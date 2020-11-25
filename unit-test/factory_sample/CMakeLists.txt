message("----------------------Factory Sample Begin-------------------------")
cmake_minimum_required(VERSION 3.0.0)

add_executable(factory-sample.ut 
                factory-test
              )

include_directories(factory-sample.ut unit-test/include .)

target_compile_options(factory-sample.ut PRIVATE -std=c++2a -fconcepts)
message("----------------------Factory Sample End---------------------------")