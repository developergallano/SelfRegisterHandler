#pragma once
#include "Handler.h"

class LogoutHandler : public Handler
{
public:
    virtual std::string getName() override;
    LogoutHandler(int handler);
};