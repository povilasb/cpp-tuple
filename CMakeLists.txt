cmake_minimum_required(VERSION 2.6)

project(tuple CXX)

option(TUPLE_ENABLE_TESTS "Enables or disables tests. Disabled by default."
	OFF)


message(STATUS "Build type: ${CMAKE_BUILD_TYPE}.")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fstack-protector")
set(CMAKE_CXX_FLAGS "-std=c++98 -Wall -Wextra -Werror -pedantic")


set(TUPLE_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${TUPLE_INCLUDE_DIRS})


if (TUPLE_ENABLE_TESTS)
	add_subdirectory(test)
endif()
