/* Изначально я пытался создать функцию для рисования залитых кругов.
 * Когда у меня это получилось, захотелось на чем то ее испытать
 * В игре мне хотелось добавить какого-то помощника, каоторый иногда помогает герою
 * Так совершенно случайно у меня получился этот странный, но довольно милый недо покемон
 *
 */

#include <GL/glut.h>
#include "draw_lib.h"


void renderScene(void);


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    glutCreateWindow("Game");
    glutDisplayFunc(renderScene);

    glutMainLoop();

    return 0;
}




void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.4, 0.2, 0.5, 0.3);
    glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 1000, 1000, 0, 1, 0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        Color cbody = {0, 147.0/255, 221.0/255};
        Color ceye = {1, 1, 1};
        drawMinion(cbody, ceye, -50, 100);


    glutSwapBuffers();



}

