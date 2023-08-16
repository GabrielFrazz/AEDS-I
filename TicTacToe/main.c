#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "Board.h"
#include "Util.h"

void init(void){
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glOrtho (0, WIDTH, 0, HEIGHT, -1 ,1);
}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    // glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (WIDTH, HEIGHT);
    glutInitWindowPosition (100, 100);

    glutCreateWindow ("tictactoe");
    init();


    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
