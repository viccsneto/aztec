#include "PropertyManager.h"
#include <list>
namespace Aztec {
  PropertyManager *PropertyManager::s_instance = NULL;

  PropertyManager *PropertyManager::getInstance()
  {
    if (!s_instance)
      s_instance = new PropertyManager();
    return s_instance;
  }
  PropertyManager::PropertyManager()
  {
    m_database.open(":memory:");
    //m_database.open("z:/tmp.db");
    m_database.execDML("PRAGMA journal_mode=OFF");
    m_database.execDML("PRAGMA locking_mode=exclusive");
    m_database.execDML("PRAGMA read_uncommited=true");

    // Creates the main tables of the database
    m_database.execDML("CREATE TABLE tbl_property "
                       "("
                       " gamestate_address INTEGER,"
                       " gameobject_address INTEGER,"
                       " property TEXT, "
                       " value TEXT, "
                       " PRIMARY KEY (gamestate_address, gameobject_address, property) "
                       ")");

    // Creates the database indexes
    m_database.execDML("CREATE INDEX tbl_property_property_idx ON tbl_property(property)");

    m_database.execDML("CREATE INDEX tbl_property_value_idx ON tbl_property(value)");

    m_database.execDML("CREATE INDEX tbl_property_gamestate_address_idx ON tbl_property(gamestate_address)");

    m_database.execDML("CREATE INDEX tbl_property_gameobject_address_idx ON tbl_property(gameobject_address)");

    m_stmt_insert_property = m_database.compileStatement("INSERT INTO tbl_property "
                                                         "("
                                                         " gamestate_address, "
                                                         " gameobject_address, "
                                                         " property, "
                                                         " value "
                                                         ")"
                                                         "VALUES"
                                                         "("
                                                         " @gamestate_address,"
                                                         " @gameobject_address,"
                                                         " @property,"
                                                         " @value "
                                                         ")");


    m_stmt_update_property = m_database.compileStatement("UPDATE tbl_property SET "
                                                         " value = @value "
                                                         "WHERE "
                                                         " gameobject_address = @gameobject_address AND"
                                                         " property = @property ");


    m_stmt_delete_gameobject = m_database.compileStatement("DELETE FROM tbl_property "
                                                           "WHERE "
                                                           " gameobject_address = @gameobject_address");

    m_stmt_delete_property = m_database.compileStatement("DELETE FROM tbl_property "
                                                         "WHERE "
                                                         " gameobject_address = @gameobject_address AND"
                                                         " property = @property");

    m_stmt_select_gameobject = m_database.compileStatement("SELECT gameobject_address FROM tbl_property "
                                                           "WHERE "
                                                           " gamestate_address = @gamestate_address AND"
                                                           " property = @property AND "
                                                           " value = @value ");

    m_stmt_select_property = m_database.compileStatement("SELECT gameobject_address FROM tbl_property "
                                                         "WHERE "
                                                         " gamestate_address = @gamestate_address AND"
                                                         " property = @property "
                                                         "ORDER BY "
                                                         " value ");
  }


  PropertyManager::~PropertyManager()
  {
  }

  bool PropertyManager::update_property(GameObject *object, const char *property_name, const char *value)
  {
    m_stmt_update_property.reset();

    m_stmt_update_property.bindInt64("@gameobject_address", (size_t)object);
    m_stmt_update_property.bind("@property", property_name);
    m_stmt_update_property.bind("@value", value);
    if (m_stmt_update_property.execDML() == 0)
      return false;
    return true;
  }

  void PropertyManager::set_property(GameObject *object, const char *property_name, const char *value)
  {
    if (!update_property(object, property_name, value)) {
      m_stmt_insert_property.reset();
      m_stmt_insert_property.bindInt64("@gamestate_address", (size_t)object->getGameState());
      m_stmt_insert_property.bindInt64("@gameobject_address", (size_t)object);

      m_stmt_insert_property.bind("@property", property_name);
      m_stmt_insert_property.bind("@value", value);
      m_stmt_insert_property.execDML();
    }
  }

  void PropertyManager::delete_property(GameObject *object, const char *property_name)
  {
    m_stmt_delete_property.reset();
    m_stmt_delete_property.bindInt64("@gameobject_address", (size_t)object);
    m_stmt_delete_property.bind("@property", property_name);
    m_stmt_delete_property.execDML();
  }

  void PropertyManager::delete_gameobject(GameObject *object)
  {
    m_stmt_delete_gameobject.reset();
    m_stmt_delete_gameobject.bindInt64("@gameobject_address", (size_t)object);
    m_stmt_delete_gameobject.execDML();
  }

  GameObjectList *PropertyManager::query_to_list(CppSQLite3Query q)
  {
    GameObjectList *list = new GameObjectList();
    while (!q.eof()) {
      list->add((GameObject *)q.getInt64Field("gameobject_address"));
      q.nextRow();
    }

    return list;
  }

  GameObjectList *PropertyManager::query(GameStateController *state, const char *property_name, const char *property_value)
  {

    m_stmt_select_gameobject.reset();
    m_stmt_select_gameobject.bindInt64("@gamestate_address", (size_t)state);
    m_stmt_select_gameobject.bind("@property", property_name);
    m_stmt_select_gameobject.bind("@value", property_value);
    return query_to_list(m_stmt_select_gameobject.execQuery());
  }

  GameObjectList *PropertyManager::query(GameStateController *state, const char *property_name)
  {

    m_stmt_select_property.reset();
    m_stmt_select_property.bindInt64("@gamestate_address", (size_t)state);
    m_stmt_select_property.bind("@property", property_name);

    return query_to_list(m_stmt_select_property.execQuery());
  }

} // namespace Aztec