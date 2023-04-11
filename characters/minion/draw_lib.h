#include <GL/glut.h>

#ifndef DRAW_LIB_H
#define DRAW_LIB_H


const int DISPLAY_WIDTH = 1000;
const int DISPLAY_HEIGHT = 1000;

//рисует залитый круг с заданными параметрами
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);

//рисует персонажа
void drawMinion();

#endif // DRAW_LIB_H
