cmake_minimum_required(VERSION 3.29)
project(Sylogisme C)

set(CMAKE_C_STANDARD 99)

add_executable(Sylogisme main.c
        writing.h
        writing.c
        displayConsole.h
        displayConsole.c)
