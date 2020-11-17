#pragma once
#include "IHandler.h"

class HeaderHandler : public IHandler
{
public:
   HeaderHandler();
   virtual ~HeaderHandler();

   virtual const std::string& getRegistryType() const override;
   virtual HandlerResult handle(std::string msg) override;
};

