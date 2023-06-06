#ifndef LOGIC_LIB_H
#define LOGIC_LIB_H
#include "entity.h"	
#include "world.h"

// устанавливает начальн. значения переменным враг, герой и мир
void initializate(World& world, Entity& enemy, Entity& hero);
//пассивно восстанавливает ману игроку
void regenarateMana(Entity& hero);

//урон противнику способностям
void cardUse(World world, Entity& hero, Entity& enemy);

// функция следящая за событиями связанными со значением world.stage
//0 - обычный ход игры
//1 - прокачка
//2 - смерть
//3 - победа
void update(World& world, Entity& enemy, Entity& hero, int t);
//добавить характеристики окна прокачки герою
void appendCharacteristic(World& world, Entity& hero);

//применение спосбности карты ( урон врагу или бафф герою)
void cardUse(World world, Entity& hero, Entity& enemy);

// установка момента атаки врага, а также ее частоты (на псевдослуч. числах)
void enemy_attack_detect(World& world, Entity& enemy, Entity& hero);

//нанесение урона игроку врагом
void enemy_attack(World& world, Entity& enemy, Entity& hero);

//установка длительного эффекта на героя/врага
void EffectSet(Entity& hero, Entity& enemy, Card card, int n);

//применение длительного эффекта на врага/игрока в данный момент времени
void EffectReduse(Entity& entity);


#endif // LOGIC_LIB_H