#include "electron_instance.h"
#include "electron_message.h"
#include "electron_osutils.h"
#include <petunia/ipc_medium_default.h>
#include <list>
#include <iostream>
#include <assert.h>
#include <chrono>

ElectronInstance::ElectronInstance(std::string instance_id)
  :m_instance_id(instance_id)
{
  Connect();
}

void ElectronInstance::Connect()
{  
  m_petunia = std::make_shared<Petunia::Petunia>(new Petunia::IPCMediumDefault(m_instance_id, Petunia::ConnectionRole::Client));
}

ElectronInstance::~ElectronInstance()
{
  
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

