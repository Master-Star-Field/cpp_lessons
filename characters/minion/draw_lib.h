#include <GL/glut.h>

#ifndef DRAW_LIB_H
#define DRAW_LIB_H

struct Color{
    double r;
    double g;
    double b;
};

const int DISPLAY_WIDTH = 1000;
const int DISPLAY_HEIGHT = 1000;

//рисует залитый круг с заданными параметрами
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);

//рисует персонажа
void drawMinion(Color cbody, Color ceye, int x, int y);

#endif // DRAW_LIB_H
