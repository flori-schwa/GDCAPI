cmake_minimum_required(VERSION 3.10)
project(GDCAPI)

set(CMAKE_CXX_STANDARD 20)

#include_directories(
#        Dependencies/HAPIH/include
#)

set(SOURCES

        include/__gd_ptr.h
        include/__gdcapimain.h

        include/GameInfo.h
        include/GdHandle.h
        include/LevelInfo.h
        include/MemoryReadException.h
        include/PlayerInfo.h

        __gd_ptr.cpp
        GameInfo.cpp
        GdHandle.cpp
        LevelInfo.cpp
        PlayerInfo.cpp
        MemoryReadException.cpp)

add_library(GDCAPI ${SOURCES})
add_library(HAPIH include/HAPIH.h HAPIH.cpp)
set_target_properties(HAPIH PROPERTIES LINKER_LANGUAGE CXX)

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
endif()

target_link_libraries(GDCAPI HAPIH)