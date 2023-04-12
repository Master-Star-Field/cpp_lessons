#include <GL/glut.h>
#include "draw_lib.h"

void renderScene(void);
void update(int value);

double t = 0;

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glClearColor(1, 1, 1, 1);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(0.0f, 1000, 1000, 0.0f, 0.0f, 1.0f);

    drawGrid();
    drawLineFunction(t, CLINE, 3);

}

// Функция обновления графика через определенное время
void update(int value) {
    if (t <= last_value) {
        t += 0.05;
        glutPostRedisplay();
        glutTimerFunc(TICKS, update, 0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Parametric grafer");
    glutDisplayFunc(renderScene);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
