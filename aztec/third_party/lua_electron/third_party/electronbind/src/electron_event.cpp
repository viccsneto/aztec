#include "electron_event.h"

ElectronEvent::ElectronEvent(const char *name, std::function<void(const char *text, size_t size, void *data)> listener_function)
{
  m_name = std::string(name);
  m_listener_function = listener_function;
}

std::function<void(const char *text, size_t size, void *data)> ElectronEvent::GetFunction()
{
  return m_listener_function;
}

std::string ElectronEvent::GetName()
{
  return m_name;
}

