#pragma once
#include "ParserTypeRegistry.h"

class StringParser : public Parser
{
public:
    StringParser();
    virtual std::string parse(std::string& str) override;
};