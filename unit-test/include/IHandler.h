#pragma once
#include <memory>
#include "HandlerResult.h"
#include "Registry.h"

class Handler 
{
public:
   virtual~Handler(){}
   virtual HandlerResult handle(std::string) {return HandlerResult{HandlerResult::Fail, std::string("Default")}; };
};

using HandlerPtr = std::unique_ptr<Handler>;