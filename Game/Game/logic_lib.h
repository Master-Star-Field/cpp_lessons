#ifndef LOGIC_LIB_H
#define LOGIC_LIB_H
#include "entity.h"	
#include "world.h"

// ������������� �������. �������� ���������� ����, ����� � ���
void initializate(World& world, Entity& enemy, Entity& hero);
//�������� ��������������� ���� ������
void regenarateMana(Entity& hero);

//���� ���������� ������������
void cardUse(World world, Entity& hero, Entity& enemy);

// ������� �������� �� ��������� ���������� �� ��������� world.stage
//0 - ������� ��� ����
//1 - ��������
//2 - ������
//3 - ������
void update(World& world, Entity& enemy, Entity& hero, int t);
//�������� �������������� ���� �������� �����
void appendCharacteristic(World& world, Entity& hero);

//���������� ���������� ����� ( ���� ����� ��� ���� �����)
void cardUse(World world, Entity& hero, Entity& enemy);

// ��������� ������� ����� �����, � ����� �� ������� (�� ����������. ������)
void enemy_attack_detect(World& world, Entity& enemy, Entity& hero);

//��������� ����� ������ ������
void enemy_attack(World& world, Entity& enemy, Entity& hero);

//��������� ����������� ������� �� �����/�����
void EffectSet(Entity& hero, Entity& enemy, Card card, int n);

//���������� ����������� ������� �� �����/������ � ������ ������ �������
void EffectReduse(Entity& entity);


#endif // LOGIC_LIB_H