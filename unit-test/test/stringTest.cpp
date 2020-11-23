#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Registry.h"

enum Test
{
    Fail,
    Success
};

using InstRegistry = InstanceRegistry<Test,std::string>;

TEST_CASE("instantiate-test-fail")
{
    InstRegistry::selfRegister(Test::Fail, "Fail");
    auto instance = InstanceRegistry<Test,std::string>::instance().get(Test::Fail);
    REQUIRE(instance == "Fail");
}

TEST_CASE("instantiate-test-succees")
{
    InstRegistry::selfRegister(Test::Success, "Success");
    auto instance = InstanceRegistry<Test,std::string>::instance().get(Test::Success);
    REQUIRE(instance == "Success");
}
