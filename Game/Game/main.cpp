#include <GL/glut.h>
#include "drawlib.h"
#include "entity.h"
#include "world.h"
#include  "logic_lib.h"
#include "animation_lib.h"
#include "music_lib.h"
#include "file_lib.h"
#include<ctime>
#include<array>
#include"file_lib.h"

void renderScene(void);
void mouseClick(int button, int state, int x, int y);
void timerFunction(int value);

int t = 0;
World world;
Entity hero, enemy;

void timerFunction(int value) {
	if (t == 480)
		t = 0;
	t += 1;
	glutPostRedisplay();
	glutTimerFunc(33, timerFunction, 1);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH), glutGet(GLUT_SCREEN_HEIGHT));
	glutCreateWindow("Elements and Magic");
	load_world_entity_parametr(world, hero);
	initializate(world, enemy, hero);
	srand(time(0));

	glutTimerFunc(33, timerFunction, 1);
	glutMouseFunc(mouseClick);
	glutDisplayFunc(renderScene);
	glutMainLoop();

	return 0;
}



void renderScene(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthMask(GL_FALSE);
	glClearColor(0.0, 0.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	draw(world, hero, enemy);
	animation(world, hero, enemy, t);
	update(world, enemy, hero, t);

	//ContinueSound(); // включить фоновую музыку
	glutSwapBuffers();
}

void mouseClick(int button, int state, int x, int y)
{
	// изменения карты заклинания по правому клику мыши
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP && world.stage == 0 && !world.change_press)
	{
		world.change_press = true;
		for (int i = 0; i < world.card_count; i++)
		{
			if ((world.deck[i].mouse_coord.x_start + i * 142) <= x && x <= (world.deck[i].mouse_coord.x_end + i * 142) && y >= world.deck[i].mouse_coord.y_end && y <= world.deck[i].mouse_coord.y_start) {

				world.deck[i].card_num = rand() % count_off_all;
				world.deck[i].set_default(i);
				world.deck[i].position.x -= 0.155 * i;
				world.right_press = i + 1;
			}
		}
	}
	//использование карты левой кнопкой мыши.
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		switch (world.stage)
		{
		case 0: // только во время игры
			for (int i = 0; i < world.card_count; i++)
			{
				if ((world.deck[i].mouse_coord.x_start + i * 142) <= x && x <= (world.deck[i].mouse_coord.x_end + i * 142) && y >= world.deck[i].mouse_coord.y_end && y <= world.deck[i].mouse_coord.y_start && hero.anim_param.stage == 0)
				{
					hero.anim_param.press = i + 1;
					if (hero.character.mana - world.deck[i].mana >= -0.01)
					{
						// определение какой тип анимации активировать: на себя, на противника
						if (!world.deck[i].card_type)
						{
							hero.anim_param.stage = 1;
						}
						if (world.deck[i].card_type) {
							hero.anim_param.stage = 2;
						}
					}
				}
			}
			break;

		case 1: // окно повышения характеристик
			if (441 <= x && x <= 616 && y >= 212 && y <= 321 && world.points != 0) {
				world.points -= 1;
				world.append[0] += 20;
			}
			if (450 <= x && x <= 603 && y >= 358 && y <= 466 && world.points != 0) {
				if (hero.character.luck < 23)
				{
					world.points -= 1;
					world.append[1] += 1;
				}

			}
			if (483 <= x && x <= 600 && y >= 493 && y <= 600 && world.points != 0) {
				world.points -= 1;
				world.append[2] += 20;
			}
			if (453 <= x && x <= 613 && y >= 630 && y <= 736 && world.points != 0) {
				world.points -= 1;
				world.append[3] += 1;
			}
			if (1081 <= x && x <= 1234 && y >= 198 && y <= 308 && world.points != 0) {
				world.points -= 1;
				world.append[4] += 1;
			}
			if (1083 <= x && x <= 1247 && y >= 344 && y <= 450 && world.points != 0) {
				world.points -= 1;
				world.append[5] += 1;
			}
			if (1068 <= x && x <= 1242 && y >= 495 && y <= 596 && world.points != 0) {
				world.points -= 1;
				world.append[6] += 1;
			}
			if (1062 <= x && x <= 1236 && y >= 643 && y <= 738 && world.points != 0) {
				world.points -= 1;
				world.append[7] += 1;
			}
			if (755 <= x && x <= 1021 && y >= 804 && y <= 872 && world.points == 0) {
				appendCharacteristic(world, hero);
				Entity new_enemy;
				new_enemy.set_default(world.level);
				enemy = new_enemy;
				world.stage = 0;
				world.points += world.plus_points;
				for (int i = 0; i < 8; i++)
					world.append[i] = 0;
				world.level += 1;
			}
			break;
		}
	}
}




