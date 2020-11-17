#pragma once

template<typename T>
class IRegistryEntry
{
public:
   virtual~IRegistryEntry(){}
   virtual const T& getRegistryType() const = 0;
};
