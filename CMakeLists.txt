message("----------------------SelfRegisterHandler Begin-------------------------")
cmake_minimum_required(VERSION 3.0.0)
project(SelfRegisterHandler)

add_executable(handler 
            main.cpp
            src/HandlerResult.cpp
            src/ProtocolHandler.cpp
            src/Registry.cpp
            )

include_directories(handler include)

#target_include_directories(handler PUBLIC include/HandlerResult.h)

message("----------------------SelfRegisterHandler End---------------------------")