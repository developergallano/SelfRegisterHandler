message("----------------------SelfRegisterHandler Begin-------------------------")
cmake_minimum_required(VERSION 3.0.0)
project(SelfRegisterHandler)

add_executable(handler 
            main.cpp
            src/HandlerResult.cpp
            src/HeaderHandler.cpp
            src/NonCompliantHandler.cpp
            src/ProtocolHandler.cpp
            )

include_directories(handler include)

message("----------------------SelfRegisterHandler End---------------------------")