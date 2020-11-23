#pragma once
#include "ParserTypeRegistry.h"

class StreamParser : public Parser
{
public:
    StreamParser();
    virtual std::string parse(std::string& str) override;
};