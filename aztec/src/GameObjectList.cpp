#include "GameObjectList.h"
namespace Aztec {
  GameObjectList::GameObjectList()
  {
    _className.assign("GameObjectList");
    m_index = 0;
  }

  GameObjectList::~GameObjectList()
  {
  }

  void GameObjectList::clear()
  {
    m_gameobject_map.clear();
    m_index = 0;
  }

  GameObject *GameObjectList::add(GameObject *object)
  {
    if (!has(object))
      m_gameobject_map.insert(pair<GameObject *, GameObject *>(object, object));

    return object;
  }

  GameObject *GameObjectList::get(unsigned int index)
  {
    return at(index);
  }

  void GameObjectList::remove(GameObject *object)
  {

    multimap<GameObject *, GameObject *>::iterator i = m_gameobject_map.find(object);
    if (i == m_gameobject_map.end())
      return;

    m_gameobject_map.erase(i);
  }

  unsigned int GameObjectList::getSize()
  {
    return m_gameobject_map.size();
  }

  bool GameObjectList::has(GameObject *object)
  {
    multimap<GameObject *, GameObject *>::iterator i = m_gameobject_map.find(object);
    return i != m_gameobject_map.end();
  }

  GameObject *GameObjectList::at(unsigned int index)
  {
    if (index > getSize())
      return NULL;
    multimap<GameObject *, GameObject *>::iterator i = m_gameobject_map.begin();
    for (unsigned int pos = 0; pos < index; pos++)
      ++i;
    return i->second;
  }
  multimap<GameObject *, GameObject *> GameObjectList::getList()
  {
    return m_gameobject_map;
  }

  bool GameObjectList::hasNext()
  {
    return (m_index < getSize());
  }

  bool GameObjectList::setPosition(unsigned int pos)
  {
    if (pos < getSize()) {
      m_index = pos;
      return true;
    }
    return false;
  }

  GameObject *GameObjectList::next()
  {
    GameObject *object = NULL;
    if (hasNext()) {
      object = at(m_index++);
    }
    return object;
  }

} // namespace Aztec