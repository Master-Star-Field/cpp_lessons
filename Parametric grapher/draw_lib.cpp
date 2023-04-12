#include <GL/glut.h>
#include<string>
#include "draw_lib.h"

//использую Stroke? а не  Bitmap, т. к. последний не поддерживает поворот с помощью glRotatef
//рисование строк по оси y
void drawString(float x, float y, float z, std::string s) {
    glPushMatrix();
        glTranslatef(x, y,z);
        glRotatef(180, 0, 0, 1);
        glRotatef(-180, 0, 1, 0);
        glScalef(0.1,0.1,0);
    for (int c = 0; c < s.size(); c++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, s[c]);  // Updates the position
    glPopMatrix();
}

//рисование строк по оси x
void drawStringh(float x, float y, float z, std::string s) {
    glPushMatrix();
        glTranslatef(x, y + 85,z);
        glRotatef(90, 0, 0, 1);
        glRotatef(-180, 0, 1, 0);
        glScalef(0.1,0.1,0);
    for (int c = 0; c < s.size(); c++)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, s[c]);  // Updates the position
    glPopMatrix();
}

//рисование сетки графика

void drawGrid()
{
    glColor3b(102/255,100/255,128/255);
    glLineWidth(1);


    double n_x = min_x();
    double n_y = min_y();

    double step_x = dx / (WIDTH / 30);
    double step_y = dy / (HEIGHT / 30);

    //отрисовываем сетку и значения x, y по ячейкам
    //horizontal x
    for(int i = 120; i <= WIDTH; i+= 30)
    {
        glBegin(GL_LINES);
            glVertex2f(i, 0);
            glVertex2f(i, HEIGHT - 120);
        glEnd();
        if(i + 30 <= WIDTH)
            drawStringh(i - 5, HEIGHT - 95, 0, std::to_string(n_x));
        n_x += step_x;
    }
    //vertical y
    for(int i = HEIGHT - 120; i >= 0  ; i-= 30)
    {
        glBegin(GL_LINES);
            glVertex2f(120, i);
            glVertex2f(WIDTH, i);
        glEnd();
        if(i - 30 >= 0)
            drawString(5, i + 5, 0, std::to_string(n_y));
        n_y += step_y;
    }

    // рисуем крест координатных осей
    glColor3f(0,0,0);
    glLineWidth(4);

    glBegin(GL_LINES);
    glVertex2f(570, 0);
    glVertex2f(570, HEIGHT - 120);
    glVertex2f(120, 420);
    glVertex2f(WIDTH, 420);
    glEnd();

}

void drawLineFunction(double t, Color cline, short width)
{
    glColor3f(cline.r, cline.g, cline.b);
    glLineWidth(width);
    glBegin(GL_LINE_STRIP);
    for (float i = first_value; i <= t; i += 0.05) {
        float y_c = y(i) * (HEIGHT - 120)  / dy;
        float x_c = x(i) * (WIDTH - 120)  / dx;
        glVertex2f(570 + x_c, 420 + y_c);
    }
    glEnd();

    glFlush();
}

double max_y()
{
    double max = y(first_value);
    for(double i  = first_value + 0.01; i <= last_value; i+= 0.01)
        if(y(i) > max)
            max = y(i);
    return max;

}

double min_y()
{
    double min = y(first_value);
    for(double i  = first_value + 0.01; i <= last_value; i+= 0.01)
        if(y(i) < min)
            min = y(i);
    return min;

}

double max_x()
{
    double max = x(first_value);
    for(double i  = first_value + 0.01; i <= last_value; i+= 0.01)
        if(x(i) > max)
            max = x(i);
    return max;

}

double min_x()
{
    double min = x(first_value);
    for(double i  = first_value + 0.01; i <= last_value; i+= 0.01)
        if(x(i) < min)
            min = x(i);
    return min;

}
