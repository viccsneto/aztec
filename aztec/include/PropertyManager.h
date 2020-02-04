#pragma once
#include "SQLITE3/CppSQLite3.h"
#include "GameObject.h"
#include "GameStateController.h"
#include "GameObjectList.h"
#include <list>
namespace Aztec {
  class PropertyManager {
  public:
    static PropertyManager *getInstance();
    PropertyManager();
    ~PropertyManager();
    void set_property(GameObject *object, const char *property_name, const char *value);
    bool update_property(GameObject *object, const char *property_name, const char *value);
    void delete_property(GameObject *object, const char *property_name);
    void delete_gameobject(GameObject *object);

    GameObjectList *query(GameStateController *state, const char *property, const char *value);
    GameObjectList *query(GameStateController *state, const char *property);

  private:
    GameObjectList *query_to_list(CppSQLite3Query q);
    // GameObject Database
    CppSQLite3DB m_database;

    // tbl_properties
    CppSQLite3Statement     m_stmt_insert_property;
    CppSQLite3Statement     m_stmt_update_property;
    CppSQLite3Statement     m_stmt_delete_property;
    CppSQLite3Statement     m_stmt_delete_gameobject;
    CppSQLite3Statement     m_stmt_select_gameobject;
    CppSQLite3Statement     m_stmt_select_property;
    static PropertyManager *s_instance;
  };
} // namespace Aztec