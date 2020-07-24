#include "HeaderHandler.h"
#include "Registry.h"

#include <iostream>

using RegistrableHandlerRegistry = Registry<IHandler>;
template<>template<> 
bool RegistrableHandlerRegistry::SelfRegister<HeaderHandler>::_registered 
   = Registry<IHandler>::SelfRegister<HeaderHandler>::selfRegister();

HeaderHandler::HeaderHandler()
{}

HeaderHandler::~HeaderHandler()
{}

const std::string& HeaderHandler::getName() const
{
   static std::string name {"Header"};
   return name;
}

HandlerResult HeaderHandler::handle(std::string msg)
{
   HandlerResult result(HandlerResult::Fail, std::string());
   std::cout << "HeaderHandler handled." << std::endl;
   return result;   
}
