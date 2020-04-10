#pragma once
#include <string>
class ElectronOSUtils
{
  public:
    static unsigned long long GetTimeMilliseconds();
    static unsigned long CreateSystemProcess(const char *command);
    static unsigned long GetPID();
    static bool KillProcess(unsigned long pid);
    static bool FileExists(std::string& looking_path);
    static bool DirectoryExists(std::string& looking_path);
    static std::string        GetTemporaryFolder();
    static std::string RelativeToFullPath(std::string path);
};
