#pragma once

class IRegistryEntry
{
public:
   virtual~IRegistryEntry(){}
   virtual const std::string& getRegistryName() const = 0;
};
