#include "ProtocolHandler.h"
#include "Registry.h"
/*
RegistrableHandlerPtr createProtocolHandler()
{
   return std::make_unique<ProtocolHandler>();
}
bool ProtocolHandler::_registered = Registry::instance().add(createProtocolHandler());
*/
template<>
bool SelfRegister<ProtocolHandler>::_registered = SelfRegister<ProtocolHandler>::selfRegister();

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
   return result;   
}
