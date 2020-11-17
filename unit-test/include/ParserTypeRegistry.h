#pragma once
#include <string>
#include "Registry.h"

enum Type
{
    Stream,
    Char,
    Period,
    String
};

class Parser : public IRegistryEntry<Type>
{
public:
    virtual const Type& getRegistryType() const = 0;
    virtual std::string parse(std::string& str) = 0;
};