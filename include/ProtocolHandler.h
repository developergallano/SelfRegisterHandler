#pragma once
#include "IHandler.h"

class ProtocolHandler : public IHandler
{
public:
   ProtocolHandler();
   virtual ~ProtocolHandler();

   virtual const std::string& getRegistryName() const override;
   virtual HandlerResult handle(std::string msg) override;
};

