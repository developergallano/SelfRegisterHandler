#pragma once
#include "IHandler.h"

class ProtocolHandler : public Handler
{
public:
   ProtocolHandler();
   virtual ~ProtocolHandler();

   //virtual const std::string& getRegistryType() const override;
   virtual HandlerResult handle(std::string msg) override;

   static const char PROTOCOLHANDLER[];
};

