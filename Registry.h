#ifndef __REGISTRY_H__
#define __REGISTRY_H__

#include <map>
#include <memory>
#include <type_traits>
#include <functional>

/*
 * this class template is use to enforce template argument
 * to implement 'getRegistryType' method
 */
/*
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
*/

/*
 * RegistryEntry defines an interface for a registry entry
 */
/*
template<typename TKey, typename TValue>
class RegistryEntry
{
public:
   RegistryEntry<TKey,TValue>(){}
   RegistryEntry<TKey,TValue>(TKey key, TValue value) 
   : _key(key)
   , _value(std::move(value))
   {
   }
   virtual~RegistryEntry(){}
   virtual const TKey& getKey() const{ return _key; }
   virtual TValue& getValue() { return _value; }
private:
   TKey _key;
   TValue _value;
};
*/
/*
 * this is the registry for objects  of InterfaceT
 * The type InterfaceT must have a 'getRegistryName()' method enforced by
 * enable_if
 */
template<typename TKey, typename TValue, 
         typename std::enable_if<std::is_default_constructible<TValue>::value, bool>::type = 0,
         typename std::enable_if<std::is_move_constructible<TValue>::value, bool>::type = 0,
         typename std::enable_if<std::is_move_assignable<TValue>::value, bool>::type = 0 >
class Registry
{
public:
   using RegistryMap = std::map<TKey, TValue>;

   static Registry& instance()
   {
      static Registry inst;
      return inst;
   }

   /*
    * register an entry
    */
   static bool registerEntry(TKey key, TValue value)
   {
      return instance().add(key, std::forward<TValue>(value));
   }

   /*
    * this adds the handler to the registry
    */
   bool add(TKey key, TValue value)
   {
      // the key should not exists for add to succeed
      if( _map.find(key) != _map.end() )
      {
         return false;
      }

      _map[key] = std::move(value);
      return true;
   }

   /*
    * access to the object given a name
    */
   auto& get(TKey key)
   {
      if( _map.find(key) != _map.end() )
      {
         return _map[key];
      }

      static TValue value;
      return value;
   }

   bool exists(TKey key)
   {
      return _map.find(key) != _map.end();
   }


private:
   /*
    * this is the map that holds the registry
    */
   RegistryMap _map;
};

/*
 * Registry specialization to self register a type
 */
template<typename TKey, typename TValue>
class SelfRegisterRegistry : public Registry<TKey,TValue>
{
private:
   /*
    * the variable that holds the instance registry info
    */
   template<TKey>
   class InstReg
   {
   public:
      static bool _registered;
   };
};
   
/*
 * 
 */
template<typename TKey, typename TValue>
class Factory
{
public:
   template<typename... TArgs>
   static TValue create(TKey key, TArgs... args)
   {
      using Func = std::function<TValue(TArgs...)>;
      if(! SelfRegisterRegistry<TKey, Func>::instance().exists(key) )
      {
         TValue value;
         return value;
      }
      auto creator = SelfRegisterRegistry<TKey,Func>::instance().get(key);
      auto ret = creator(std::forward<TArgs...>(args... ));
      return std::move(ret);
   }

   template<typename... TArgs>
   static bool registerCreator(TKey key, std::function<TValue(TArgs...)> creator)
   {
      using Func = std::function<TValue(TArgs...)>;
      return SelfRegisterRegistry<TKey,Func>::instance().registerEntry(key, creator);
   }
};

class LifeCycleManager
{

};


#endif //__REGISTRY_H__