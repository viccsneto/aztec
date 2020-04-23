#include "electron_bind.h"
#include "electron_window.h"
#include "electron_message.h"
#include "electron_instance.h"
#include "electron_osutils.h"

#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <sstream>
#include <iostream>
#include <iomanip>

ElectronBind *ElectronBind::s_instance = nullptr;

std::vector<std::string> *ElectronBind::SplitPath(const char *path)
{
  std::vector<std::string> *arr = new std::vector<std::string>();
  size_t length = strlen(path);
  size_t previous = 0;

  for (size_t i = 0; i <= length; ++i) {
    if (path[i] == 0 || path[i] == ';') {
      size_t entry_length = i - previous;
      char *entry = (char *)malloc((entry_length + 1) * sizeof(char));
      entry[entry_length] = 0;
      for (size_t j = 0; j < entry_length; ++j) {
        int pos = previous + j;
        if (path[pos] != '\\') {
          entry[j] = path[pos];
        }
        else {
          entry[j] = '/';
        }
      }
      std::string path_entry(entry);

      if (path_entry[entry_length - 1] != '/') {
        path_entry += "/";
      }

      arr->push_back(path_entry);
      free(entry);
      i++;
      previous = i;
    }
  }

  return arr;
}

ElectronBind *ElectronBind::Instance()
{
  if (!s_instance) {
    s_instance = new ElectronBind();
  }
  return s_instance;
}

void ElectronBind::Release()
{
  delete s_instance;
}

ElectronBind::ElectronBind()
{
  m_electron_name = "electron.exe";
  if (!FindElectron()) {
    throw(new ElectronBind::Exception("Could not find Electron"));
  }

  m_browser_count = 0;
  m_pid           = ElectronOSUtils::GetPID();
}

ElectronBind::~ElectronBind()
{
}

bool ElectronBind::FindElectron()
{
  std::string path = "./USE;" + std::string(getenv("PATH"));
  std::vector<std::string> *path_entries = SplitPath(path.c_str());

  for (std::vector<std::string>::iterator it = path_entries->begin(); it != path_entries->end(); ++it) {
    std::string looking_path = ElectronOSUtils::RelativeToFullPath(*it + m_electron_name);
    if (ElectronOSUtils::FileExists(looking_path)) {        
      m_electron_path = ElectronOSUtils::RelativeToFullPath(*it);
      return true;
    }
  }

  return false;
}

std::shared_ptr<ElectronInstance> ElectronBind::CreateBrowserInstance(const char *command_line_args)
{
  std::ostringstream timestamp;
  unsigned long long time = ElectronOSUtils::GetTimeMilliseconds();

  std::string instance_id = "__ELECTRONBIND__TIMESTAMP_" + std::to_string(time) + std::string("__PID_") + std::to_string(m_pid) + "__BROWSERID_" +
                            std::to_string(m_browser_count + 1) + std::string("__");

  std::shared_ptr<ElectronInstance> instance = std::make_shared<ElectronInstance>(instance_id);

  std::string additional_args  = command_line_args ? " " + std::string(command_line_args) : "";
  additional_args              = (additional_args.length() > 1) ? additional_args : "";
  std::string electron_command = "\"" + m_electron_path + m_electron_name + "\" "+
    "\"" + m_electron_path + ".\" " +
    "---inspect-brk "
    "--channel \"" + instance->GetChannel() + "\" "
    + additional_args;
  
  unsigned long electron_pid = ElectronOSUtils::CreateSystemProcess(electron_command.c_str());
  if (electron_pid != 0) {
    m_browser_count++;
  }
  else {
    throw(new ElectronBind::Exception(std::string("Electron launch command failed: " + electron_command).c_str()));
  }

  instance->SetPID(electron_pid);
  return instance;
}

void ElectronBind::RegisterBrowserWindow(ElectronWindow *window)
{
  window->SetInstance(CreateBrowserInstance(window->GetCommandLineArgs()));
  m_browser_windows.insert(std::make_pair(window->GetInstance()->GetID(), window));
}

void ElectronBind::UnregisterBrowserWindow(ElectronWindow *window)
{
  std::unordered_map<std::string, ElectronWindow *>::iterator it = m_browser_windows.find(window->GetInstance()->GetID());
  if (it != m_browser_windows.end()) {
    m_browser_windows.erase(it->first);
  }
}
