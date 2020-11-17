#pragma once
#include "HandlerResult.h"
#include "IRegistryEntry.h"

class IHandler : public IRegistryEntry<std::string>
{
public:
   virtual~IHandler(){}
   virtual HandlerResult handle(std::string msg) = 0;
};
