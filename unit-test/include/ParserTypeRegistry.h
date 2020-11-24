#pragma once
#include <memory>
#include <string>

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

using ParserPtr = std::unique_ptr<Parser>;