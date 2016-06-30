project(parse-study)

cmake_minimum_required(VERSION 3.2)
add_definitions(-Wall -std=c++14)

find_package(Qt5 COMPONENTS Quick Core)
qt5_add_resources(PROJ_RES ${CMAKE_CURRENT_SOURCE_DIR}/res/parse.qrc)
set(CMAKE_AUTOMOC ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
FILE(GLOB SOURCES src/*.cpp)
FILE(GLOB HEADERS inc/*.h)

add_executable(run ${HEADERS} ${SOURCES} ${PROJ_RES})
qt5_use_modules(run Core Quick)
target_link_libraries(run ${QT_LIBRARIES})
