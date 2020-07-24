#pragma once
#include <map>
#include <memory>

template<typename InterfaceT>
class Registry
{
public:
using RegistrableHandlerPtr = std::unique_ptr<InterfaceT>;
using RegistryMap = std::map<std::string, RegistrableHandlerPtr>;

   static Registry& instance();

   bool add(RegistrableHandlerPtr reg);
   RegistrableHandlerPtr& get(std::string name);
private:
   RegistryMap _map;
public:
   template< typename T>
   class SelfRegister
   {
      static bool selfRegister()
      {
         return Registry::instance().add(std::make_unique<T>());
      }
   private:
      static bool _registered;
   };
};

template<typename InterfaceT>
Registry<InterfaceT>& Registry<InterfaceT>::instance()
{
   static Registry inst;
   return inst;
}

template<typename InterfaceT>
bool Registry<InterfaceT>::add(RegistrableHandlerPtr reg)
{
   if( reg )
   {
      _map[reg->getName()] = std::move(reg);
      return true;
   }
   return false;
}

template<typename InterfaceT>
typename Registry<InterfaceT>::RegistrableHandlerPtr& Registry<InterfaceT>::get(std::string name)
{
   if( _map.find(name) != _map.end() )
   {
      return _map[name];
   }

   static RegistrableHandlerPtr ptr;
   return ptr;
}