#include "NonCompliantHandler.h"
#include "Registry.h"

#include <iostream>

using RegistryeHandlerRegistry = Registry<std::string,INonHandler>;
template<>template<> 
bool RegistryeHandlerRegistry::SelfRegister<NonCompliantHandler>::_registered 
   = RegistryeHandlerRegistry::SelfRegister<NonCompliantHandler>::selfRegister();

NonCompliantHandler::NonCompliantHandler()
{}

NonCompliantHandler::~NonCompliantHandler()
{}

const std::string& NonCompliantHandler::getRegistryType() const
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
