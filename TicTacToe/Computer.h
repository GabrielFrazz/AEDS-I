
#ifndef TICTACTOE_COMPUTER_H
#define TICTACTOE_COMPUTER_H

# include <stdio.h>
# include <stdlib.h>

#include "Board.h"

typedef struct cell{
    TBoard board;
    struct cell *pai;
    struct cell *branch[9];
    int score;
} TCell;


TCell *createsNode(TBoard board);

int minimax(TCell *node, int isMaximizing);

void makeBestMove(TCell *actual);



#endif //TICTACTOE_COMPUTER_H
