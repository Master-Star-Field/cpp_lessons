/* В какой то момент мне показалось, что только фон с цикличными анимациями, будет смотреться скучно.
 * Поэтому я решил добавить статичные объекты. К примеру дом за которым падают звезды.
 * В результате вышел такой маленький домик, которому надо еще добавить возможность изменять цвет.
 */

#include<GL\glut.h>
#include "draw_lib.h"

void renderScene()
{
    glClearColor(0.5, 0.9, 0.4, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, 900.0f, 0, 700, 0.0f, 1.0f);
    home(0.3, 0.3, 1000, 1100);
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 90);
    glutInitWindowSize(900, 700);
    glutCreateWindow("background house");
    glutDisplayFunc(renderScene);
    glutMainLoop();
}
