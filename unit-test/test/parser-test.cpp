#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ParserTypeRegistry.h"
#include "Registry.h"

#include "StringParser.h"

#include <type_traits>

/*
   class Parser defines the base class for parsers. Type is an
   enumeration classifying parser types.
*/
TEST_CASE("Parser tests")
{
   std::string strToParse{"str"};
   Type type = Type::Stream;
   auto& parser = Registry<Type,ParserPtr>::instance().get(type);

   // a parser of type Type::Stream exists, it should succeed getting the parser
   REQUIRE(parser.get());
   std::string retVal1 = parser.get()->parse(strToParse);
   REQUIRE(retVal1 == "StreamParser:str");

   // a parser of type Type::String exists, it should succeed getting the parser
   Type stringType = Type::String;
   auto& stringParser = Registry<Type,ParserPtr>::instance().get(stringType);
   REQUIRE(stringParser.get());
   std::string retVal2 = stringParser.get()->parse(strToParse);
   REQUIRE(retVal2 == "StringParser:str");

   // a parser of type Type::Period does not exist, it should fail getting the parser
   Type periodType = Type::Period;
   auto& periodParser = Registry<Type,ParserPtr>::instance().get(periodType);
   REQUIRE(periodParser.get() ==  nullptr);
}

/*
 * this proves that polymorphic behavior is not supported for value type
 * see concepts is c++ 20
 */
TEST_CASE("Parser value test")
{
   std::string strToParse{"str"};
   // a parser of type Type::String exists, it should succeed getting the parser
   Type stringType = Type::String;
   auto& stringParser = Registry<Type,Parser>::instance().get(stringType);

   StringParser* parser = dynamic_cast<StringParser*>(&stringParser);
   REQUIRE(parser == nullptr);
}
/*
template<typename T>
concept EqualityComaparable = requires(T a, T b)
{
   { a == b } -> std::same_as<bool>;
   { a != b } -> std::same_as<bool>;
}
*/