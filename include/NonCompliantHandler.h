#pragma once
#include "IHandler.h"

class INonHandler
{
public:
   virtual const std::string& getRegistryType() const = 0;
};

class NonCompliantHandler : public INonHandler
{
public:
   NonCompliantHandler();
   virtual ~NonCompliantHandler();

   virtual const std::string& getRegistryType() const;
   virtual HandlerResult handle(std::string msg);
};

