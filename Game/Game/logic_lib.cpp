#include "entity.h"
#include "world.h"
#include <cstdlib>
#include<ctime>
#include<cmath>
#include<array>
#include "file_lib.h"

void initializate(World &world, Entity &enemy, Entity &hero)
{
	srand(time(0));
	world.set_default();
	hero.hero_set_default(world.type_terra);
	enemy.set_default(world.level);
}
void regenarateMana(Entity& hero)
{
	double plus_mana = hero.character.max_mana / 100.0 * hero.character.quality;
	if (hero.character.quality > 10)
		plus_mana /= hero.character.quality / 4;
	if (hero.character.mana + plus_mana <= hero.character.max_mana)
		hero.character.mana += plus_mana;
	else
		hero.character.mana = hero.character.max_mana;
	if (hero.character.mana  < 0)
		hero.character.mana += 1;
}

void EffectSet(Entity& hero, Entity& enemy, Card card, int n)
{
	switch (n)
	{
	case 1:
		enemy.effect.type_effect = 1;
		enemy.effect.etime = card.value;
		break;
	case 2:
		hero.effect.type_effect = 2;
		hero.effect.etime = card.value;
		break;
	case 3:
		hero.effect.type_effect = 3;
		hero.effect.etime = card.value;
		break;
	case 4:
		hero.effect.type_effect = 4;
		hero.effect.etime = card.value;
		break;
	case 5:
		enemy.effect.type_effect = 5;
		enemy.effect.etime = card.value;
		break;
	case 6:
		enemy.effect.type_effect = 6;
		enemy.effect.etime = card.value;
		break;
	case 7:
		hero.effect.type_effect = 7;
		hero.effect.etime = card.value;
		break;
	case 8:
		hero.effect.type_effect = 8;
		hero.effect.etime = card.value;
		break;
	}
}
//отравление противника
void poison(Entity& entity, Entity attacker)
{
	if (entity.effect.stime <= entity.effect.etime)
	{
		if (entity.character.health >= 10)
			entity.character.health -= (0.8 - entity.character.affinity[0] / 10 + attacker.character.affinity[0] / 10);
	}
	else
	{
		entity.effect.type_effect = 0;
		entity.effect.stime = 0;
	}

	entity.effect.stime += 1;
}
//регеннерация здровья героя
void health_regeneration(Entity& entity)
{
	if (entity.effect.stime <= entity.effect.etime)
	{
		if (entity.character.health <= entity.character.max_health)
			entity.character.health += 0.5 + 0.2 * entity.character.quality + entity.character.affinity[0] / 10.0;
	}
	else
	{
		entity.effect.type_effect = 0;
		entity.effect.stime = 0;
	}

	entity.effect.stime += 1;
}
//увеличение affinity к огню героя
void fire_resist(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[1] += 6;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[1] -= 6;
	}

	entity.effect.stime += 1;
}
//увеличение affinity к ветру героя
void wind_resist(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[3] += 6;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[3] -= 6;
	}

	entity.effect.stime += 1;
}
//увеличение affinity к тьме героя
void dark_resist(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[2] += 6;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[2] -= 6;
	}

	entity.effect.stime += 1;
}
//увеличение affinity к воде героя
void water_resist(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[0] += 6;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[0] -= 6;
	}

	entity.effect.stime += 1;
}
//уменьшение affinity к тьме врага
void dark_weakness(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[2] -= 5;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[2] += 5;
	}

	entity.effect.stime += 1;
}
//уменьшение affinity к огню врага
void fire_weakness(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[1] -= 5;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[1] += 5;
	}

	entity.effect.stime += 1;
}
//уменьшение affinity к ветру врага
void wind_weakness(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.affinity[3] -= 5;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.affinity[3] += 5;
	}

	entity.effect.stime += 1;
}
//увеличение quality
void mana_bust(Entity& entity)
{
	if (entity.effect.stime == 0)
	{
		entity.character.quality += 5;
	}
	if (entity.effect.stime == entity.effect.etime)
	{
		entity.character.quality -= 5;
	}

	entity.effect.stime += 1;
}

void EffectReduse(Entity& entity, Entity attacker)
{
	switch (entity.effect.type_effect)
	{
	case 1:
		poison(entity, attacker);
		break;
	case 2:
		dark_resist(entity);
		break;
	case 3:
		wind_resist(entity);
		break;
	case 4:
		water_resist(entity);
		break;
	case 5:
		fire_weakness(entity);
		break;
	case 6:
		wind_weakness(entity);
		break;
	case 7:
		mana_bust(entity);
		break;
	case 8:
		health_regeneration(entity);
		break;
	}
}

