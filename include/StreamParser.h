#pragma once
#include "ParserTypeRegistry.h"

class StreamParser : public Parser
{
public:
    StreamParser();
    virtual const Type& getRegistryType() const override;
    virtual void parse(std::string& str) override;
};