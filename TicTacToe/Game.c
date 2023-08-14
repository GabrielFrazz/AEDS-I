#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "Game.h"
#include "Board.h"
#include "Util.h"
#include "Computer.h"

int computerPlayer = 1;
int winner = 0;

int pointsControl = 0;
int Xwins = 0;
int Owins = 0;

void checkWin(void) {

    int t = 0;
    int j = 0;
    int i;

    for (i = 0; i < 3; i++) {
        t = 0;
        for (j = 0; j < 3; j++) {
            t += current.grid[j + (i * 3)];
        }

        if ((t == 3) || (t == -3)) {
            winner = 1 * t;
            drawWinner = i + 3;

            if(pointsControl == 0) {
                if (winner > 0) Xwins++;
                else Owins++;
                pointsControl = 1;
            }

            return;

        }
    }

    for (i = 0; i < 3; i++) {
        t = 0;

        for (j = 0; j < 3; j++) {
            t += current.grid[i + (j * 3)];
        }

        if ((t == 3) || (t == -3)) {
            winner = 1 * t;
            drawWinner = i;

            if(pointsControl == 0) {
                if (winner > 0) Xwins++;
                else Owins++;
                pointsControl = 1;
            }

            return;

        }
    }

    t = current.grid[0] + current.grid[4] + current.grid[8];

    if ((t == 3) || (t == -3)) {
        winner = 1 * t;
        drawWinner = 6;

        if(pointsControl == 0) {
            if (winner > 0) Xwins++;
            else Owins++;
            pointsControl = 1;
        }

        return;

    }

    t = current.grid[2] + current.grid[4] + current.grid[6];

    if ((t == 3) || (t == -3)) {
        winner = 1 * t;
        drawWinner = 7;

        if(pointsControl == 0) {
            if (winner > 0) Xwins++;
            else Owins++;
            pointsControl = 1;
        }

        return;

    }

    if(computerPlayer == 1 && turn == -1){

        TCell *actual = createsNode(current);
        makeBestMove(actual);

        turn = 1;
    }

}

void resetGame(void){
    for(int i = 0; i < 9; i++)
        current.grid[i] = 0;
    winner = 0;
    drawWinner = 0;
    pointsControl = 0;
    display();
}
