#include "PropertyList.h"
namespace Aztec {
  PropertyList::PropertyList()
  {
    _className.assign("PropertyList");
  }

  PropertyList::~PropertyList()
  {
    clear();
  }

  void PropertyList::clear()
  {
    m_property_map.clear();
  }

  const char *PropertyList::add(const char *property, const char *value)
  {
    string str_property(property);
    string str_value(value);
    if (get(property) == NULL)
      m_property_map.insert(pair<string, string>(str_property, str_value));
    else
      return set(property, value);
    return get(property);
  }

  const char *PropertyList::get(const char *property)
  {
    string                             str_property(property);
    multimap<string, string>::iterator i = m_property_map.find(str_property);
    if (i == m_property_map.end())
      return NULL;
    else
      return i->second.c_str();
  }

  const char *PropertyList::set(const char *property, const char *value)
  {
    string                             str_property(property);
    multimap<string, string>::iterator i = m_property_map.find(str_property);
    if (i != m_property_map.end())
      m_property_map.erase(i);

    return add(property, value);
  }

  void PropertyList::remove(const char *property)
  {
    string                             str_property(property);
    multimap<string, string>::iterator i = m_property_map.find(str_property);

    if (i == m_property_map.end())
      return;

    m_property_map.erase(i);
  }

  unsigned int PropertyList::getSize()
  {
    return m_property_map.size();
  }

  bool PropertyList ::has(const char *property)
  {
    return (get(property) != NULL);
  }

  const char *PropertyList::getName(unsigned int index)
  {
    if (index > getSize())
      return NULL;
    multimap<string, string>::iterator i = m_property_map.begin();
    for (unsigned int pos = 0; pos < index; pos++)
      ++i;
    return i->first.c_str();
  }

  const char *PropertyList::at(unsigned int index)
  {
    if (index > getSize())
      return NULL;
    multimap<string, string>::iterator i = m_property_map.begin();
    for (unsigned int pos = 0; pos < index; pos++)
      ++i;
    return i->second.c_str();
  }
  multimap<string, string> PropertyList::getList()
  {
    return m_property_map;
  }

  int PropertyList::getIndex(const char *property)
  {
    multimap<string, string>::iterator i = m_property_map.begin();
    for (int pos = 0; pos < m_property_map.size(); pos++) {
      if (i->first.compare(property) == 0)
        return pos;
      ++i;
    }
    return -1;
  }

  int PropertyList::getValueIndex(const char *value)
  {
    return getValueIndex(value, 0);
  }

  int PropertyList::getValueIndex(const char *value, unsigned int n)
  {
    int                                count = 0;
    multimap<string, string>::iterator i     = m_property_map.begin();
    for (int pos = 0; pos < m_property_map.size(); pos++) {
      if (i->second.compare(value) == 0) {
        if (count == n)
          return pos;
        count++;
      }
      ++i;
    }
    return -1;
  }

  bool PropertyList::hasValue(const char *value)
  {
    return getValueIndex(value) != -1;
  }
} // namespace Aztec