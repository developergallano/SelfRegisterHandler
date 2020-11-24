#include "StringParser.h"
#include "Registry.h"


using SelfRegisterPtr = SelfRegisterRegistry<Type, ParserPtr>;
template<>template<> bool SelfRegisterPtr::InstReg<Type::String>::_registered = SelfRegisterPtr::registerEntry(Type::String, std::make_unique<StringParser>());

StringParser::StringParser()
{
    _type = Type::String;
}

std::string StringParser::parse(std::string& str)
{
    return "StringParser:" + str;
}

