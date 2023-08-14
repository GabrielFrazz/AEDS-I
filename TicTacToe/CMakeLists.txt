cmake_minimum_required(VERSION 3.26)
project(TicTacToe C)

set(CMAKE_C_STANDARD 11)

add_executable(TicTacToe main.c
        Board.c
        Board.h
        Util.c
        Util.h
        Game.c
        Game.h
        Computer.c
        Computer.h
        Ui.c
        Ui.h
)

target_link_libraries(TicTacToe -lOpenGL32 -lfreeGLUT)