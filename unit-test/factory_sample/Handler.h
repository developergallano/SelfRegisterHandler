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

//Known Handlers
extern const char LOGINHandler[];
extern const char LOGOUTHandler[];

using HandlerPtr = std::unique_ptr<Handler>;
using HandlerFunc = std::function<HandlerPtr(std::string)>;
using SelfRegister = SelfRegisterRegistry<const char*, HandlerFunc>;
using HandlerFactory = Factory<const char*,HandlerPtr>;

