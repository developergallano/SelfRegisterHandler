#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ParserTypeRegistry.h"
#include "Registry.h"

/*
   class Parser defines the base class for parsers. Type is an
   enumeration classifying parser types.
*/
TEST_CASE("Parser tests")
{
   std::string strToParse{"str"};
   Type type = Type::Stream;
   auto& parser = Registry<Type,Parser>::instance().get(type);

   // a parser of type Type::Stream exists, it should succeed getting the parser
   REQUIRE( parser.get() );
   if( parser.get() )
   {
      auto retVal = parser->parse(strToParse);
      REQUIRE(retVal == "StreamParser:str");
   }

   // a parser of type Type::String exists, it should succeed getting the parser
   Type stringType = Type::String;
   auto& stringParser = Registry<Type,Parser>::instance().get(stringType);
   REQUIRE( stringParser.get() );
   if( stringParser.get() )
   {
      auto retVal = stringParser->parse(strToParse);
      REQUIRE(retVal == "StringParser:str");
   }

   // a parser of type Type::Period does not exist, it should fail getting the parser
   Type periodType = Type::Period;
   auto& periodParser = Registry<Type,Parser>::instance().get(periodType);
   REQUIRE( periodParser.get() == nullptr);   
}