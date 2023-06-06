#ifndef DRAW_LIB_H
#define DRAW_LIB_H
#include "entity.h"
#include "world.h"

//отрисовка объектов игры с учетом позиции и масштаба, и ориентации
void draw_desert(Position position);
void draw_cave(Position position);
void draw_water_elemental(Display display, Animation anim_param, double max_health, double health);
void draw_demon(Display display, Animation anim_param, double max_health, double health);
void draw_dragon(Display display, Animation anim_param, double max_health, double health);
void draw_wizard(Display display, Animation anim_param, double max_health, double health, double max_mana, double mana);
void draw(World world, Entity entity_1, Entity entity_2);
//отрисовка стандартного шрифта glut
void RenderString(std::string str);
//отрисовка собственного шрифта цифр
void draw_digitals(int n, double x, double y, Color3d color);
//возвращает структуру Color по трем входным пераметрам
Color makeColor(double r, double g, double b, double a);

//отрисовка окна характеристик
void draw_new_level(World& world, Entity &hero);

//отрисовка callback для изменения карты
void draw_counter(World& world);

//отрисовка способностей противников
void draw_water_elem_attack(Animation anim_param, World world);
void draw_demon_attack(Animation anim_param, World world);
void draw_dragon_attack(Animation anim_param, World world);

//отрисовка экрана при победе
void draw_victory();
//отрисовка объектов в зависимости от этапа мира в данный момент
void draw(World world, Entity entity_1, Entity entity_2);
#endif // DRAW_LIB_H