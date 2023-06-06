#ifndef ANIMATION_LIB_H
#define ANIMATION_LIB_H

#include "world.h"
#include "entity.h"

void animation(World &world, Entity &enemy, Entity &hero, short t);

//���������� ��� ��������� �� 0
void set_default(Entity& entity);

//�������� �����
void wizard_pas_anim(Animation& anim_param, short t);
//�������� ���������� ����� �� ����
void wizard_self_use_anim(Animation& anim_param, short t);
//���������� ����� �� �����
void wizard_attack_use_anim(Animation& anim_param, short t);

//�������� ����� � ����� �����������
void demon_pas_anim(Animation& anim_param, short t);
void demon_attack_anim(Animation& anim_param, short t);

void water_pas_anim(Animation& anim_param, short t);
void water_attack_anim(Animation& anim_param, short t);

void dragon_pas_anim(Animation& anim_param, short t);
void dragon_attack_anim(Animation& anim_param, short t);

//����� �������� ����� Entity
void hero_animation(Animation& anim_param, short t);
void demon_animation(Animation& anim_param, short t);
void water_animation(Animation& anim_param, short t);
void dragon_animation(Animation& anim_param, short t);

//�������� ���������� �������� �������� �������� ����������� �������
void animation(World& world, Entity& enemy, Entity& hero, short t);

#endif // ANIMATION_LIB_H