#pragma once
#include "Registry.h"

class ProtocolHandler : public IRegistrableHandler
{
public:
   ProtocolHandler();
   virtual ~ProtocolHandler();

   virtual const std::string& getName() const override;
   virtual HandlerResult handle(std::string msg) override;

private:
   //static bool _registered;
};

