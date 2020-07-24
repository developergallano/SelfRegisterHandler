#include "Registry.h"

Registry& Registry::instance()
{
   static Registry inst;
   return inst;
}

bool Registry::add(RegistrableHandlerPtr reg)
{
   if( reg )
   {
      _map[reg->getName()] = std::move(reg);
      return true;
   }
   return false;
}

RegistrableHandlerPtr& Registry::get(std::string name)
{
   if( _map.find(name) != _map.end() )
   {
      return _map[name];
   }

   static RegistrableHandlerPtr ptr;
   return ptr;
}
