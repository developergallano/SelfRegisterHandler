#pragma once
#include "ParserTypeRegistry.h"

class StringParser : public Parser
{
public:
    StringParser();
    virtual const Type& getRegistryType() const override;
    virtual std::string parse(std::string& str) override;
};