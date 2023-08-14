#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#include "Board.h"
#include "Game.h"
#include "Ui.h"

int drawWinner = 0;

TBoard current = {
        .grid = {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void drawO(GLfloat x, GLfloat y) {

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);

    glColor3f(1.0f, 0.4f, 0.2f);
    GLfloat circle_points = 100.0f;
    GLfloat angle;
    int radiusX =77, radiusY = 77;
    glLineWidth(6.0);

    x = x + (WIDTH / 6);
    y = y + (HEIGHT / 6);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < circle_points; i++) {
        angle = 2 * PI * i / circle_points;
        glVertex2f((cos(angle) * radiusX) + x, (sin(angle) * radiusY) + y);
    }
    glEnd();

    glDisable(GL_BLEND);
    glDisable(GL_LINE_SMOOTH);

}


void drawX(int x, int y) {

    glLineWidth(5.0);
    glEnable(GL_LINE_SMOOTH); // anti-aliasing

    glColor3f(0.4f, 0.7f, 1.0f);


    // Draw the crossed lines
    glBegin(GL_LINES);
    glVertex2i(x+5, y+5);
    glVertex2i(x + (WIDTH / 3)-5, y + (HEIGHT / 3)-5);
    glVertex2i(x+5, y + (HEIGHT / 3)-5);
    glVertex2i(x + (WIDTH / 3)-5, y+5);
    glEnd();

    //glFlush();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // background color
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

    if (currentState == MENU) {
        renderMainMenu();
    }else if(currentState == GAME_MODE_SELECTION) {
        renderGameModeSelection();
    }else if(currentState == CONTROLS){
        renderControls();
    }else if(currentState == SCORE){
        renderPoints();
    }else if(currentState == ABOUT){
        renderAboutTheGame();
    }else if (currentState == GAMEPLAY || currentState == SUB) {
        // Render game board

        // Set background color
        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);

        // Draw board grid lines
        glLineWidth(5.0);
        glColor3f(0.2f, 0.2f, 0.2f);

        // Draw vertical lines
        for (int i = 1; i < 3; ++i) {
            glBegin(GL_LINES);
            glVertex2i(WIDTH / 3 * i, 0);
            glVertex2i(WIDTH / 3 * i, HEIGHT);
            glEnd();
        }

        // Draw horizontal lines
        for (int i = 1; i < 3; ++i) {
            glBegin(GL_LINES);
            glVertex2i(0, HEIGHT / 3 * i);
            glVertex2i(WIDTH, HEIGHT / 3 * i);
            glEnd();
        }

        // Draw X and O symbols
        for (int i = 0; i < 9; i++) {
            if (current.grid[i] == 1) {
                drawX(coordinates[i][0], coordinates[i][1]);
            } else if (current.grid[i] == -1) {
                drawO(coordinates[i][0], coordinates[i][1]);
            }
        }

        checkWin();
        if (computerPlayer == 1) {
            for (int i = 0; i < 9; i++) {
                if (current.grid[i] == -1) {
                    drawO(coordinates[i][0], coordinates[i][1]);
                }
            }
        }

        if (winner != 0) {
            currentState = SUB;
            glColor3f(1.0, 0.0, 0.0);
            glLineWidth(6.0);
            glBegin(GL_LINES);
            glVertex2f(victoryLines[drawWinner][0], victoryLines[drawWinner][1]);
            glVertex2f(victoryLines[drawWinner][2], victoryLines[drawWinner][3]);
            glEnd();
        }

        if(currentState == SUB){
            renderSubMenu();
        }

    }

    glutSwapBuffers();
}




