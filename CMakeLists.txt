cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

project(algos)

set(PROJECT_VERSION "0.1.0")

message(STATUS "CMAKE_ROOT: " ${CMAKE_ROOT} )
message(STATUS "CMAKE_SYSTEM_NAME          = ${CMAKE_SYSTEM_NAME}"         )
message(STATUS "CMAKE_SYSTEM: " ${CMAKE_SYSTEM} )
message(STATUS "CMAKE_SYSTEM_VERSION: " ${CMAKE_SYSTEM_VERSION} )
message(STATUS "CMAKE_SYSTEM_PROCESSOR: " ${CMAKE_SYSTEM_PROCESSOR} )
message(STATUS "CMAKE_CXX_COMPILER_ID      = ${CMAKE_CXX_COMPILER_ID}"     )
message(STATUS "CMAKE_CXX_COMPILER_VERSION = ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "CMAKE_COMPILER_IS_GNUCXX   = ${CMAKE_COMPILER_IS_GNUCXX}"  )
message(STATUS "CMAKE_INCLUDE_PATH: " ${CMAKE_INCLUDE_PATH} )
message(STATUS "CMAKE_LIBRARY_PATH: " ${CMAKE_LIBRARY_PATH} )

set(CMAKE_CXX_STANDARD 14)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
  message(STATUS "Setting definition -O0")
  add_definitions(-O0)
  set(CMAKE_CXX_FLAGS "-g -Wall -pedantic")
else()
  message(STATUS "Setting definition -O3")
  add_definitions(-O3)
  set(CMAKE_CXX_FLAGS "-Wall -pedantic")
endif()

message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )
message(STATUS "BUILD_SHARED_LIBS: " ${BUILD_SHARED_LIBS} )

add_executable("stack"
    src/stack.cpp
)
