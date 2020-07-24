#include "ProtocolHandler.h"
#include "Registry.h"

#include <iostream>

using RegistrableHandlerRegistry = Registry<IHandler>;
template<>template<> 
bool RegistrableHandlerRegistry::SelfRegister<ProtocolHandler>::_registered 
   = Registry<IHandler>::SelfRegister<ProtocolHandler>::selfRegister();

ProtocolHandler::ProtocolHandler()
{}

ProtocolHandler::~ProtocolHandler()
{}

const std::string& ProtocolHandler::getName() const
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
