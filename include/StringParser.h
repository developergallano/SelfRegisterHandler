#pragma once
#include "ParserTypeRegistry.h"

class StringParser : public Parser
{
public:
    StringParser();
    virtual const Type& getRegistryType() const override;
    virtual void parse(std::string& str) override;
};