void enemy_attack_detect(World& world, Entity& enemy, Entity& hero)
{
	int attack_be;
	switch (enemy.type_entity)
	{
	case 1:
		attack_be = rand() % 100;
		if (attack_be == 0)
		{
			enemy.anim_param.stage = 1;
		}
		break;
	case 2:
		attack_be = rand() % 200;
		if (attack_be == 0)
		{
			enemy.anim_param.stage = 1;
		}
		break;
	case 3:
		attack_be = rand() % 150;
		if (attack_be == 0)
		{
			enemy.anim_param.stage = 1;
		}
		break;
	}

}
void enemy_attack(World& world, Entity& enemy, Entity& hero)
{
	switch (enemy.type_entity)
	{
	double damage;
	case 1: // water elem
		damage = enemy.character.bace_attack * world.level * 0.5;
		if (hero.character.affinity[0] > enemy.character.affinity[0])
			damage /= hero.character.affinity[0] - enemy.character.affinity[0] + 1;
		else
			damage *= (double)enemy.character.affinity[0] / hero.character.affinity[0] /3;
		hero.character.health -=  damage;
		break;
	case 2: //demon
		damage = enemy.character.bace_attack * world.level * 0.15;
		if (hero.character.affinity[2] > enemy.character.affinity[2])
			damage /= hero.character.affinity[2] - enemy.character.affinity[2] + 1;
			hero.character.max_health -= damage;
		break;
	case 3: //dragon
		damage = enemy.character.bace_attack * world.level * 0.5;
		if (hero.character.affinity[3] > enemy.character.affinity[3])
			damage /= hero.character.affinity[3] - enemy.character.affinity[3] + 1;
		else
			damage *= (double)enemy.character.affinity[0] / hero.character.affinity[0] / 3;
		hero.character.health -= damage;
		break;
	}

}

void appendCharacteristic(World& world, Entity& hero)
{
	hero.character.max_health += world.append[0];
	hero.character.luck += world.append[1];
	hero.character.max_mana += world.append[2];
	hero.character.quality += world.append[3];
	hero.character.affinity[0] += world.append[4];
	hero.character.affinity[1] += world.append[5];
	hero.character.affinity[2] += world.append[6];
	hero.character.affinity[3] += world.append[7];
}

