#include "electron_osutils.h"
#include <chrono>
#include <ratio>
#include <sys/stat.h>
#ifdef _WIN32
# include <windows.h>
# include <process.h>
#else
# include <unistd.h>
#endif

unsigned long long ElectronOSUtils::GetTimeMilliseconds()
{
  auto time   = std::chrono::high_resolution_clock::now();
  auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(time.time_since_epoch());
  return millis.count();
}

#ifdef _WIN32
unsigned long ElectronOSUtils::CreateSystemProcess(const char *command)
{
  STARTUPINFO         si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));
  si.cb = sizeof(STARTUPINFO);
  si.dwFlags |= STARTF_USESTDHANDLES;
  char current_directory[4096];
  GetCurrentDirectory(4096, current_directory);

  if (!CreateProcess(NULL, (LPSTR)(char *)command, NULL, NULL, TRUE, 0, NULL, (LPSTR)(char *)current_directory,
                     &si, // Pointer to STARTUPINFO structure
                     &pi)) {
    return 0;
  }
  return pi.dwProcessId;
}

unsigned long ElectronOSUtils::GetPID()
{
  return _getpid();
}

bool ElectronOSUtils::FileExists(std::string &looking_path)
{
  struct stat looking_stat;
  if (stat(looking_path.c_str(), &looking_stat) == 0) {
    return looking_stat.st_mode & _S_IFREG == _S_IFREG;
  }

  return false;
}

bool ElectronOSUtils::DirectoryExists(std::string &looking_path)
{
  struct stat looking_stat;
  if (stat(looking_path.c_str(), &looking_stat) == 0) {
    return looking_stat.st_mode & _S_IFDIR == _S_IFDIR;
  }

  return false;
}


std::string ElectronOSUtils::GetTemporaryFolder()
{
  std::string temp = std::string(getenv("tmp")) + "\\";
  return temp;
}

#else
std::string ElectronOSUtils::GetTemporaryFolder()
{
  return "/var/tmp/";
}

unsigned long ElectronOSUtils::GetPID()
{
  return getpid();
}

bool ElectronOSUtils::FileExists(std::string& looking_path)
{
  struct stat looking_stat;
  if (stat(looking_path.c_str(), &looking_stat) == 0) {
    return true;
  }
  return false;
}

unsigned long ElectronOSUtils::CreateSystemProcess(const char *command)
{
  //TODO - Implement Posix mechanism
  return 0;
}

#endif
