#include "entity.h"
#include "world.h"
#include <cmath>
#include<ctime>

void set_default(Entity &entity)
{
	entity.anim_param.param_1 = 0;
	entity.anim_param.param_2 = 0;
	entity.anim_param.param_3 = 0;
	entity.anim_param.param_4 = 0;
	entity.anim_param.param_5 = 0;
	entity.anim_param.param_6 = 0;
	entity.anim_param.param_7 = 0;
	entity.anim_param.param_8 = 0;
}

void wizard_pas_anim(Animation& anim_param, short t)
{
	if (t / 30 % 2 == 0)
	{
		anim_param.param_1 -= 0.08; // left leg
		anim_param.param_2 -= 0.1; // right hand
		anim_param.param_3 -= 0.05; // head
		anim_param.param_7 += 0.01;
	}
	if (t / 30 % 2 == 1)
	{
		anim_param.param_1 += 0.08;
		anim_param.param_2 += 0.1;
		anim_param.param_3 += 0.05;
		anim_param.param_7 -= 0.01;
	}

	if (t / 360*4 % 2 == 0)
	{

		anim_param.param_8 += 0.25;
	}
	if (t / 360*4 % 2 == 1)
	{
		anim_param.param_8 -= 0.25;
	}

}
void wizard_attack_use_anim(Animation& anim_param, short t)
{
	if (anim_param.bioclock.stime < anim_param.bioclock.etime)
	{
		anim_param.param_6 += anim_param.bioclock.stime * 0.0023;
		anim_param.param_7 += std::cos(anim_param.bioclock.stime) * 0.15 - 0.02;
	}
	if(anim_param.bioclock.stime == anim_param.bioclock.etime)
	{
		anim_param.param_6 = 0;
		anim_param.param_7 = 0;
		anim_param.param_5 = 0;
	}
		
	anim_param.bioclock.stime += 1;

}
void wizard_self_use_anim(Animation& anim_param, short t)
{
	if (anim_param.bioclock.stime < anim_param.bioclock.etime)
	{
		if (t / 60 % 2 == 0)
		{
			anim_param.param_4 -= 0.1; // staff
			anim_param.param_5 -= 5.65;

		}
		if (t / 60 % 2 == 1)
		{
			anim_param.param_4 += 0.1;
			anim_param.param_5 -= 5.65;

		}
	}
	if (anim_param.bioclock.stime == anim_param.bioclock.etime)
	{
		anim_param.param_4 = 0;
		anim_param.param_5 = 0;
	}

	anim_param.bioclock.stime += 1;

}


void demon_pas_anim(Animation& anim_param, short t)
{
	if (t / 30 % 2 == 0)
	{
		anim_param.param_1 -= 0.35;
		anim_param.param_2 -= 0.35; 
		anim_param.param_3 += 0.005;
		anim_param.param_4 -= 0.15;

	}
	if (t / 30 % 2 == 1)
	{
		anim_param.param_1 += 0.35;
		anim_param.param_2 += 0.35;
		anim_param.param_3 -= 0.005;
		anim_param.param_4 += 0.15;
	}
}
void demon_attack_anim(Animation& anim_param, short t)
{
	if (anim_param.bioclock.stime < 50)
	{
		anim_param.param_8 += 0.02;
	}
	
	else if(anim_param.bioclock.stime >= 50 && anim_param.bioclock.stime < 100 && anim_param.bioclock.stime / 10 % 2 == 0)
	{
		anim_param.param_6 += 0.01;
		anim_param.param_7 -= 0.5;
	}

	else if (anim_param.bioclock.stime >= 50 && anim_param.bioclock.stime < 100 && anim_param.bioclock.stime / 10 % 5 == 1)
	{
		anim_param.param_6 -= 0.01;
		anim_param.param_7 += 0.5;

	}

	if (anim_param.bioclock.stime > 100)
	{
		anim_param.param_8 -= 0.02;
	}
	if (anim_param.bioclock.stime == anim_param.bioclock.etime)
	{
		anim_param.stage = 0;
		anim_param.param_8 = 0;
		anim_param.param_6 = 0;
		anim_param.param_7 = 0;
		//anim_param.bioclock.stime = 0;
	}



	anim_param.bioclock.stime += 1;
}


