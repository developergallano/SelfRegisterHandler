#include "HeaderHandler.h"
#include "Registry.h"

#include <iostream>

using RegistryeHandlerRegistry = Registry<std::string, IHandler>;
template<>template<> 
bool RegistryeHandlerRegistry::SelfRegister<HeaderHandler>::_registered 
   = RegistryeHandlerRegistry::SelfRegister<HeaderHandler>::selfRegister();

HeaderHandler::HeaderHandler()
{}

HeaderHandler::~HeaderHandler()
{}

const std::string& HeaderHandler::getRegistryType() const
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
