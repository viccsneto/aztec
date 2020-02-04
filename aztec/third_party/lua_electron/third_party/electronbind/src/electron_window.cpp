#include "electron_window.h"

ElectronWindow::ElectronWindow(const char *command_line_args)
  :m_command_line_args("")
{
  if (command_line_args) {
    m_command_line_args = std::string(command_line_args);
  }

  ElectronBind::Instance()->RegisterBrowserWindow(this);
}

ElectronWindow::ElectronWindow()
{
  ElectronBind::Instance()->RegisterBrowserWindow(this);
}

std::shared_ptr<ElectronInstance> ElectronWindow::GetInstance() const
{
  return m_instance;
}

void ElectronWindow::SendMessage(std::shared_ptr<Petunia::Message> message)
{
  m_instance->SendMessage(message);
}

const char * ElectronWindow::GetCommandLineArgs()
{
  return m_command_line_args.c_str();
}

void ElectronWindow::AddListener(std::string name, std::function<void(std::shared_ptr<Petunia::Message> message)> listener_function)
{
  m_instance->AddListener(name, listener_function);
}


bool ElectronWindow::RemoveListener(std::string listener_name)
{
  return m_instance->RemoveListeners(listener_name);
}

ElectronWindow::~ElectronWindow()
{
  ElectronBind::Instance()->UnregisterBrowserWindow(this);
  SendMessage(std::make_shared<Petunia::Message>("destroy", std::make_shared<std::string>(m_instance->GetID())));

}

void ElectronWindow::SetInstance(std::shared_ptr<ElectronInstance> instance)
{
  m_instance = instance;
}
