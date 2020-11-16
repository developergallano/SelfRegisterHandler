#pragma once
#include "IHandler.h"

class INonHandler
{
public:
   virtual const std::string& getRegistryName() const = 0;
};

class NonCompliantHandler : public INonHandler
{
public:
   NonCompliantHandler();
   virtual ~NonCompliantHandler();

   virtual const std::string& getRegistryName() const;
   virtual HandlerResult handle(std::string msg);
};

