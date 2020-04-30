#include <petunia/ipc_medium_nanomsg.h>
#include <assert.h>
#include <petunia/osutils.h>
#include <nanomsg/nn.hpp>
#include <nanomsg/pair.h>
#include <iostream>


namespace Petunia {
  class IPCInternalMedium : public IPCMedium
  {
  public:
    IPCInternalMedium(std::string &channel, ConnectionRole connection_role /*= ConnectionRole::Auto*/)
      :IPCMedium(channel, connection_role)
    {      
      std::string channel_prefix = "ipc:///tmp/";

      m_nano_socket = std::make_shared<nn::socket>(AF_SP, NN_PAIR);
      int max_size = -1;
      m_nano_socket->setsockopt(NN_SOL_SOCKET, NN_RCVMAXSIZE, &max_size, sizeof(max_size));
      if (connection_role == ConnectionRole::Server) {
        m_nano_socket->bind((channel_prefix + channel).c_str());
      }
      else {
        m_nano_socket->connect((channel_prefix + channel).c_str());
      }
    }
    
    ~IPCInternalMedium()
    {

    }

    bool SendMessages(std::queue<std::shared_ptr<Message>> &outbox_queue)
    {     
      if (!outbox_queue.empty()) {
        while (!outbox_queue.empty()) {
          std::shared_ptr<Message> message = outbox_queue.front();
          auto composed_message = std::make_shared<std::string>();
          size_t type_size = strlen(message.get()->GetType()) + 1;         
          composed_message->resize(type_size + message->GetDataSize());
          memcpy((void *)composed_message->data(), message->GetType(), type_size);
          memcpy((void *)(composed_message->data() + type_size), (void *)message->GetData()->data(), message->GetDataSize());
          
          m_nano_socket->send(composed_message->data(), composed_message->size(), 0);
          outbox_queue.pop();
        }
        return true;
      }      

      return false;
    }
    
    bool ReceiveMessages(std::queue<std::shared_ptr<Message>> &inbox_queue)
    {
      char *buffer = nullptr;
      int rc;
      bool received = false;
      while ((rc = m_nano_socket->recv(&buffer, NN_MSG, NN_DONTWAIT)) > 0) {        
        size_t type_size = strlen(buffer);
        std::string message_type;
        message_type.resize(type_size);
        strncpy((char *)message_type.data(), buffer, type_size);
        auto message_body = std::make_shared<std::string>();
        size_t body_offset = type_size + 1;
        size_t body_size = rc - body_offset;
        message_body->resize(body_size);
        
        memcpy((char *)message_body->data(), buffer + body_offset, body_size);
        
        nn_freemsg(buffer);
        buffer = nullptr;

        inbox_queue.push(std::make_shared<Message>(message_type, message_body));

        received = true;
      }
      return received;
    }
  private:
    std::shared_ptr<nn::socket> m_nano_socket;
  };
  
  IPCMediumNanomsg::IPCMediumNanomsg(std::string &channel, ConnectionRole connection_role /*= ConnectionRole::Auto*/)
    :IPCMedium(channel, connection_role)
  {
    m_internal_medium = std::make_shared<IPCInternalMedium>(channel, connection_role);
  }

  IPCMediumNanomsg::~IPCMediumNanomsg()
  {
    
  }

  bool IPCMediumNanomsg::SendMessages(std::queue<std::shared_ptr<Message>> &outbox_queue)
  {
    return m_internal_medium->SendMessages(outbox_queue);
  }


  bool IPCMediumNanomsg::ReceiveMessages(std::queue<std::shared_ptr<Message>> &inbox_queue)
  {
    return m_internal_medium->ReceiveMessages(inbox_queue);
  }
}