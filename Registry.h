#pragma once
#include <map>
#include <memory>
#include <type_traits>

/*
 * this class template is use to enforce template argument
 * to implement 'getRegistryType' method
 */
template <typename T>
class Has_getRegistryType
{
private:
    typedef char Yes[1];
    typedef char No[2];
    template <typename C> static Yes& test( decltype(&C::getRegistryType) ) ;
    template <typename C> static No& test(...);
public:
    enum { value = sizeof(test<T>(0)) == sizeof(Yes) };
};

/*
 * IRegistryEntry defines an interface for a regitry entry
 */
template<typename T>
class IRegistryEntry
{
public:
   virtual~IRegistryEntry(){}
   virtual const T& getRegistryType() const = 0;
};

/*
 * this is the registry for objects  of InterfaceT
 * The type InterfaceT must have a 'getRegistryName()' method enforced by
 * enable_if
 */
template<typename RegT, typename InterfaceT, 
         typename std::enable_if<Has_getRegistryType<InterfaceT>::value, bool>::type = 0 >
class Registry
{
public:
   using RegistryHandlerPtr = std::unique_ptr<InterfaceT>;
   using RegistryMap = std::map<RegT, RegistryHandlerPtr>;

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
      // the key should not exists for add to succeed
      if( reg.get() == nullptr || _map.find(reg->getRegistryType()) != _map.end() )
      {
         return false;
      }

      _map[reg->getRegistryType()] = std::move(reg);
      return true;
   }

   /*
    * access to the object given a name
    */
   RegistryHandlerPtr& get(RegT registry)
   {
      if( _map.find(registry) != _map.end() )
      {
         return _map[registry];
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