#include "electron_message.h"
ElectronMessage::ElectronMessage(std::string msg_type, std::string msg_text, size_t msg_size, void *msg_data)
  :m_msg_type(msg_type)
  ,m_msg_text(msg_text)
  ,m_msg_size(msg_size)
  ,m_msg_data(msg_data)
{

}

ElectronMessage::ElectronMessage(std::string msg_type, std::string msg_text, std::string msg_data)
  :m_msg_type(msg_type)
  ,m_msg_text(msg_text)
  ,m_msg_size(msg_data.length() + 1)
  ,m_msg_data(strdup(msg_data.c_str()))
{

}

ElectronMessage::ElectronMessage(const char *msg_type, const char *msg_text, const char *msg_data)
  :m_msg_type(msg_type)
  , m_msg_size(strlen(msg_data)+1) 
  , m_msg_text(msg_text)
  , m_msg_data(strdup(msg_data))
{
  
}

std::string ElectronMessage::GetType()
{
  return m_msg_type;
}

size_t ElectronMessage::GetSize()
{
  return m_msg_size;
}

size_t ElectronMessage::GetTextSize()
{
  return m_msg_text.size();
}

void * ElectronMessage::GetData()
{
  return m_msg_data;
}

const char *ElectronMessage::GetText()
{
  return m_msg_text.c_str();
}

ElectronMessage::~ElectronMessage()
{
  free(m_msg_data);
}

