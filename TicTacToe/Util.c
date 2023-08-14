#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

#include "Board.h"
#include "Ui.h"
#include "Util.h"

int turn = 1;

TBoard current;


void keyboard(unsigned char key, int x, int y){

    switch (key) {
        case 27:
            exit(0);
            break;
        case 'R':
        case 'r':
            currentState = GAMEPLAY;
            resetGame();
            break;
        case 'P':
        case 'p':
            currentState = SCORE;
            display();
            break;
        case 'M':
        case 'm':
            currentState = MENU;
            Xwins = 0;
            Owins = 0;
            resetGame();
            display();
            break;
        case 'g':
        case 'G':
            currentState = GAME_MODE_SELECTION;
            resetGame();
            display();
            break;
        case 'b':
        case 'B':
            currentState = GAMEPLAY;
            display();
            break;
        case 's':
        case 'S':
            currentState = SUB;
            display();
            break;
        case '1':
            if(currentState == MENU){
                currentState = GAME_MODE_SELECTION;
                display();
            }else if(currentState == GAME_MODE_SELECTION){
                currentState = GAMEPLAY;
                computerPlayer = 0;
                display();
            }
            break;
        case '2':
            if(currentState == MENU){
                currentState = CONTROLS;
                display();
            }else if(currentState == GAME_MODE_SELECTION){
                currentState = GAMEPLAY;
                computerPlayer = 1;
                display();
            }
            break;
        case '3':
            if(currentState == MENU){
                currentState = ABOUT;
                display();
            }else if(currentState == GAME_MODE_SELECTION){
                currentState = MENU;
                display();
            }
            break;
        case '4':
            exit(0);
            break;

    }
}

int coordinatesX(int x){

    if(x < WIDTH/3)
        return 0;
    if(x > WIDTH/3 && x < (WIDTH/3)*2)
        return 1;
    return 2;

}

int coordinatesY(int y){

    if(y < HEIGHT/3)
        return 0;
    if(y > HEIGHT/3 && y < (HEIGHT/3)*2)
        return 1;
    return 2;

}


void mouse(int button, int state, int x, int y){
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && currentState == GAMEPLAY || currentState == SUB) {
        if(currentState == GAMEPLAY){
            currentState = SUB;
        }else if(currentState == SUB){
            currentState = GAMEPLAY;
        }
        display();
    }
    if(button == GLUT_LEFT_BUTTON && currentState == GAMEPLAY){
        if (state==GLUT_DOWN && winner == 0)
        {

            int line = coordinatesY(y);
            int column = coordinatesX(x);

            int calc = column+(line*3);
            if(current.grid[calc] == 0){
                if(turn==1){
                    current.grid[calc] = turn;
                    turn = -1;
                }else if(turn==-1){
                    current.grid[calc] = turn;
                    turn = 1;
                }
            }else{
                printf("Field taken!\n");
            }
        }
    }
}

