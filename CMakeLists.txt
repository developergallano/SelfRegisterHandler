message("----------------------SelfRegisterHandler Begin-------------------------")
cmake_minimum_required(VERSION 3.0.0)

project(SelfRegisterHandler)

add_executable(Registry.ut 
            unit-test/test/stringTest.cpp
            #unit-test/test/parser-test.cpp
            #unit-test/test/ihandler-test.cpp

            #unit-test/src/HandlerResult.cpp
            #unit-test/src/HeaderHandler.cpp
            #unit-test/src/NonCompliantHandler.cpp
            #unit-test/src/ProtocolHandler.cpp
            #unit-test/src/StreamParser.cpp
            #unit-test/src/StringParser.cpp
            
            )

include_directories(handler . )# unit-test/include)

message("----------------------SelfRegisterHandler End---------------------------")