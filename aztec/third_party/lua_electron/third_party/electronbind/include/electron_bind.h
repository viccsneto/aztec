#pragma once
#include <string>
#include <unordered_map>
#include <stdexcept>
#include <memory>
#include <vector>

class ElectronWindow;
class ElectronInstance;
class ElectronMessage;

class ElectronBind
{
public:
  class Exception : public std::runtime_error
  {
  public:
    Exception(const char *message)
    : std::runtime_error(message)
    {

    }
  };
  
  static ElectronBind *Instance();
  static void Release();
  void UnregisterBrowserWindow(ElectronWindow* window);
private:
  ElectronBind();
  ~ElectronBind();
  bool FindElectron();
  std::shared_ptr<ElectronInstance> CreateBrowserInstance(const char *command_line_args = NULL);
  void RegisterBrowserWindow(ElectronWindow *window);
  std::vector<std::string> *SplitPath(const char *path);

private:
  static ElectronBind *s_instance;
  std::string m_electron_path;
  std::string m_electron_name;
  unsigned int m_browser_count;
  unsigned long m_pid;
  std::unordered_map<std::string, ElectronWindow *> m_browser_windows;
private:
  friend class ElectronWindow;
  
};