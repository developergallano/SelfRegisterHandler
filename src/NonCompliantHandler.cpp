#include "NonCompliantHandler.h"
#include "Registry.h"

#include <iostream>

using RegistrableHandlerRegistry = Registry<INonHandler>;
template<>template<> 
bool RegistrableHandlerRegistry::SelfRegister<NonCompliantHandler>::_registered 
   = Registry<INonHandler>::SelfRegister<NonCompliantHandler>::selfRegister();

NonCompliantHandler::NonCompliantHandler()
{}

NonCompliantHandler::~NonCompliantHandler()
{}

const std::string& NonCompliantHandler::getName() const
{
   static std::string noName{"NonCompliantHandler"};
   return noName;
}

HandlerResult NonCompliantHandler::handle(std::string msg)
{
   HandlerResult result(HandlerResult::Fail, std::string());
   std::cout << "ProtocolHandler handled." << std::endl;
   return result;   

}
