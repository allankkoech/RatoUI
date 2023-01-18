cmake_minimum_required(VERSION 3.5)

project(RatoUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(RatoUI test.cpp)

install(TARGETS RatoUI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
