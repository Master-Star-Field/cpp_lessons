#ifndef GOLEM_DRAW_LIB_H
#define GOLEM_DRAW_LIB_H

struct Color
{
    double r;
    double g;
    double b;
};

const int WIDTH_BOX = 600;
const int HEIGHT_BOX = 600;

const float x_position = 500;
const float y_position = 400;

void drawBody();
void drawHand(char type);
void drawHead();
void drawGolem();

#endif // GOLEM_DRAW_LIB_H
