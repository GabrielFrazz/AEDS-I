#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500

#define PI 3.14
#define MARGIN_CUT 10

#include "Game.h"
#include "Ui.h"


typedef struct {
    int grid[9];
}TBoard;

extern int drawWinner;

static int victoryLines[8][4] = {
        { (WIDTH/3)/2 , MARGIN_CUT , (WIDTH / 3) / 2 ,       HEIGHT - MARGIN_CUT},
        { (WIDTH/2) ,   MARGIN_CUT , (WIDTH / 2) ,           HEIGHT - MARGIN_CUT},
        { WIDTH - (WIDTH/3)/2 ,      MARGIN_CUT ,  WIDTH - (WIDTH / 3) / 2 , HEIGHT - MARGIN_CUT},

        { MARGIN_CUT ,  HEIGHT - (HEIGHT / 3) / 2, WIDTH - MARGIN_CUT,       HEIGHT - (HEIGHT / 3) / 2},
        { MARGIN_CUT , (HEIGHT / 2),     WIDTH - MARGIN_CUT, HEIGHT / 2},
        { MARGIN_CUT , (HEIGHT / 3) / 2, WIDTH - MARGIN_CUT, (HEIGHT / 3) / 2},

        { MARGIN_CUT ,  HEIGHT - MARGIN_CUT,       WIDTH - MARGIN_CUT,       MARGIN_CUT},
        { MARGIN_CUT ,  MARGIN_CUT,      WIDTH - MARGIN_CUT, HEIGHT - MARGIN_CUT},
};

static int coordinates[9][2] = {
        {0,(HEIGHT/3)*2},	{WIDTH/3,(HEIGHT/3)*2},	{(WIDTH/3)*2,(HEIGHT/3)*2},
        {0,HEIGHT/3},		{WIDTH/3,HEIGHT/3},		{(WIDTH/3)*2,HEIGHT/3},
        {0,0},				{WIDTH/3,0},			{(WIDTH/3)*2,0}
};

extern TBoard current;

void initializeBoard(TBoard *board);
int isBoarFull(TBoard board);
int isBoarEmpty(TBoard board);
void drawO(GLfloat x, GLfloat y);
void drawX(int x, int y);
void display(void);

#endif // BOARD_H_INCLUDED