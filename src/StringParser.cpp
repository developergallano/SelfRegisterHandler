#include "StringParser.h"
#include "Registry.h"

using RegistryeHandlerRegistry = Registry<Type,Parser>;
template<>template<> 
bool RegistryeHandlerRegistry::SelfRegister<StringParser>::_registered 
   = RegistryeHandlerRegistry::SelfRegister<StringParser>::selfRegister();

StringParser::StringParser()
{}

const Type& StringParser::getRegistryType() const
{
    static Type type = Type::String;
    return type;
}

void StringParser::parse(std::string&)
{

}

