#pragma once
#include <string>
//#include "Registry.h"

enum Type
{   
    None,
    Stream,
    Char,
    Period,
    String
};

class Parser 
{
public:
    virtual const Type& getRegistryType() const{ return _type;};
    virtual std::string parse(std::string& str) {return std::string(); };
protected:
    Type _type{Type::None};
};