void water_pas_anim(Animation& anim_param, short t)
{
	if (t / 30 % 2 == 0)
	{
		anim_param.param_1 -= 0.35;
		anim_param.param_6 -= 0.3;
		anim_param.param_2 += 0.1;



	}
	if (t / 30 % 2 == 1)
	{
		anim_param.param_1 += 0.35;
		anim_param.param_6 += 0.3;
		anim_param.param_2 -= 0.1;
	}
	if (t / 60 % 2 == 0)
	{
		anim_param.param_5 -= 0.1;


	}
	if (t / 60 % 2 == 1)
	{
		anim_param.param_5 += 0.1;
	}

}
void water_attack_anim(Animation& anim_param, short t)
{
	if (anim_param.bioclock.stime < anim_param.bioclock.etime / 2)
	{
		anim_param.param_8 -= 0.09;
		anim_param.param_7 += 0.09;
	}

	else if (anim_param.bioclock.stime >= anim_param.bioclock.etime / 2 && anim_param.bioclock.stime < anim_param.bioclock.etime)
	{
		anim_param.param_8 -= 0.09;
		anim_param.param_7 -= 0.02;
	}

	if (anim_param.bioclock.stime == anim_param.bioclock.etime)
	{
		anim_param.stage = 0;
		anim_param.param_8 = 0;
		anim_param.param_7 = 0;
		//anim_param.bioclock.stime = 0;
	}
	anim_param.bioclock.stime += 1;
}

void dragon_pas_anim(Animation& anim_param, short t)
{
	if (t / 30 % 2 == 0)
	{
		anim_param.param_1 -= 0.15;
		anim_param.param_2 -= 0.3;
		anim_param.param_3 -= 0.1;



	}
	if (t / 30 % 2 == 1)
	{
		anim_param.param_1 += 0.15;
		anim_param.param_2 += 0.3;
		anim_param.param_3 += 0.1;
	}
	if (t / 60 % 2 == 0)
	{
		anim_param.param_4 -= 0.1;


	}
	if (t / 60 % 2 == 1)
	{
		anim_param.param_4 += 0.1;
	}

}
void dragon_attack_anim(Animation& anim_param, short t)
{
	if (anim_param.bioclock.stime < anim_param.bioclock.etime / 2)
	{
		anim_param.param_5 -= 0.16;
		anim_param.param_7 += 0.15;
	}

	else if (anim_param.bioclock.stime >= anim_param.bioclock.etime / 2 && anim_param.bioclock.stime < anim_param.bioclock.etime)
	{
		anim_param.param_5 -= 0.16;
		anim_param.param_7 -= 0.15;
	}

	if (anim_param.bioclock.stime == anim_param.bioclock.etime)
	{
		anim_param.stage = 0;
		anim_param.param_5 = 0;
		anim_param.param_7  = 0;
		//anim_param.bioclock.stime = 0;
	}



	anim_param.bioclock.stime += 1;
}

void hero_animation(Animation &anim_param, short t)
{
	switch (anim_param.stage)
	{
	case 0:
		wizard_pas_anim(anim_param, t);
		break;
	case 1:
		wizard_pas_anim(anim_param, t);
		wizard_attack_use_anim(anim_param, t);
		break;
	case 2:
		wizard_pas_anim(anim_param, t);
		wizard_self_use_anim(anim_param, t);
		break;

	}
	//anim_param.stage = 2;
}
void demon_animation(Animation& anim_param, short t)
{
	switch (anim_param.stage)
	{
	case 0:
		//hero_pas_anim(anim_param, t);
		demon_pas_anim(anim_param, t);
		break;
	case 1:
		demon_pas_anim(anim_param, t);
		demon_attack_anim(anim_param, t);
		break;

	}
}
void water_animation(Animation& anim_param, short t)
{
	switch (anim_param.stage)
	{
	case 0:
		//hero_pas_anim(anim_param, t);
		water_pas_anim(anim_param, t);
		break;
	case 1:
		//hero_pas_anim(anim_param, t);
		water_pas_anim(anim_param, t);
		water_attack_anim(anim_param, t);
		break;

	}
}
void dragon_animation(Animation& anim_param, short t)
{
	switch (anim_param.stage)
	{
	case 0:
		//hero_pas_anim(anim_param, t);
		dragon_pas_anim(anim_param, t);
		break;
	case 1:
		//hero_pas_anim(anim_param, t);
		dragon_pas_anim(anim_param, t);
		dragon_attack_anim(anim_param, t);
		break;

	}
}

void animation(World &world, Entity &enemy, Entity &hero, short t)
{
	enemy.animation(t);
	hero.animation(t);
}

