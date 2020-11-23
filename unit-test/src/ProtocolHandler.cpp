#include "ProtocolHandler.h"
#include "Registry.h"

#include <iostream>

//using SelfRegister = SelfRegisterRegistry<Type, Parser>;
//template<>template<> bool SelfRegister::InstReg<Type::Stream>::_registered = SelfRegister::registerEntry(Type::Stream, StreamParser());


constexpr auto PROTOCOLHANDLER{"ProtocolHandler"};
//using SelfRegister = SelfRegisterRegistry<std::string,IHandler>;
//template<>template<> bool SelfRegister::InstReg<PROTOCOLHANDLER>::_registered = false;//SelfRegister::InstReg<PROTOCOLHANDLER>();//
/*
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
*/