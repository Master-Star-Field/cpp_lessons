#ifndef FILE_LIB_H
#define FILE_LIB_H
#include "world.h"
#include "entity.h"
#include<array>
//функция загрузки в массив из файла параметров заклинаний в картах
std::array<Card, count_off_all> load_config();
//установка базовых зачений в world, hero
void load_world_entity_parametr(World& world, Entity& hero);
#endif // FILE_LIB_Hj
