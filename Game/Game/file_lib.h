#ifndef FILE_LIB_H
#define FILE_LIB_H
#include "world.h"
#include "entity.h"
#include<array>
//������� �������� � ������ �� ����� ���������� ���������� � ������
std::array<Card, count_off_all> load_config();
//��������� ������� ������� � world, hero
void load_world_entity_parametr(World& world, Entity& hero);
#endif // FILE_LIB_Hj
