
#ifndef TICTACTOE_GAME_H
#define TICTACTOE_GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#include "Util.h"

extern int Xwins;
extern int Owins;
extern int computerPlayer;
extern int winner;

void checkWin(void);
void resetGame(void);

#endif //TICTACTOE_GAME_H
