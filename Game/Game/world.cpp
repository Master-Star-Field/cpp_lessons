#include "world.h"
#include "file_lib.h"
#include<array>
#include <GL/freeglut.h>
#include "structures_lib.h"
#include "drawlib.h"

void Card::set_default(int i)
{
	static std::array<Card, count_off_all> cards = load_config();
	card_type = cards[card_num].card_type;
	mana = cards[card_num].mana;
	name = cards[card_num].name;
	value = cards[card_num].value;
	attribute = cards[card_num].attribute;
	mouse_num = i;
	position.x += 0.155 * i;

}
void World::set_default()
{
	type_terra = rand() % 2;
	for (int i = 0; i < card_count; i++)
	{
		deck[i].card_num = rand() % count_off_all;
		deck[i].set_default(i);
	}
	//type_terra = 1;
	switch (type_terra) {
	case 0:
		position.sc_w = 1.5;
		position.sc_h = 1.2;
		position.x = -0.1;
		position.y = 0.1;

		break;

	case 1:
		position.sc_w = 1.2;
		position.sc_h = 1.3;
		position.x = -0.1;
		position.y = 0.1;

		break;
	}
}

void World::draw_cards(Entity entity_1)
{
	for (int i = 0; i < card_count; i++)
	{
		glPushMatrix();
		glTranslated(deck[i].position.x, deck[i].position.y, 0);
		glScaled(deck[i].position.sc_w, deck[i].position.sc_h, 1);
		under();
		middle();
		center();
		glPopMatrix();
	}
	if (entity_1.anim_param.stage == 1 or entity_1.anim_param.stage == 2)
	{
		glPushMatrix();
		glTranslated(deck[entity_1.anim_param.press - 1].position.x - 0.26, deck[entity_1.anim_param.press - 1].position.y, 0);
		RenderString(deck[entity_1.anim_param.press - 1].name);
		glPopMatrix();
	}

}

void World::draw()
{
	switch (type_terra)
	{
	case 0:
		draw_desert(position);
		break;
	case 1:
		draw_cave(position);
		break;

	}
}
