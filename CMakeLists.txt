cmake_minimum_required(VERSION 2.8)
project(CWK2 C)

include_directories(unity/include)


add_executable(CWK2
        checker.c
        checker.h
        grid.c
        grid.h
        logic.c
        logic.h
        main.c)

add_executable(unity_tests unit_tests.c checker.c unity/src/unity.c)

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2)
set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")
