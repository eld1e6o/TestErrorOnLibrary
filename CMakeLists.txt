cmake_minimum_required(VERSION 2.8.12)

project(test_pub_priv)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -std=c++11")

#set(OpenCV_INCLUDE_DIRS "./include/")
find_package(OpenCV QUIET ) # HINTS /opt/ocv)

message(" ** Test with public private libraries ** ")

include_directories(${OpenCV_INCLUDE_DIRS})

aux_source_directory(./src SRC_LIST)
include_directories(./hpp SRC_LIST)
FILE(GLOB_RECURSE LibFiles "./hpp/*.h")
add_custom_target(headers SOURCES ${LibFiles})

add_library(myFramework ${SRC_LIST} )
add_executable(test_pub_priv ./examples/Main.cpp)
target_link_libraries(test_pub_priv ${OpenCV_LIBS} myFramework)

