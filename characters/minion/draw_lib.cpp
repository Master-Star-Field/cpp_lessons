#include <GL/glut.h>
#include "draw_lib.h"
#include<cmath>

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){

    int triangleAmount = 40; //количество линий для рисования круга

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for(int i = 0; i <= triangleAmount;i++) {
            glVertex2f(
                    x + (radius * cos(i *  2.0f * M_PI / triangleAmount)),
                y + (radius * sin(i * 2.0f * M_PI / triangleAmount))
            );
        }
    glEnd();
}

void drawMinion(Color cbody, Color ceye, int x, int y)
{
    glTranslatef(x, y, 0);
    //рисуем голубые ушки
    glColor3f(cbody.r, cbody.g, cbody.b);
   drawFilledCircle(320, 320, 90);
   drawFilledCircle(DISPLAY_WIDTH -  320, 320, 90);

   //ушки внутри
   glColor3f(1, 0, 0);
   drawFilledCircle(320, 320, 50);
   drawFilledCircle(DISPLAY_WIDTH -  320, 320, 50);

   //тело внутри
    glColor3f(cbody.r, cbody.g, cbody.b);
   drawFilledCircle(500, 500, 250);

   //хвостик
   drawFilledCircle(850, 650, 70);

   glColor3f(1,1,1);
   drawFilledCircle(500, 600, 140);

   //глазки
   glColor3f(0,0,0);
   drawFilledCircle(410, 400, 30);
   drawFilledCircle(640, 400, 30);

   glColor3f(ceye.r, ceye.g, ceye.b);
   drawFilledCircle(420, 380, 5);
   drawFilledCircle(650, 380, 5);

   //линия к хвосту
   glColor3f(0,0,0);
   glLineWidth(5);
   glBegin(GL_LINE_STRIP);
   glVertex2d(700, 650);
   glVertex2d(700, 750);
   glVertex2d(850, 750);
   glVertex2d(850, 720);
   glEnd();

   glBegin(GL_LINES);
   glVertex2d(450, 450);
   glVertex2d(570, 450);

   glEnd();

   //ножки
   glColor3f(cbody.r, cbody.g, cbody.b);
   glBegin(GL_QUADS);
   glVertex2d(410, 730);
   glVertex2d(390, 790);
   glVertex2d(410, 790);
   glVertex2d(430, 740);

   glVertex2d(DISPLAY_WIDTH - 410, 730);
   glVertex2d(DISPLAY_WIDTH - 390, 790);
   glVertex2d(DISPLAY_WIDTH - 410, 790);
   glVertex2d(DISPLAY_WIDTH - 430, 740);

   glEnd();
}
