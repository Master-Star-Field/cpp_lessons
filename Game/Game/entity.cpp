#include <GL/glut.h>
#include "entity.h"
#include "drawlib.h"
#include "animation_lib.h"
void setBar(Bar& Bar, double x, double y, double s_w, double s_h, double max_value, double value, Color color)
{
	Bar.x = x;
	Bar.y = y;
	Bar.s_w = s_w;
	Bar.s_h = s_h;
	Bar.max_value = max_value;
	Bar.value = value;
	Bar.color = color;
}

int lenNum(int num)
{
	int count = 0;
	while (true)
	{
		if (num / 10 >= 1)
			num /= 10, count += 1;
		else
			break;
	}
	return count + 1;
}
void Bar::draw()
{
	if (value <= 0)
		value = 0;

	glPushMatrix();
	glTranslated(x, y, 0);
	glScaled(s_w, s_h, 1);
	glColor4d(205.0 / 255, 224.0 / 255, 249.0 / 255, 1);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(0.1, 0);
	glVertex2d(0.1, 0.05);
	glVertex2d(0, 0.05);
	glEnd();

	glColor4d(color.r, color.g, color.b, 1);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(value / max_value * 0.1, 0);
	glVertex2d(value / max_value * 0.1, 0.05);
	glVertex2d(0, 0.05);
	glEnd();

	glLineWidth(5);
	glColor4d(0, 0, 0, 1);
	glBegin(GL_LINE_LOOP);
	glVertex2d(0, 0);
	glVertex2d(0.1, 0);
	glVertex2d(0.1, 0.05);
	glVertex2d(0, 0.05);
	glEnd();

	glPushMatrix();
	glLineWidth(3);
	glScaled(0.1, 0.15, 1);
	draw_digitals(value, 0.5, 0.1, Color3d{ 1,1,1 });
	glColor4d(1,1,1, 1);
	glTranslated(0.015
		*lenNum(value), 0, 0);
	glBegin(GL_LINES);
	glVertex2d(0.51, 0.28);
	glVertex2d(0.54, 0.06);
	glEnd();
	draw_digitals(max_value, 0.7 + 0.01*lenNum(value), 0.1, Color3d{ 1,1,1 });
	glPopMatrix();
	glPopMatrix();


}
void Entity::draw()
{
	switch (type_entity)
	{
	case 0:
		draw_wizard(display, anim_param, character.max_health, character.health, character.max_mana, character.mana);
		break;
	case 1:
		draw_water_elemental(display, anim_param, character.max_health, character.health);
		break;
	case 2:
		draw_demon(display, anim_param, character.max_health, character.health);
		break;
	case 3:
		draw_dragon(display, anim_param, character.max_health, character.health);
		break;
	}
}
void Entity::hero_set_default(char cart)
{
	/*
	display.sc_w = 0.22;
	display.sc_h = 0.35;
	display.x = 2.5;
	display.y = -0.4;
	*/
	display.sc_w = 0.25;
	display.sc_h = 0.5;
	display.x = -0.7;
	if (cart == 0)
		display.y = -0.05;
	if (cart == 1)
		display.y = -0.08;
	character.health = character.max_health;
	character.mana = character.max_mana;
	anim_param.bioclock.etime = 68;
}
void Entity::set_default(int level)
{
	type_entity = rand() % 3 + 1;
	//type_entity = 2;
	character.max_health += 100 * level;
	character.health = character.max_health;
	switch (type_entity)
	{

	case 1: //water elemental
		display.sc_w = 0.4;
		display.sc_h = 0.6;
		display.x = 0.4;
		display.y = 0.05;

		anim_param.bioclock.etime = 54;

		character.affinity[0] = 7 + level * 2; // water
		character.affinity[1] = 0; // fire
		character.affinity[2] = 1 + level * 2; //dark 
		character.affinity[3] = 4 * level * 2; // wind

		break;

	case 2: //demon

		display.sc_w = 0.5;
		display.sc_h = 0.52;
		display.x = 0.4;
		display.y = 0.1;

		anim_param.bioclock.etime = 150;

		character.affinity[0] = 1 + level; // water
		character.affinity[1] = 3 + level * 2; // fire
		character.affinity[2] = 8 + level * 1.5; //dark 
		character.affinity[3] = level; // wind

		break;

	case 3: // dragon

		display.sc_w = -0.385;
		display.sc_h = 0.7;
		display.x = 0.4;
		display.y = 0.15;

		anim_param.bioclock.etime = 24;
		character.bace_attack = 20;
		character.affinity[0] = 3 * level; // water
		character.affinity[1] = 0; // fire
		character.affinity[2] = 2 * level; //dark 
		character.affinity[3] = 9 * level; // wind

		break;
	}
}

void Entity::animation(int t)
{
	switch (type_entity)
	{
	case 0:
		hero_animation(anim_param, t);
		break;
	case 1:
		water_animation(anim_param, t);
		break;
	case 2:
		demon_animation(anim_param, t);
		break;
	case 3:
		dragon_animation(anim_param, t);
		break;
	}
}