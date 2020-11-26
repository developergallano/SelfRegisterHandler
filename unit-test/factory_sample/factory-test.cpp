#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Registry.h"
#include "Message.h"
#include "Handler.h"


TEST_CASE("CreatorTest")
{
    auto message = HandlerFactory::create(LOGINHandler, 1);
    REQUIRE(message.get());
    REQUIRE(message.get()->getName() == "LoginHandler");
}

TEST_CASE("CreatorTest2")
{
    auto message = HandlerFactory::create(LOGOUTHandler, 2);
    REQUIRE(message.get());
    REQUIRE(message.get()->getName() == "LogoutHandler");
}

TEST_CASE("MessageCreatorTest")
{
    auto message = MessageFactory::create(LOGINMESSAGE, std::string("test login"));
    REQUIRE(message.get());
    REQUIRE(message.get()->processMessage("test login :(login-message)"));
}

TEST_CASE("MessageCreatorTest2")
{
    auto message = MessageFactory::create(LOGOUTMESSAGE, std::string("test logout"));
    REQUIRE(message.get());
    REQUIRE(message.get()->processMessage("test logout :(logout-message)"));
}
