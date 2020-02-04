#pragma once
#include "electron_bind.h"
#include "electron_instance.h"
#include <functional>
#include <unordered_map>
#include <string>

class ElectronWindow
{
public:
  ElectronWindow();
  ElectronWindow(const char *command_line_args);
  std::shared_ptr<ElectronInstance> GetInstance() const;
  void SendMessage(std::shared_ptr<Petunia::Message> message);
  const char *GetCommandLineArgs();
  void AddListener(std::string name, std::function<void(std::shared_ptr<Petunia::Message> message)> listener_function);
  bool RemoveListener(std::string listener_name);
  virtual ~ElectronWindow();
private:
  void SetInstance(std::shared_ptr<ElectronInstance> instance);
  std::shared_ptr<ElectronInstance> m_instance;
private:
  friend class ElectronBind;
  std::string m_command_line_args;
};
