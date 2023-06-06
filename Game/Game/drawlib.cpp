#include < GL/freeglut.h>
#include "drawlib.h"
#include<cmath>
#include<string>
#include "entity.h"
#include "structures_lib.h"
#include "world.h"
#include<ctime>

void RenderString(std::string str)
{
	glPushMatrix();
	glColor4d(1, 1, 1, 1);
	glRasterPos2f(0.2, 0.2);
	unsigned char chum[256];
	memcpy(chum, str.c_str(), str.size() + 1);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24,chum);
	glPopMatrix();
}	

Color makeColor(double r, double g, double b, double a)
{
	Color color = { r, g, b, a };
	return color;
}

void draw_water_elemental(Display display, Animation anim_param, double max_health, double health)
{
	Bar water_bar;
	setBar(water_bar, display.x - 0.08, display.y + 0.65,  2.6, 1, max_health, health, makeColor(1, 0, 0, 1));

	glPushMatrix();
		glTranslated(display.x, display.y, 0);
		glScaled(display.sc_w, display.sc_h, 1);
		glPushMatrix();
			glRotated(anim_param.param_1, 0, 0, 1);
				water_left_hand(display.visible);
		glPopMatrix();
		glPushMatrix();
				water_body(display.visible);
				glTranslated(0.02, 0.05, 0);
				glRotated(anim_param.param_2, 0, 0, 1);
				water_tail(display.visible);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.04, 0, 0);
			glRotated(anim_param.param_5, 0, 0, 1);
				water_head(display.visible);
				water_eye(display.visible);
				water_mouth(display.visible);
		glPopMatrix();

		glPushMatrix();
			glRotated(anim_param.param_6, 0, 0, 1);
				water_right_hand(display.visible);
		glPopMatrix();

	//water_hurt();
	glPopMatrix();
	water_bar.draw();
}
void draw_demon(Display display, Animation anim_param, double max_health, double health)
{
	Bar demon_bar;
	setBar(demon_bar, display.x - 0.14, display.y + 0.5 + anim_param.param_3, 2.6, 1, max_health, health, makeColor(1, 0, 0, 1));
	glPushMatrix();
			glTranslated(display.x, display.y + anim_param.param_3, 0);
			glScaled(display.sc_w, display.sc_h, 1);
			glPushMatrix();
				glScaled(-1, 1, 1);
				glPushMatrix();
				glRotated(anim_param.param_1, 0, 0, 1);
				demon_left_wing(display.visible);
				glPopMatrix();
					demon_left_hand(display.visible);
					demon_left_leg(display.visible);
			glPopMatrix();
			glPushMatrix();
			glRotated(anim_param.param_2, 0, 0, 1);
			demon_left_wing(display.visible);
			glPopMatrix();
			demon_left_hand(display.visible);
			demon_head(display.visible);
			glPushMatrix();
			glRotated(anim_param.param_4, 0, 0, 1);
			demon_eye(display.visible);
			glPopMatrix();
			demon_mouth(display.visible);
			demon_left_leg(display.visible);
	glPopMatrix();
	demon_bar.draw();
}
void draw_dragon(Display display, Animation anim_param, double max_health, double health)
{
	Bar dragon_bar;
	setBar(dragon_bar, display.x - 0.22, display.y - 0.8, 3.6, 1, max_health, health, makeColor(1, 0, 0, 1));
	glPushMatrix();
	glTranslated(display.x, display.y, 0);
	glScaled(display.sc_w, display.sc_h, 1);
		dragon_puzo(display.visible);
		dragon_telo(display.visible);
		glPushMatrix();
		glTranslated(-0.19, 0, 0);
		glRotated(anim_param.param_1, 0, 0, 1);
		dragon_golova(display.visible);
		glPopMatrix();


		glPushMatrix();
		glRotated(anim_param.param_2, 0, 0, 1);
		dragon_pravoe_krilo(display.visible);
		glPopMatrix();


		glPushMatrix();
		glRotated(anim_param.param_3, 0, 0, 1);
		dragon_levoe_krilo(display.visible);
		glPopMatrix();

		glPushMatrix();
		glRotated(anim_param.param_3, 0, 0, 1);
		dragon_xvoct(display.visible);
		glPopMatrix();

		dragon_nogi(display.visible);
	glPopMatrix();
	dragon_bar.draw();


}
void draw_wizard(Display display, Animation anim_param, double max_health, double health, double max_mana, double mana)
{
	Bar wizard_bar, mana_bar;
	//setHealthBar(wizard_bar, display.x - 0.35, display.y - 0.8, 3.6, 1, max_health, health);
	setBar(wizard_bar, display.x + -0.3, display.y + 0.965 , 4.5, 2, max_health, health, makeColor(1, 0, 0, 1));
	setBar(mana_bar, display.x + -0.3, display.y + 0.845, 4.5, 2, max_mana, mana, makeColor(91/255.0, 161 / 255.0, 231 / 255.0, 1));
	glPushMatrix();
	glTranslated(display.x, display.y, 0);
	glScaled(display.sc_w, display.sc_h, 1);
		wizard_mantia_zad(display.visible);
			glPushMatrix();
			glRotated(anim_param.param_1, 0, 0, 1);
				wizard_noga_levaya(display.visible); 
			glPopMatrix();
		wizard_noga_pravaya(display.visible); 
		wizard_mantia(display.visible);
			glPushMatrix();
			glRotated(anim_param.param_2, 0, 0, 1);
				wizard_pravaya_ruka(display.visible);
			glPopMatrix();
			glPushMatrix();
			glRotated(anim_param.param_3, 0, 0, 1);
				wizard_golova(display.visible);
				wizard_head(display.visible);
				wizard_eye(display.visible);
			glPopMatrix();
			glPushMatrix();
			glRotated(anim_param.param_4, 0, 0, 1);
			wizard_levaya_ruka(display.visible);
				glPushMatrix();
				glTranslated(anim_param.param_6 - 0.1, anim_param.param_7 + 0.35, 0);
					glRotated(anim_param.param_5, 0, 0, 1);
					double t = abs(sin(anim_param.param_8));
					Color3d color1{0 , 0, 0.2 + t}, color2{0.5,  0.2, 0.2 + t}, 
							color3{t, 0.5, 0.8}, color4{0.1 + t, 0.1 + t, 0.1 +t};
					wizard_fire(display.visible, color1, color2, color3, color4);
				//glTranslated(0, -0.7, 0);
				glPopMatrix();
			glPopMatrix();
		wizard_pravay_vorotnic(display.visible);
	glPopMatrix();
	wizard_bar.draw();
	mana_bar.draw();


}
void draw_desert(Position position)
{
	glPushMatrix();
		glTranslated(position.x, position.y, 0);
		glScaled(position.sc_w, position.sc_h, 1);
			desert();
	glPopMatrix();
}
void draw_cave(Position position)
{
	glPushMatrix();
		glTranslated(position.x, position.y, 0);
		glScaled(position.sc_w, position.sc_h, 1);
			background();
			background_fag();
			background_rocks();
			green_rocks();
			ground();
			caves_eye();
			caves_crystals();
	glPopMatrix();
} 
void draw_characteristic(Position position)
{
	glPushMatrix();
	glTranslated(position.x, position.y, 0);
	glScaled(position.sc_w, position.sc_h, 1);
	wood(1);
	flower(1);
	glPopMatrix();
}

