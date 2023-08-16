#include <stdio.h>
#include <stdlib.h>

#include "Computer.h"


TCell *createsNode(TBoard b){
    TCell *no = (TCell*) malloc(sizeof(TCell));
    no->pai = NULL;
    for(int i = 0; i < 9; i++){
        no->branch[i] = NULL;
    }
    no->board = b;
    no->score = 0;
    return no;
}

void buildTree(TCell *cell, int player) {
    for (int i = 0; i < 9; i++) {
        if (cell->board.grid[i] == 0) {

            TCell *newCell = createsNode(cell->board);
            newCell->board.grid[i] = player;
            newCell->pai = cell;
            cell->branch[i] = newCell;

            if (!evaluate(&(newCell->board), -player) && !isBoarFull((newCell->board))) {
                buildTree(newCell, -player);
            }
        }
    }
}


int evaluate(const TBoard *board, int player) {

    const int winPatterns[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
            {0, 4, 8}, {2, 4, 6}            // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        int a = winPatterns[i][0];
        int b = winPatterns[i][1];
        int c = winPatterns[i][2];

        if (board->grid[a] == player && board->grid[b] == player && board->grid[c] == player) {
            return 1;
        }
    }
    return 0;
}

int minimax(TCell *node, int depth, int maximizingPlayer) {

    if (evaluate(&(node->board), -1)) {
        return 10 - depth;
    } else if (evaluate(&(node->board), 1)) {
        return depth - 10;
    } else if (isBoarFull((node->board))) {
        return 0;
    }

    if (maximizingPlayer) {
        int bestScore = -100000;

        for (int i = 0; i < 9; i++) {
            TCell *child = node->branch[i];
            if (child != NULL) {
                int score = minimax(child, depth + 1, 0);
                bestScore = score > bestScore ? score : bestScore;
            }
        }

        return bestScore;
    } else {
        int bestScore = 100000;

        for (int i = 0; i < 9; i++) {
            TCell *child = node->branch[i];
            if (child != NULL) {
                int score = minimax(child, depth + 1, 1);
                bestScore = score < bestScore ? score : bestScore;
            }
        }

        return bestScore;
    }
}


void makeBestMove(TCell *actual) {


    int bestScore = -100000;
    int bestMove = 0;

    for (int i = 0; i < 9; i++) {
        TCell *move = actual->branch[i];
        if (move != NULL) {
            int score = minimax(move, 0, 0);
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    current.grid[bestMove] = -1;

}



