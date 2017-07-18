cmake_minimum_required(VERSION 3.7)
project(betterlapse)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS filesystem system)
find_package(OpenCV REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OpenCV_INCLUDE_DIRS})
set(SOURCE_FILES main.cpp)

add_executable(betterlapse ${SOURCE_FILES})
target_link_libraries(betterlapse ${Boost_LIBRARIES})
target_link_libraries(betterlapse ${OpenCV_LIBRARIES})