//bace attack
void card_0(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value*hero.character.quality*0.5 + hero.character.max_mana / 40 / hero.character.quality;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 50.0);
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//super attack
void card_1(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value * hero.character.quality * 0.5 + hero.character.max_mana / 10 / hero.character.quality;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 10.0);
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//mana victim
void card_2(Entity& hero, Entity& enemy, Card card)
{
	hero.character.health -= card.mana;
	if (hero.character.mana + card.value * 10 < hero.character.max_mana)
		hero.character.mana += card.value * 10;
	else
		hero.character.mana = hero.character.max_mana;

}
//poison
void card_3(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -=card.mana;
	EffectSet(hero, enemy, card,  1);
}
//heal
void card_4(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	if (hero.character.health +  hero.character.affinity[0] * card.value <= hero.character.max_health)
		hero.character.health +=  hero.character.affinity[0] * card.value;
	else
		hero.character.health = hero.character.max_health;

}
//water arrow
void card_5(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value * hero.character.quality * 0.5 + hero.character.max_mana / 40 / hero.character.quality;
	damage /= 1.4;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 10.0);
	if(hero.character.affinity[0] > enemy.character.affinity[0])
		damage *= hero.character.affinity[0] - enemy.character.affinity[0];
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//dark bolt
void card_6(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value * hero.character.quality * 0.5 + hero.character.max_mana / 40 / hero.character.quality;
	damage /= 1.5;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 10.0);
	if (hero.character.affinity[2] > enemy.character.affinity[2])
		damage *= hero.character.affinity[2] - enemy.character.affinity[2];
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//death
void card_7(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	bool live = rand() % 2;
	if (live)
		enemy.character.health = -1;
	else
		hero.character.health = -1;

}
//fire hand
void card_8(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value * hero.character.quality * 0.5 + hero.character.max_mana / 40 / hero.character.quality;
	damage /= 1.3;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 10.0);
	if (hero.character.affinity[1] > enemy.character.affinity[1])
		damage *= hero.character.affinity[1] - enemy.character.affinity[1];
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//wind bird
void card_9(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value * hero.character.quality * 0.5 + hero.character.max_mana / 40 / hero.character.quality;
	damage /= 1.5;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 10.0);
	if (hero.character.affinity[3] > enemy.character.affinity[3])
		damage *= hero.character.affinity[3] - enemy.character.affinity[3];
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//dark resist
void card_10(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card,  2);
}
//wind resis3
void card_11(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card, 3);
}
//water resist
void card_12(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card, 4);
}
//fire weakness
void card_13(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card, 5);
}
//wind weakness
void card_14(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card, 6);
}
//union elements
void card_15(Entity& hero, Entity& enemy, Card card)
{
	double damage = card.value * hero.character.quality * 0.5 + hero.character.max_mana / 40 / hero.character.quality * (hero.character.affinity[0] + hero.character.affinity[1] + hero.character.affinity[2] + hero.character.affinity[3]) / 3;
	damage /= 1.2;
	if (hero.character.quality > 3)
		damage /= (1.2 + hero.character.quality / 10.0);
	hero.character.mana -= card.mana;
	enemy.character.health -= damage;
}
//mana_bust
void card_16(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card, 7);
}
// health regeneration
void card_17(Entity& hero, Entity& enemy, Card card)
{
	hero.character.mana -= card.mana;
	EffectSet(hero, enemy, card, 8);
}
//change life
void card_18(Entity& hero, Entity& enemy, Card card)
{
	int temp = hero.character.health;
	hero.character.health = hero.character.max_health - temp;
}
//mana_life_cirlce
void card_19(Entity& hero, Entity& enemy, Card card)
{
	int temp = hero.character.health;
	if (hero.character.mana > hero.character.max_health)
		hero.character.health = hero.character.max_health, hero.character.mana = temp;
	else
		hero.character.health = hero.character.mana, hero.character.mana = temp;
}
//greate victim
void card_20(Entity& hero, Entity& enemy, Card card)
{
	hero.character.health -= hero.character.max_health / 2;
	hero.character.mana = 3 * hero.character.max_mana;
}

void cardUse(World world, Entity& hero, Entity& enemy)
{
		switch (world.deck[hero.anim_param.press - 1].card_num)
		{
		case 0:
			card_0(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 1:
			card_1(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 2:
			card_2(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 3:
			card_3(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 4:
			card_4(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 5:
			card_5(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 6:
			card_6(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 7:
			card_7(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 8:
			card_8(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 9:
			card_9(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 10:
			card_10(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 11:
			card_11(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 12:
			card_12(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 13:
			card_13(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 14:
			card_14(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 15:
			card_15(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 16:
			card_16(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 17:
			card_17(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 18:
			card_18(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 19:
			card_19(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
		case 20:
			card_20(hero, enemy, world.deck[hero.anim_param.press - 1]);
			break;
}
	hero.anim_param.bioclock.stime = 0;
	hero.anim_param.stage = 0;

	
}

void update(World& world, Entity& enemy, Entity& hero, int t)
{
	EffectReduse(hero, enemy);
	EffectReduse(enemy, hero);

	if (t % 10 == 1)
	{
		regenarateMana(hero);
	}

	if (hero.anim_param.bioclock.stime > hero.anim_param.bioclock.etime && hero.anim_param.press > 0)
		cardUse(world, hero, enemy);

	if (t % 2 == 1 && world.card_change.stime - 1 >= 0 && world.change_press)
	{
		world.card_change.stime -= 1;
	}
	if (world.card_change.stime == 0)
		world.change_press = false, world.card_change.stime = world.card_change.etime;

	enemy_attack_detect(world, enemy, hero);

	if (enemy.anim_param.bioclock.stime > enemy.anim_param.bioclock.etime)
	{
		enemy.anim_param.bioclock.stime = 0;
		enemy_attack(world, enemy, hero);
	}
	if (hero.character.health > hero.character.max_health && enemy.type_entity == 2)
		hero.character.health = hero.character.max_health;
	if (enemy.character.health <= 0)
	{
		world.stage = 1;
		enemy.character.health = 1;
		if (rand() % (25 - hero.character.luck) == 0 && world.crystal_state < 4)
			world.crystal_state += 1;
	}
	if (world.crystal_state == 4)
		world.stage = 3;
	if (hero.character.health <= 0)
	{
		world.stage = 2;
	}
}