//установка позиции окна характеристик
Position TabloParametrs()
{
	Position position;
	position.x = 0.08;
	position.y = 0.2;
	position.sc_w = 1;
	position.sc_h = 1.6;
	return position;
}


void draw_crystal(int stage)
{
	glPushMatrix();
	glTranslated(-0.27, -0.78, 0);
	glScaled(0.16, 0.16, 1);
	if (stage >= 0)
		draw_crystal_shablon(1);
	if (stage >= 1)
		draw_crystal_first(1);
	if (stage >= 2)
	draw_crystal_second(1);
	if (stage >= 3)
	draw_crystal_third(1);
	if (stage >= 4)
	{
		draw_crystal_fourth(1);
		draw_crystal_blicks(1);
	}

	glPopMatrix();

}

void draw_digitals(int n, double x, double y, Color3d color)
{
	std::string str = std::to_string(n);
	float k = 0.05;
	glPushMatrix();
	glColor4d(color.r, color.g, color.b, 1);
	glTranslated(x, y,0); 
	for (int i = 0; i < str.size(); i++)
	{
		//glTranslated(0.01 * i, 0, 0);
		switch (str[i])
		{
		case '0':
			glPushMatrix();
			glScaled(0.12, 0.15, 1);
			glTranslated(-1.9, 1.1, 0);
			draw_zero(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '1':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(0, 0, 0);
			draw_one(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '2':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-0.33, 0, 0);
			draw_two(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '3':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-0.83, 0, 0);
			draw_three(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '4':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-1.25, 0, 0);
			draw_four(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '5':
			glPushMatrix();
			glScaled(0.15, 0.14, 1);
			glTranslated(-1.7, 0, 0);
			draw_five(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '6':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-0.02, 1.1, 0);
			draw_six(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '7':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-0.42, 1.1, 0);
			draw_seven(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '8':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-0.836 , 1.1, 0);
			draw_eight(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		case '9':
			glPushMatrix();
			glScaled(0.15, 0.15, 1);
			glTranslated(-1.278, 1.1, 0);
			draw_nine(color);
			glPopMatrix();
			glTranslated(k, 0, 0);
			break;
		}
	}
	glPopMatrix();


}

void draw_new_level(World &world, Entity &hero)
{


	draw_characteristic(TabloParametrs());
	glPushMatrix();
	glScaled(0.25, 0.28, 1);
	glPushMatrix();
	glTranslated(1.4, 1.35, 0);
	draw_elem_dark(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.35, -0.6, 0);
	draw_elem_fire(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.4, 1.4, 0);
	draw_elem_water(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.35, -0.65, 0);
	draw_elem_wind(1);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	glScaled(0.1, 0.12, 1);
	glPushMatrix();
	glTranslated(-4.4, 4.2, 0);
	draw_heart(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-4.4, 2, 0); 
		draw_luck(1);
	

	glPopMatrix();
	glPushMatrix();
	glTranslated(-4.4, -0.2, 0);
	draw_mana(1);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-4.4, -2.4, 0);
	draw_magic_circle(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.15, -6.9, 0);
	glScaled(4, 4, 1);
	draw_button_normal(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.6, -6.9, 0);
	glScaled(4, 4, 1);
	draw_button_press(1);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 6.6, 0);
	glScaled(4, 4, 1);
	draw_point(1);
	glPopMatrix();

	glPopMatrix();
	Color3d color = { 0, 0, 0};

	draw_digitals(world.append[0] + hero.character.max_health, -0.1, 0.425, color); //health
	draw_digitals(world.append[1] + hero.character.luck, -0.1, 0.17, color); //luck
	draw_digitals(world.append[2] + hero.character.max_mana, -0.1, -0.105, color); //mana
	draw_digitals(world.append[3] + hero.character.quality, -0.1, -0.375, color); //quality
	draw_digitals(world.append[4] + hero.character.affinity[0], 0.55, 0.425, color); //water
	draw_digitals(world.append[5] + hero.character.affinity[1], 0.55, 0.17, color); //dark
	draw_digitals(world.append[6] + hero.character.affinity[2], 0.55, -0.105, color); //fire
	draw_digitals(world.append[7] + hero.character.affinity[3], 0.55, -0.375, color); //wind
	draw_digitals(world.points, 0.43, 0.685, color); //points
}

void draw_counter(World & world)
{
	Color3d color = { 1,1,1};
	glPushMatrix();
	glTranslated(-0.82, 0.435, 0);
	glScaled(0.55, 0.55, 1);
	draw_digitals(world.card_change.stime, -0.1, 0.425, color);
	glPopMatrix();

	if (world.right_press > 0 && world.card_change.stime <  world.card_change.etime)
	{
		glPushMatrix();
		glTranslated(world.deck[world.right_press - 1].position.x - 0.26, world.deck[world.right_press - 1].position.y, 0);
		RenderString(world.deck[world.right_press - 1].name);
		glPopMatrix();
	}

}

void draw_water_elem_attack(Animation anim_param, World world)
{
	glPushMatrix();
	glScaled(0.125, 0.125, 1);
	glTranslated(anim_param.param_8 + 0.5, 1, 0);
	water_sphere(anim_param.param_7);

	glPopMatrix();
}
void draw_demon_attack(Animation anim_param, World world)
{
	glPushMatrix();
	glScaled(1.1, 1.1, 1);
	da_fon(anim_param.param_8);
	glPopMatrix();

		glPushMatrix();
		glTranslated(anim_param.param_6, 0, 0);
		
			da_eye_1(anim_param.param_8);

		glPushMatrix();
		glRotated(anim_param.param_7, 0, 0, 1);
		da_eye_1z(anim_param.param_8);
		da_eye_1b(anim_param.param_8);

		glPopMatrix();
		glPopMatrix();

		if (world.level > 3)
		{
			glPushMatrix();
			glTranslated(anim_param.param_6, 0, 0);
			da_eye_2(anim_param.param_8);

			glPushMatrix();
			glRotated(anim_param.param_7, 0, 0, 1);
			da_eye_2z(anim_param.param_8);
			da_eye_2b(anim_param.param_8);

			glPopMatrix();
			glPopMatrix();
		}

		if (world.level > 5)
		{
			glPushMatrix();
			glTranslated(anim_param.param_6, 0, 0);
			da_eye_3(anim_param.param_8);

			glPushMatrix();
			glRotated(anim_param.param_7, 0, 0, 1);
			da_eye_3z(anim_param.param_8);
			da_eye_3b(anim_param.param_8);

			glPopMatrix();
			glPopMatrix();
		}



	glPopMatrix();

}
void draw_dragon_attack(Animation anim_param, World world)
{
	glPushMatrix();
	glScaled(0.25, 0.3, 1);
	glTranslated(anim_param.param_5+1, 1, 0);
	glRotated(-90, 0, 0, 1);
	wind_blust(anim_param.param_7);

	glPopMatrix();
}

void draw_victory()
{
	glPushMatrix();
	da_fon(0.6);
	glTranslated(0.5, -0.35, 0);
	glScaled(1.5, 1.5, 1);
	victory_shield();
	victory_table();
	victory_left_sword();
	victory_left_flag();
	glPushMatrix();
	glTranslated(-0.665, 0, 0);
	glScaled(-1, 1, 1);
		victory_left_sword();
		victory_left_flag();
	glPopMatrix();
	glPopMatrix();
}
void draw(World world, Entity entity_1, Entity entity_2)
{
	world.draw();
	if (world.stage == 0)
	{
		entity_2.draw();
		entity_1.draw();
		world.draw_cards(entity_1);
		draw_counter(world);
		draw_crystal(world.crystal_state);
	}
	if (world.stage == 1)
	{
		draw_new_level(world, entity_1);
	}
	if (world.stage == 2){
		fon();
		chart();
	}
	if (world.stage == 3)
	{
		draw_victory();
	}

	if(entity_2.anim_param.stage == 1 && world.stage == 0)
		switch (entity_2.type_entity)
		{
		case 1:
			draw_water_elem_attack(entity_2.anim_param, world);
			break;
		case 2:
			draw_demon_attack(entity_2.anim_param, world);
			break;
		case 3:
			draw_dragon_attack(entity_2.anim_param, world);
			break;
		}
}
