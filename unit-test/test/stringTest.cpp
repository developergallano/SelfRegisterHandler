//#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Registry.h"

enum Test
{
    Fail,
    Success
};

using InstRegistry = Registry<Test,std::string>;

TEST_CASE("instantiate-test-fail")
{
    InstRegistry::registerEntry(Test::Fail, "Fail");
    auto instance = InstRegistry::instance().get(Test::Fail);
    REQUIRE(instance == "Fail");
}

TEST_CASE("instantiate-test-succees")
{
    InstRegistry::registerEntry(Test::Success, "Success");
    auto instance = InstRegistry::instance().get(Test::Success);
    REQUIRE(instance == "Success");
}
