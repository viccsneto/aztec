#pragma once
#include <petunia/petunia.h>



class ElectronInstance
{
public:
  ElectronInstance(std::string instance_id);
  void Connect();

  ~ElectronInstance();
  std::string GetID();
  std::string GetChannel();
  void SendMessage(std::shared_ptr<Petunia::Message> message);
  void AddListener(std::string name, std::function<void(std::shared_ptr<Petunia::Message> message)> listener_function);
  bool RemoveListeners(std::string listener_name) const;

private:
  std::shared_ptr<Petunia::Petunia> m_petunia;
  std::string m_instance_id;  
public:
  void SetPID(unsigned long electron_pid);
private:
  unsigned long m_pid;
};


