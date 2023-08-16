
#ifndef TICTACTOE_UI_H
#define TICTACTOE_UI_H

#include <stdlib.h>
#include <stdio.h>


enum GameState {
    MENU,
    GAME_MODE_SELECTION,
    CONTROLS,
    SCORE,
    ABOUT,
    SUB,
    GAMEPLAY
};

extern enum GameState currentState;

void drawText(int x, int y, const char* text);
void renderMainMenu(void);
void renderGameModeSelection(void);
void renderControls(void);
void renderAboutTheGame(void);
void renderPoints(void);
void renderSubMenu(void);

#endif //TICTACTOE_UI_H
