#pragma once
#include <map>
#include <memory>
#include <type_traits>

template <typename T>
class Has_getName
{
private:
    typedef char Yes[1];
    typedef char No[2];
    template <typename C> static Yes& test( decltype(&C::getName) ) ;
    template <typename C> static No& test(...);
public:
    enum { value = sizeof(test<T>(0)) == sizeof(Yes) };
};

template<typename InterfaceT, 
typename std::enable_if<Has_getName<InterfaceT>::value, bool>::type = 0
>
class Registry
{
public:
using RegistrableHandlerPtr = std::unique_ptr<InterfaceT>;
using RegistryMap = std::map<std::string, RegistrableHandlerPtr>;

   static Registry& instance()
   {
      static Registry inst;
      return inst;
   }

   bool add(RegistrableHandlerPtr reg)
   {
      if( reg )
      {
         _map[reg->getName()] = std::move(reg);
         return true;
      }
      return false;

   }
   RegistrableHandlerPtr& get(std::string name)
   {
      if( _map.find(name) != _map.end() )
      {
         return _map[name];
      }

      static RegistrableHandlerPtr ptr;
      return ptr;

   }
private:
   RegistryMap _map;
public:
   
   template< typename T,
   typename std::enable_if<std::is_base_of<InterfaceT, T>::value, bool>::type = 0,
   typename std::enable_if<std::is_default_constructible<T>::value, bool>::type = 0
    >
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

/*
template<typename InterfaceT,
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
*/