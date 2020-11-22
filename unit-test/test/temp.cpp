#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Registry.h"

enum Test
{
    Fail,
    Success
};

TEST_CASE("instantiate-test")
{
    //InstanceRegistry<Test,std::string>::instance().get(Test::Fail);
    InstanceRegistry<Test,std::string>::instance().
}