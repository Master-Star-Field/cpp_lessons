#ifndef DRAW_LIB_H
#define DRAW_LIB_H
#include "entity.h"
#include "world.h"

//��������� �������� ���� � ������ ������� � ��������, � ����������
void draw_desert(Position position);
void draw_cave(Position position);
void draw_water_elemental(Display display, Animation anim_param, double max_health, double health);
void draw_demon(Display display, Animation anim_param, double max_health, double health);
void draw_dragon(Display display, Animation anim_param, double max_health, double health);
void draw_wizard(Display display, Animation anim_param, double max_health, double health, double max_mana, double mana);
void draw(World world, Entity entity_1, Entity entity_2);
//��������� ������������ ������ glut
void RenderString(std::string str);
//��������� ������������ ������ ����
void draw_digitals(int n, double x, double y, Color3d color);
//���������� ��������� Color �� ���� ������� ����������
Color makeColor(double r, double g, double b, double a);

//��������� ���� �������������
void draw_new_level(World& world, Entity &hero);

//��������� callback ��� ��������� �����
void draw_counter(World& world);

//��������� ������������ �����������
void draw_water_elem_attack(Animation anim_param, World world);
void draw_demon_attack(Animation anim_param, World world);
void draw_dragon_attack(Animation anim_param, World world);

//��������� ������ ��� ������
void draw_victory();
//��������� �������� � ����������� �� ����� ���� � ������ ������
void draw(World world, Entity entity_1, Entity entity_2);
#endif // DRAW_LIB_H