#pragma once
#include "IHandler.h"

class HeaderHandler : public Handler
{
public:
   HeaderHandler();
   virtual ~HeaderHandler();

   virtual HandlerResult handle(std::string msg) override;
};

