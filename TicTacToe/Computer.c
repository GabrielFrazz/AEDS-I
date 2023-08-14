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

int evaluate(TBoard board) {
    int lines[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Horizontal
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Vertical
            {0, 4, 8}, {2, 4, 6}             // Diagonal
    };

    for (int i = 0; i < 8; i++) {
        int sum = board.grid[lines[i][0]] + board.grid[lines[i][1]] + board.grid[lines[i][2]];
        if (sum == 3) return 10;
        if (sum == -3) return -10;
    }

    return 0;
}

int minimax(TCell *node, int isMaximizing) {

    TBoard board = node->board;

    int score = evaluate(board);
    if (score != 0) {
        return score;
    }

    if (isMaximizing) {
        int bestScore = -1000000;
        for (int i = 0; i < 9; i++) {
            if (board.grid[i] == 0) {
                board.grid[i] = -1;
                TCell *child = createsNode(board);
                node->branch[i] = child;
                int currentScore = -minimax(child, 0);
                board.grid[i] = 0;
                if (currentScore > bestScore) {
                    bestScore = currentScore;
                }
            }
        }
        node->score = bestScore;
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 9; i++) {
            if (board.grid[i] == 0) {
                board.grid[i] = 1;
                TCell *child = createsNode(board);
                node->branch[i] = child;
                int currentScore = minimax(child, 1);
                board.grid[i] = 0;
                if (currentScore < bestScore) {
                    bestScore = currentScore;
                }
            }
        }
        node->score = bestScore;
        return bestScore;
    }
}

void makeBestMove(TCell *actual) {

    int bestMove = -1;
    int bestScore = -1000;

    for (int i = 0; i < 9; i++) {
        if (current.grid[i] == 0) {
            TCell *child = actual->branch[i];
            if (child == NULL) {
                child = createsNode(actual->board);
                child->board.grid[i] = -1;
                actual->branch[i] = child;
            }
            int currentScore = minimax(child, 0);
            if (currentScore > bestScore) {
                bestScore = currentScore;
                bestMove = i;
            }
        }
    }

    if (bestMove != -1) {
        current.grid[bestMove] = -1;
    }
}



