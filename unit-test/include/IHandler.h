#pragma once
#include "HandlerResult.h"
#include "Registry.h"

class IHandler : public IRegistryEntry<std::string>
{
public:
   virtual~IHandler(){}
   virtual HandlerResult handle(std::string msg) = 0;
};
