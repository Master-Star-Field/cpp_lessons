#ifndef ENTITY_H
#define ENTITYL_H

//sub structures
struct Display
{
	double sc_w = 1;
	double sc_h = 1;
	double x = 0;
	double y = 0;
	double visible = 1;
};

struct Color3d
{
	double r, g, b;
};

struct Color
{
	double r, g, b, a;
};
struct Timer
{
	unsigned int stime = 0;
	unsigned int etime = 50;
};
struct Effect
{
	char type_effect = 0;
	int stime = 0;
	int etime;
};
struct Animation
{
	char stage = 0;
	int press = 0;
	Timer bioclock;
	double param_1 = 0;
	double param_2 = 0;
	double param_3 = 0;
	double param_4 = 0;
	double param_5 = 0;
	double param_6 = 0;
	double param_7 = 0;
	double param_8 = 0;
};
struct Characteristic
{
	double max_health = 150;
	double health = 150;
	int luck = 23;
	int affinity[4] = { 2,2,2,2 }; // water fire dark wind
	int max_mana = 170;
	double mana = 170;
	double quality = 1;
	double bace_attack = 10;
};

struct Entity
{
	char type_entity = 0; // 0 - hero; 1 - water_elemental; 2 - demon; 3 - dragon
	Display display;
	Animation anim_param;
	Characteristic character;
	Effect effect;

	void set_default(int level);
	void hero_set_default(char cart);
	void animation(int t);
	void draw();
	// type func draw
};


struct Bar
{
	double x;
	double y;
	double s_w;
	double s_h;
	double max_value;
	double value;
	Color color = { 1, 0, 0 };

	void draw();
};

void setBar(Bar& Bar, double x, double y, double s_w, double s_h, double max_value, double value, Color color);
#endif // ENTITY_H
#pragma once
