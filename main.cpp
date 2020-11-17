#include "IHandler.h"
#include "Registry.h"
#include "ParserTypeRegistry.h"

#include <memory>
#include <iostream>



int main(int argc, char* argv[])
{  
   if( argc == 1 )
   {
      std::cout << "No parameter" << std::endl;
      return 0;
   }

   std::string strToParse{"str"};
   Type type = Type::Stream;
   auto& parser = Registry<Type,Parser>::instance().get(type);
   if( parser.get() )
   {
      parser->parse(strToParse);
   }

   Type stringType = Type::String;
   auto& stringParser = Registry<Type,Parser>::instance().get(stringType);
   if( stringParser.get() )
   {
      stringParser->parse(strToParse);
   }


   std::string handler{argv[1]};
   auto& prot = Registry<std::string,IHandler>::instance().get(handler);
   if( prot.get())
   {
      prot->handle("test");
   }
   else
   {
      std::cout << "NOT handled" << std::endl;
   }
   

}