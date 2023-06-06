#ifndef STRUCTURES_LIB_H
#define STRUCTURES_LIB_H
#include"entity.h"

//hero - first mage 
void mage_hat(double visible);
void mage_head(double visible);
void mage_body(double visible);
void mage_mantia(double visible);
void mage_staff_hand(double visible);

//enemy0 - water_elemental
void water_hurt();
void water_body(double visible);
void water_head(double visible);
void water_eye(double visible);
void water_mouth(double visible);
void water_tail(double visible);
void water_right_hand(double visible);
void water_left_hand(double visible);

//enemy1 - demon
void demon_left_wing(double visible);
void demon_left_hand(double visible);
void demon_head(double visible);
void demon_eye(double visible);
void demon_mouth(double visible);
void demon_left_leg(double visible);

//enety2 - dragon

void dragon_puzo(double visible);
void dragon_telo(double visible);
void dragon_xvoct(double visible);
void dragon_golova(double visible);
void dragon_nogi(double visible);
void dragon_pravoe_krilo(double visible);
void dragon_levoe_krilo(double visible);

// hero 1 - wizard


void wizard_golova(double visible);
void wizard_head(double visible);
void wizard_eye(double visible);
void wizard_noga_levaya(double visible);
void wizard_noga_pravaya(double visible);
void wizard_mantia_zad(double visible);
void wizard_mantia(double visible);
void wizard_levaya_ruka(double visible);
void wizard_pravaya_ruka(double visible);
void wizard_pravay_vorotnic(double visible);
void wizard_fire(double visible, Color3d color1, Color3d color2, Color3d color3, Color3d color4);

void desert();

void background();
void background_fag();
void background_rocks();
void green_rocks();
void ground();
void caves_eye();
void caves_crystals();

//card
void under();
void middle();
void center();

//game_over
void fon();
void chart();

//meteor
void up_layer(Color3d c1, Color3d c2);
void down_layer(Color3d c1);

//character
void wood(double visible);
void flower(double visible);

//elements
void draw_elem_water(double visible);
void draw_elem_wind(double visible);
void draw_elem_dark(double visible);
void draw_elem_fire(double visible);

//characters
void draw_heart(double visible);
void draw_luck(double visible);
void draw_mana(double visible);
void draw_magic_circle(double visible);

void draw_crystal_first(double visible);
void draw_crystal_second(double  visible);
void draw_crystal_third(double visible);
void draw_crystal_fourth(double visible);
void draw_crystal_blicks(double visible);
void draw_crystal_shablon(double visible);
void draw_crystal_shadow(double visible);

void draw_button_normal(double visible);
void draw_button_press(double visible);
void draw_point(double visible);

void draw_zero(Color3d color);
void draw_one(Color3d color);
void draw_two(Color3d color);
void draw_three(Color3d color);
void draw_four(Color3d color);
void draw_five(Color3d color);
void draw_six(Color3d color);
void draw_seven(Color3d color);
void draw_eight(Color3d color);
void draw_nine(Color3d color);

//enemy attacks

void da_fon(double visible);
void da_eye_1(double visible);
void da_eye_1z(double visible);
void da_eye_1b(double visible);
void da_eye_2(double visible);
void da_eye_2z(double visible);
void da_eye_2b(double visible);
void da_eye_3(double visible);
void da_eye_3z(double visible);
void da_eye_3b(double visible);

void wind_blust(double visible);

void water_sphere(double visible);

//victory
void victory_shield();
void victory_table();
void victory_left_sword();
void victory_left_flag();

#endif // STRUCTURES_LIB_H