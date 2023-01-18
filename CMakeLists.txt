cmake_minimum_required(VERSION 3.5)

project(RatoUI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SDL2_LIB_DIR
    "E:/Programs/SDL/x86/lib"
)

set(SDL2_INCLUDE_DIR
    "E:/Programs/SDL/x86/include"
)

set(SDL2_LIBRARY
    "E:/Programs/SDL/x86/bin"
)

file(GLOB_RECURSE
    SRC "test.cpp"
    gui/*.cpp
    gui/*.h
)

include_directories(
    ${SDL2_INCLUDE_DIR}
)

link_directories(
    ${SDL2_LIB_DIR}
)

add_executable(RatoUI ${SRC})

target_link_libraries(RatoUI
    -lmingw32 ${SDL2_LIB_DIR}/libSDL2main.a
    ${SDL2_LIB_DIR}/libSDL2.dll.a
    -mwindows
)

install(TARGETS RatoUI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
