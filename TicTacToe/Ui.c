#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "Board.h"
#include "Ui.h"
#include "Game.h"


enum GameState currentState = MENU;

void drawText(int x, int y, const char* text) {
    glRasterPos2i(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text);
        ++text;
    }
}

void renderMainMenu(void) {

    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_LINE_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.0);

    drawText(WIDTH / 2 - 120, HEIGHT - 100, "1 - Game Mode");

    drawText(WIDTH / 2 - 120, HEIGHT - 150, "2 - Controls");

    drawText(WIDTH / 2 - 120, HEIGHT - 200, "3 - About the Game");

    drawText(WIDTH / 2 - 120, HEIGHT - 250, "4 - Exit");

}

void renderGameModeSelection(void){

    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.0);

    drawText(WIDTH / 2 - 120, HEIGHT - 100, "1 - PlayerVsPlayer");

    drawText(WIDTH / 2 - 120, HEIGHT - 150, "2 - PlayerVsComputer");

    drawText(WIDTH / 2 - 120, HEIGHT - 200, "3 - Main Menu");

}

void renderControls(void){

    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.0);

    drawText(WIDTH / 500, HEIGHT - 100, "R - restart game");

    drawText(WIDTH / 500, HEIGHT - 130, "P - show score");

    drawText(WIDTH / 500, HEIGHT - 160, "M - main menu");

    drawText(WIDTH / 500, HEIGHT - 190, "G - select game mode");

    drawText(WIDTH / 500, HEIGHT - 220, "Esc - Exit");
}

void renderPoints(void){

    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.0);

    char formattedTextX[50];
    snprintf(formattedTextX, sizeof(formattedTextX), "X - %d", Xwins);

    char formattedTextO[50];
    snprintf(formattedTextO, sizeof(formattedTextO), "O - %d", Owins);

    drawText(WIDTH / 2 - 120, HEIGHT - 100, formattedTextX);

    drawText(WIDTH / 2 - 120, HEIGHT - 150, formattedTextO);

    drawText(WIDTH / 500, HEIGHT - 250, "B - back");

    drawText(WIDTH / 500, HEIGHT - 280, "M - Main Menu");

    drawText(WIDTH / 500, HEIGHT - 310, "Esc - Exit");
}

void renderSubMenu() {

    int submenuWidth = 200;
    int submenuHeight = 200;

    int submenuX = (WIDTH - submenuWidth) / 2;
    int submenuY = (HEIGHT - submenuHeight) / 2;

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2i(submenuX, submenuY + submenuHeight);
    glVertex2i(submenuX + submenuWidth, submenuY + submenuHeight);
    glVertex2i(submenuX + submenuWidth, submenuY);
    glVertex2i(submenuX, submenuY);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);

    char formattedTextX[50];
    snprintf(formattedTextX, sizeof(formattedTextX), "X - %d", Xwins);

    char formattedTextO[50];
    snprintf(formattedTextO, sizeof(formattedTextO), "O - %d", Owins);

    drawText(submenuX + 10, submenuY + submenuHeight - 40, formattedTextX);

    drawText(submenuX + 10, submenuY + submenuHeight - 70, formattedTextO);

    drawText(submenuX + 10, submenuY + submenuHeight - 120, "R - Play Again");

    drawText(submenuX + 10, submenuY + submenuHeight - 150, "M - Main Menu");

    drawText(submenuX + 10, submenuY + submenuHeight - 180, "Esc - Exit");

}

void renderAboutTheGame() {
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, WIDTH, 0, HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.2f, 0.2f, 0.2f);
    glLineWidth(2.0);

    drawText(WIDTH / 2 - 60, HEIGHT - 50, "About the Game");

    drawText(WIDTH / 15, HEIGHT - 120, "Tic-Tac-Toe OpenGL Game");

    drawText(WIDTH / 15, HEIGHT - 180, "Created by Carlos Gabriel de Oliveira Frazao");
    drawText(WIDTH / 15, HEIGHT - 210, "as part of the AEDS Discipline of Computer Engineering.");


    drawText(WIDTH / 500, HEIGHT - 460, "M - Menu");

}










