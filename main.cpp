#include "IHandler.h"
#include "Registry.h"

#include <memory>
#include <iostream>


int main(int argc, char* argv[])
{  
   if( argc == 1 )
   {
      std::cout << "No parameter" << std::endl;
      return 0;
   }

   std::string handler{argv[1]};
   auto& prot = Registry<IHandler>::instance().get(handler);
   if( prot.get())
   {
      prot->handle("test");
   }
   else
   {
      std::cout << "NOT handled" << std::endl;
   }
   

}