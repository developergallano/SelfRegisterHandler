#pragma once
#include "Handler.h"

class LoginHandler : public Handler
{
public:
    virtual std::string getName() override;
    LoginHandler(int handler);
};