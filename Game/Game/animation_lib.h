#ifndef ANIMATION_LIB_H
#define ANIMATION_LIB_H

#include "world.h"
#include "entity.h"

void animation(World &world, Entity &enemy, Entity &hero, short t);

//сбрасывает все параметры на 0
void set_default(Entity& entity);

//анимация покоя
void wizard_pas_anim(Animation& anim_param, short t);
//анимация применения карты на себя
void wizard_self_use_anim(Animation& anim_param, short t);
//применение карты на врага
void wizard_attack_use_anim(Animation& anim_param, short t);

//анимации покоя и атаки противников
void demon_pas_anim(Animation& anim_param, short t);
void demon_attack_anim(Animation& anim_param, short t);

void water_pas_anim(Animation& anim_param, short t);
void water_attack_anim(Animation& anim_param, short t);

void dragon_pas_anim(Animation& anim_param, short t);
void dragon_attack_anim(Animation& anim_param, short t);

//выбор анимации атаки Entity
void hero_animation(Animation& anim_param, short t);
void demon_animation(Animation& anim_param, short t);
void water_animation(Animation& anim_param, short t);
void dragon_animation(Animation& anim_param, short t);

//изменяеи переменные анимации принимая значения глобального таймера
void animation(World& world, Entity& enemy, Entity& hero, short t);

#endif // ANIMATION_LIB_H