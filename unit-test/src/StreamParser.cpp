#include "StreamParser.h"
#include "Registry.h"

using RegistryeHandlerRegistry = Registry<Type,Parser>;
template<>template<> 
bool RegistryeHandlerRegistry::SelfRegister<StreamParser>::_registered 
   = RegistryeHandlerRegistry::SelfRegister<StreamParser>::selfRegister();

StreamParser::StreamParser()
{}

const Type& StreamParser::getRegistryType() const
{
    static Type type = Type::Stream;
    return type;
}

std::string StreamParser::parse(std::string& str)
{
    return "StreamParser:" + str;
}

