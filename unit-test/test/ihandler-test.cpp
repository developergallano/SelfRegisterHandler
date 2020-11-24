#include "catch.hpp"

#include "IHandler.h"
#include "Registry.h"
#include "ProtocolHandler.h"

/*
   class IHandler defines the base class for handlers. string is the type
   used to classify handlers.
*/

TEST_CASE("Handler tests")
{
    auto& prot = Registry<const char*, HandlerPtr>::instance().get(ProtocolHandler::PROTOCOLHANDLER);

    //! handler to protocol exists, getting a handler should succeed
    REQUIRE(prot.get());
    if( prot.get())
    {
        prot->handle("test");
    }
}

/*
TEST_CASE("Non-existing Handler tests")
{
    std::string noneHandler{"none"};
    auto& prot = Registry<std::string,IHandler>::instance().get(noneHandler);

    //! handler to none does not exist, getting a handler should succeed
    REQUIRE(prot.get() == nullptr);
}
*/