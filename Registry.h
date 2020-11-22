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
 * IRegistryEntry defines an interface for a registry entry
 */
template<typename TKey, typename TValue>
class IRegistryEntry
{
public:
   IRegistryEntry(TKey key, TValue value) 
   : _key(key)
   , _value(value)
   {}
   virtual~IRegistryEntry(){}
   virtual const TKey& getKey() const{ return _key; }
   virtual TValue& getValue() { return _value; }
private:
   TKey _key;
   TValue _value;
};

/*
 * this is the registry for objects  of InterfaceT
 * The type InterfaceT must have a 'getRegistryName()' method enforced by
 * enable_if
 */
template<typename TKey, typename TValue> 
         //typename std::enable_if<Has_getRegistryType<InterfaceT>::value, bool>::type = 0 >
class Registry
{
public:
   using RegistryEntry = IRegistryEntry<TKey, TValue>;
   using RegistryMap = std::map<TKey, RegistryEntry>;

   static Registry& instance()
   {
      static Registry inst;
      return inst;
   }

   /*
    * this adds the handler to the registry
    */
   bool add(RegistryEntry reg)
   {
      // the key should not exists for add to succeed
      if( _map.find(reg->getKey()) != _map.end() )
      {
         return false;
      }

      _map[reg->getKey()] = std::move(reg);
      return true;
   }

   /*
    * access to the object given a name
    */
   TValue& get(TKey key)
   {
      if( _map.find(key) != _map.end() )
      {
         return _map[key].getValue();
      }

      static TValue value;
      return value;
   }

private:
   /*
    * this is the map that holds the registry
    */
   RegistryMap _map;


};

template<typename TKey, typename TValue,
   typename std::enable_if<std::is_default_constructible<TValue>::value, bool>::type = 0 >
class InstanceRegistry : public Registry<TKey,TValue>
{
public:
   /*
   * method to self register an object
   */
   static bool selfRegister()
   {
      return Registry<TKey,TValue>::instance().add(std::make_unique<TValue>());
   }
private:

   /*
      * indicator that the type is registered
      */
   static bool _registered;
};
   

class CreatorRegistry
{

};