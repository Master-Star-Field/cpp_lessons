#ifndef WORLD_H
#define WORLD_H
#include <string>
#include "entity.h"

struct WorldTimer
{
    unsigned int stime = 80;
    unsigned int etime = 80;
};

struct MouseCoord
{
    double x_start = 4;
    double y_start = 1014;
    double x_end = 146;
    double y_end = 806;
};
struct Position
{
    double sc_w = 0.08;
    double sc_h = 0.22;
    double x = -0.92;
    double y = -0.8;
};
struct Card
{
    short card_type = 0;
    short card_num = 0;
    short attribute = 1; // 0 - none; 1 - water; 2 - dark; 3 - wind; 4 - fire 
    short  mana = 30;
    short value = 100;
    Position position;
    MouseCoord mouse_coord;
    int mouse_num;
    WorldTimer timer;
    std::string name;

    void set_default(int i);
};

const int count_off_all = 21;//19

struct World
{
    Position position;
    short level = 1;
    char type_terra = 0;
    int points = 5;
    int plus_points = 5;
    char count_off_all = 5;
    bool change_press = false;
    int right_press = 0;
    int crystal_state = 0;
    WorldTimer card_change;
    char stage = 0; // 0 - game; 1 - choice characteristic; 2 - game over;
    const static char card_count = 4;
    char count_abilities = 1;
    Card deck[card_count];
    double append[8] = { 0,0,0,0, 0,0, 0, 0 }; // health, luck, mana, quality, fire, dark, water, wind
    void draw();
    void set_default();
    void draw_cards(Entity entity_1);
};
#endif