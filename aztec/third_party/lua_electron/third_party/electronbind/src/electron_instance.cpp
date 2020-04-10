#include "electron_instance.h"
#include "electron_message.h"
#include "electron_osutils.h"
#include <petunia/ipc_medium_nanomsg.h>
#include <list>
#include <iostream>
#include <assert.h>
#include <chrono>

ElectronInstance::ElectronInstance(std::string instance_id)
  :m_instance_id(instance_id)
  ,m_pid(0)
{
  Connect();
}

void ElectronInstance::Connect()
{  
  m_petunia = std::make_shared<Petunia::Petunia>(new Petunia::IPCMediumNanomsg(m_instance_id, Petunia::ConnectionRole::Client));
}

ElectronInstance::~ElectronInstance()
{
  ElectronOSUtils::KillProcess(m_pid);
}

std::string ElectronInstance::GetID()
{
  return m_instance_id;
}

std::string ElectronInstance::GetChannel()
{
  return m_petunia->GetChannel();
}

void ElectronInstance::SendMessage(std::shared_ptr<Petunia::Message> message)
{
  m_petunia->SendMessage(message);
}

void ElectronInstance::AddListener(std::string name, std::function<void(std::shared_ptr<Petunia::Message> message)> listener_function)
{
  m_petunia->AddListener(name, listener_function);
}

bool ElectronInstance::RemoveListeners(std::string listener_name) const
{
  return m_petunia->RemoveListeners(listener_name);
}

void ElectronInstance::SetPID(unsigned long electron_pid)
{
  m_pid = electron_pid;
}

