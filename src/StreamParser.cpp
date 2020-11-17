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

void StreamParser::parse(std::string&)
{

}

