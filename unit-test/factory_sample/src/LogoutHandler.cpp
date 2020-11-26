#include "LogoutHandler.h"


const char LOGOUTHandler[] = "LOGOUTHandler";

HandlerPtr createLogoutHandler(int handler)
{
    return std::make_unique<LogoutHandler>(handler);
}
std::function<HandlerPtr(int)> logoutHandlerCreator = createLogoutHandler;
template<>template<> bool SelfRegister::InstReg<LOGOUTHandler>::_registered 
= HandlerFactory::registerCreator<int>(LOGOUTHandler, logoutHandlerCreator);

LogoutHandler::LogoutHandler(int handler)
: Handler(handler)
{}

std::string LogoutHandler::getName()
{ 
    return "LogoutHandler"; 
}
