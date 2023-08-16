
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

void buildTree(TCell *cell, int player);

int evaluate(const TBoard *board, int player);

int minimax(TCell *node, int depth, int maximizingPlayer);

void makeBestMove(TCell *actual);



#endif //TICTACTOE_COMPUTER_H
