cmake_minimum_required(VERSION 3.26)
project(TAD_Stack C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TAD_Stack
        interface.c
        interface.h
        main.c
        Pilha.c
        Pilha.h
        queue.c
        queue.h
        util.c
        util.h)
