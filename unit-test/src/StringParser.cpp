#include "StringParser.h"
#include "Registry.h"


using SelfRegister = SelfRegisterRegistry<Type, Parser>;
template<>template<> bool SelfRegister::InstReg<Type::String>::_registered = SelfRegister::registerEntry(Type::String, StringParser());

StringParser::StringParser()
{
    _type = Type::String;
}

std::string StringParser::parse(std::string& str)
{
    return "StringParser:" + str;
}

