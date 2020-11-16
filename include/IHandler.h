#pragma once
#include "HandlerResult.h"
#include "IRegistryEntry.h"

class IHandler : public IRegistryEntry
{
public:
   virtual~IHandler(){}
   virtual HandlerResult handle(std::string msg) = 0;
};
