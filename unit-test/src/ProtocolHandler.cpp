#include "ProtocolHandler.h"
#include "Registry.h"

#include <memory>
#include <iostream>


const char ProtocolHandler::PROTOCOLHANDLER[] = "ProtocolHandler";

using SelfRegister = SelfRegisterRegistry<const char*, HandlerPtr>;
template<>template<> bool SelfRegister::InstReg<ProtocolHandler::PROTOCOLHANDLER>::_registered = SelfRegister::registerEntry(ProtocolHandler::PROTOCOLHANDLER, std::make_unique<ProtocolHandler>());//

ProtocolHandler::ProtocolHandler()
{}

ProtocolHandler::~ProtocolHandler()
{}

HandlerResult ProtocolHandler::handle(std::string msg)
{
   HandlerResult result(HandlerResult::Fail, std::string());
   std::cout << "ProtocolHandler handled." << std::endl;
   return result;   
}