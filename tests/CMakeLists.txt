cmake_minimum_required(VERSION 2.8)

project(tests)

message(STATUS "CMAKE_ROOT: " ${CMAKE_ROOT})
message(STATUS "CMAKE_SYSTEM_NAME          = ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMAKE_SYSTEM: " ${CMAKE_SYSTEM})
message(STATUS "CMAKE_SYSTEM_VERSION: " ${CMAKE_SYSTEM_VERSION})
message(STATUS "CMAKE_SYSTEM_PROCESSOR: " ${CMAKE_SYSTEM_PROCESSOR})
message(STATUS "CMAKE_CXX_COMPILER_ID      = ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CMAKE_COMPILER_IS_GNUCXX   = ${CMAKE_COMPILER_IS_GNUCXX}")

message(STATUS "CMAKE_INCLUDE_PATH: " ${CMAKE_INCLUDE_PATH})
message(STATUS "CMAKE_LIBRARY_PATH: " ${CMAKE_LIBRARY_PATH})

set(CMAKE_CXX_STANDARD 14)

find_package(GTest REQUIRED)

message(STATUS "GTEST_INCLUDE_DIRS:" ${GTEST_INCLUDE_DIRS})
message(STATUS "GTEST_LIBRARIES:" ${GTEST_LIBRARIES})

# stack
add_executable(test_stack test_stack.cpp)
target_link_libraries(test_stack ${GTEST_LIBRARIES})

# bag
add_executable(test_bag test_bag.cpp)
target_link_libraries(test_bag ${GTEST_LIBRARIES})

