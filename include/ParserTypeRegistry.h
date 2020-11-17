#pragma once
#include <string>
#include "IRegistryEntry.h"

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
    virtual void parse(std::string& str) = 0;
};