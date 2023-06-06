#ifndef FIRE_METEOR_H
#define FIRE_METEOR_H
#include<ctime>
#include "general.h"
struct fire_meteor
{
    double sc_w = -0.2;
    double sc_h = 0.2;
    double x = -0.3;
    double y = 1.1;
    double visible = 1;
    Color ey_color = Color(1, 1, 1);
};

void up_layer(Color c1, Color c2);
void down_layer(Color c1);

#endif // FIRE_METEOR_H
