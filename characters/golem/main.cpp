/*
 * Главный антогонист игры. Гений стихии, цвет которого в дальнейшем будет меняться в зависимости от типа.
 * Из-за большего объема кода, его тело разбито на несколько отдельных функций, которые
 * после объединены в функции drawGolem()
 *
 */


#include <GL/glut.h>
#include "golem_draw_lib.h"

#include<iostream>

const int DISPLAY_WIDTH = 1600;
const int DISPLAY_HEIGHT = 1000;


void renderScene(void);

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    glutCreateWindow("Golem");
    glutDisplayFunc(renderScene);
    glutMainLoop();

    return 0;
}


void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.4, 0.2, 0.5, 0.3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, DISPLAY_WIDTH, DISPLAY_HEIGHT, 0.0f, 0.0f, 1.0f);

    Color cbody = {130,106,0};
    Color cshadow = {99, 117, 117};

    drawGolem(cbody, cshadow, x_position, y_position);

    glutSwapBuffers();
}


