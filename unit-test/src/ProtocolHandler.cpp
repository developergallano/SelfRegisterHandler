#include "ProtocolHandler.h"
#include "Registry.h"

#include <iostream>

using RegistryeHandlerRegistry = Registry<std::string,IHandler>;
template<>template<> 
bool RegistryeHandlerRegistry::SelfRegister<ProtocolHandler>::_registered 
   = RegistryeHandlerRegistry::SelfRegister<ProtocolHandler>::selfRegister();

ProtocolHandler::ProtocolHandler()
{}

ProtocolHandler::~ProtocolHandler()
{}

const std::string& ProtocolHandler::getRegistryType() const
{
   static std::string name {"Protocol"};
   return name;
}

HandlerResult ProtocolHandler::handle(std::string msg)
{
   HandlerResult result(HandlerResult::Fail, std::string());
   std::cout << "ProtocolHandler handled." << std::endl;
   return result;   
}
