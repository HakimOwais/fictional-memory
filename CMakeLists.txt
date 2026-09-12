cmake_minimum_required(VERSION 3.24)

project(exchange LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)  

# list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# include(Dependencies)

add_library(fictional_memory INTERFACE)

target_include_directories(
    fictional_memory
    INTERFACE 
        "${CMAKE_CURRENT_SOURCE_DIR}/source"   
)

target_compile_features(fictional_memory INTERFACE cxx_std_20)

target_compile_options(
    fictional_memory
    INTERFACE 
    -Wall
    -Wextra
    -Wpedantic
    -fno-exceptions   
)

add_executable(
    exchange
    source/exchange_main.cpp
)

target_link_libraries(
    exchange
    PRIVATE 
        fictional_memory
)

set_target_properties(
    exchange
    PROPERTIES  
        OUTPUT_NAME "exchange"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/source"
)

add_executable(
    trader_terminal
    tools/trader_terminal.cpp
)

target_link_libraries(
    trader_terminal
    PRIVATE 
        fictional_memory
)

set_target_properties(
    trader_terminal
    PROPERTIES  
        OUTPUT_NAME "trader_terminal"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tools"
)

add_executable(
    liquidity_bot
    tools/liquidity_bot.cpp
)

target_link_libraries(
    liquidity_bot
    PRIVATE 
        fictional_memory
)

set_target_properties(
    liquidity_bot
    PROPERTIES  
        OUTPUT_NAME "liquidity_bot"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tools"
)

