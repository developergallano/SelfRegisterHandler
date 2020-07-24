#pragma once
#include <map>
#include <memory>
#include <functional>

#include "HandlerResult.h"

class IRegistrableHandler
{
public:
   virtual~IRegistrableHandler(){}
   virtual const std::string& getName() const = 0;
   virtual HandlerResult handle(std::string msg) = 0;
};

using RegistrableHandlerPtr = std::unique_ptr<IRegistrableHandler>;
using RegistryMap = std::map<std::string, RegistrableHandlerPtr>;

class Registry
{
public:
   static Registry& instance();

   bool add(RegistrableHandlerPtr reg);
   RegistrableHandlerPtr& get(std::string name);
private:
   RegistryMap _map;
};

template< typename T>
class SelfRegister
{
   static bool selfRegister()
   {
      return Registry::instance().add(std::make_unique<T>());
   }
   static bool _registered;
};

