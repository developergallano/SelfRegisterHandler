#pragma once
#include "HandlerResult.h"

class IHandler
{
public:
   virtual~IHandler(){}
   virtual const std::string& getName() const = 0;
   virtual HandlerResult handle(std::string msg) = 0;
};
