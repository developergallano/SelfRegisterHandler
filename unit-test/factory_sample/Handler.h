#pragma once
#include <string>

#include "Registry.h"

class Handler
{
public:
    Handler(int handler) : _handler(handler){}
    ~Handler(){}
    virtual std::string getName() { return "Handler"; }
private:
    int _handler;
};

class LoginHandler : public Handler
{
    virtual std::string getName() override { return "LoginHandler"; }
public:
    LoginHandler(int handler) : Handler(handler){}
};

class LogoutHandler : public Handler
{
    virtual std::string getName() override { return "LogoutHandler"; }
public:
    LogoutHandler(int handler) : Handler(handler){}
};

//Handlers
const char LOGINHandler[] = "LOGINHandler";
const char LOGOUTHandler[] = "LOGOUTHandler";

using HandlerPtr = std::unique_ptr<Handler>;

HandlerPtr createLoginHandler(int handler)
{
    return std::make_unique<LoginHandler>(handler);
}

HandlerPtr createLogoutHandler(int handler)
{
    return std::make_unique<LogoutHandler>(handler);
}

static std::unique_ptr<Handler> str();

std::function<HandlerPtr(int)> loginCreator = createLoginHandler;
std::function<HandlerPtr(int)> logoutCreator = createLogoutHandler;
using HandlerFunc = std::function<HandlerPtr(std::string)>;
using HandlerFactory = Factory<const char*,HandlerPtr>;
using SelfRegister = SelfRegisterRegistry<const char*, HandlerFunc>;
//template<>template<> bool SelfRegister::InstReg<const char*, Func>::_registered 
static bool test1 = HandlerFactory::registerCreator<int>(LOGINHandler, loginCreator);
static bool test2 = HandlerFactory::registerCreator<int>(LOGOUTHandler, logoutCreator);
