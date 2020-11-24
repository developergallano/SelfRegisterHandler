#include "StreamParser.h"
#include "Registry.h"

using SelfRegister = SelfRegisterRegistry<Type, ParserPtr>;
template<>template<> bool SelfRegister::InstReg<Type::Stream>::_registered = SelfRegister::registerEntry(Type::Stream, std::make_unique<StreamParser>());

StreamParser::StreamParser()
{
    _type = Type::Stream;
}

std::string StreamParser::parse(std::string& str)
{
    return "StreamParser:" + str;
}

