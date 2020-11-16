#pragma once
#include <map>
#include <memory>
#include <type_traits>

/*
 * this class template is use to enforce template argument
 * to implement 'getRegistryName' method
 */
template <typename T>
class Has_getRegistryName
{
private:
    typedef char Yes[1];
    typedef char No[2];
    template <typename C> static Yes& test( decltype(&C::getRegistryName) ) ;
    template <typename C> static No& test(...);
public:
    enum { value = sizeof(test<T>(0)) == sizeof(Yes) };
};

/*
 * this is the registry for objects  of InterfaceT
 * The type InterfaceT must have a 'getRegistryName()' method enforced by
 * enable_if
 */
template<typename InterfaceT, 
         typename std::enable_if<Has_getRegistryName<InterfaceT>::value, bool>::type = 0 >
class Registry
{
public:
   using RegistryHandlerPtr = std::unique_ptr<InterfaceT>;
   using RegistryMap = std::map<std::string, RegistryHandlerPtr>;

   static Registry& instance()
   {
      static Registry inst;
      return inst;
   }

   /*
    * this adds the handler to the registry
    */
   bool add(RegistryHandlerPtr reg)
   {
      if( reg )
      {
         _map[reg->getRegistryName()] = std::move(reg);
         return true;
      }
      return false;

   }

   /*
    * access to the object given a name
    */
   RegistryHandlerPtr& get(std::string registryName)
   {
      if( _map.find(registryName) != _map.end() )
      {
         return _map[registryName];
      }

      static RegistryHandlerPtr ptr;
      return ptr;
   }

private:
   /*
    * this is the map that holds the registry
    */
   RegistryMap _map;


public:
   /*
    * this is the template allow a class to declare self registering method
    */
   template< typename T,
             typename std::enable_if<std::is_base_of<InterfaceT, T>::value, bool>::type = 0,
             typename std::enable_if<std::is_default_constructible<T>::value, bool>::type = 0 >

   class SelfRegister
   {
      /*
       * method to self register an object
       */
      static bool selfRegister()
      {
         return Registry::instance().add(std::make_unique<T>());
      }
   private:

      /*
       * indicator that the type is registered
       */
      static bool _registered;
   };
};