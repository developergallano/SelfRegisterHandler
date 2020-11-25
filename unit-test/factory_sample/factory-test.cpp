#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Registry.h"
//#include "Message.h"
#include "Handler.h"

/*
std::function<MessagePtr(std::string)> loginCreator = &createLoginMessage;
std::function<MessagePtr(std::string)> logoutCreator = &createLogoutMessage;
using Func = std::function<MessagePtr(std::string)>;
using MessageFactory = Factory<const char*,MessagePtr>;
using SelfRegister = SelfRegisterRegistry<const char*, Func>;
//template<>template<> bool SelfRegister::InstReg<const char*, Func>::_registered 
static bool test1 = MessageFactory::registerCreator<std::string>(LOGINMESSAGE, loginCreator);
static bool test2 = MessageFactory::registerCreator<std::string>(LOGINMESSAGE, logoutCreator);
*/

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