project(parse-study)

cmake_minimum_required(VERSION 2.8)
add_definitions(-Wall -std=c++14)

find_package(Qt5Core REQUIRED)
set(CMAKE_AUTOMOC ON)

FILE(GLOB SOURCES src/main.cpp)

add_executable(run ${SOURCES})
qt5_use_modules(run Core)
target_link_libraries(run ${QT_LIBRARIES})
