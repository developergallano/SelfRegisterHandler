#include "LoginHandler.h"


const char LOGINHandler[] = "LOGINHandler";

HandlerPtr createLoginHandler(int handler)
{
    return std::make_unique<LoginHandler>(handler);
}
std::function<HandlerPtr(int)> loginHandlerCreator = createLoginHandler;
template<>template<> bool SelfRegister::InstReg<LOGINHandler>::_registered = HandlerFactory::registerCreator<int>(LOGINHandler, loginHandlerCreator);

LoginHandler::LoginHandler(int handler)
: Handler(handler)
{}

std::string LoginHandler::getName()
{ 
    return "LoginHandler"; 
}
