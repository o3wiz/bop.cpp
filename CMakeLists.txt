cmake_minimum_required(VERSION 3.30)

project(Bop
	VERSION 1.2.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

option(BOP_BUILD_EXAMPLE "Build example" OFF)

add_subdirectory("bop")

if(BOP_BUILD_EXAMPLE)
	add_subdirectory("example")
endif()
