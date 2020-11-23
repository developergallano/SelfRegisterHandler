#pragma once
#include "HandlerResult.h"
#include "Registry.h"

class IHandler : public RegistryEntry<std::string, IHandler>
{
public:
   virtual~IHandler(){}
   virtual HandlerResult handle(std::string msg) = 0;
};
