
#ifndef TICTACTOE_UTIL_H
#define TICTACTOE_UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>

#include "Board.h"
#include "Ui.h"


extern int turn;

void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
int coordinatesX(int x);
int coordinatesY(int y);


#endif //TICTACTOE_UTIL_H
