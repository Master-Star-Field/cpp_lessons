#include <GL/glut.h>
#include "golem_draw_lib.h"

void drawGolem()
{
    glTranslatef(x_position, y_position, 0);
    drawBody();
    drawHead();
    drawHand('l');
    drawHand('r');
}

void drawBody()
{
    //туловище
    glColor3ub(130,106,0);
    glBegin(GL_QUADS);
    glVertex2f((238), (272));
    glVertex2f((268), (386));
    glVertex2f((293), (379));
    glVertex2f((288), (282));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f((277), (304));
    glVertex2f((297), (354));
    glVertex2f((304), (352));
    glVertex2f((322), (329));
    glVertex2f((317), (291));
    glEnd();

    //летающий хвост

    glBegin(GL_POLYGON);
    glVertex2f((296), (367));
    glVertex2f((308), (370));
    glVertex2f((308), (425));
    glVertex2f((295), (419));
    glVertex2f((297), (367));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f((295), (419));
    glVertex2f((284), (410));
    glVertex2f((282), (390));
    glVertex2f((282), (411));
    glVertex2f((284), (390));
    glVertex2f((298), (395));
    glEnd();

    glColor3ub(65,77,77);
    glBegin(GL_TRIANGLES);
    glVertex2f((236), (265));
    glVertex2f((271), (318));
    glVertex2f((303), (273));

    glVertex2f((304), (327));
    glVertex2f((339), (315));
    glVertex2f((347), (213));

    glVertex2f((279), (300));
    glVertex2f((329), (204));
    glVertex2f((312), (314));

    glEnd();



    //туловище - левая рука
    glColor3ub(65,77,77);
    glBegin(GL_POLYGON);
    glVertex2f((163), (177));
    glVertex2f((228), (265));
    glVertex2f((196), (271));
    glVertex2f((172), (255));
    glVertex2f((149), (189));
    glVertex2f((164), (175));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f((159), (207));
    glVertex2f((172), (255));
    glVertex2f((144), (229));
    glVertex2f((136), (213));
    glVertex2f((143), (203));
    glVertex2f((156), (210));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f((146), (228));
    glVertex2f((132), (229));
    glVertex2f((130), (239));
    glVertex2f((155), (269));
    glVertex2f((169), (265));
    glVertex2f((170), (254));
    glEnd();


    //туловище - правая рука
    glColor3ub(65,77,77);
    glBegin(GL_POLYGON);
    glVertex2f((378), (162));
    glVertex2f((392), (172));
    glVertex2f((398), (178));
    glVertex2f((400), (195));
    glVertex2f((391), (236));
    glVertex2f((375), (252));
    glVertex2f((354), (249));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f((407), (184));
    glVertex2f((386), (210));
    glVertex2f((399), (249));
    glVertex2f((415), (239));
    glVertex2f((391), (236));
    glVertex2f((411), (211));
    glVertex2f((419), (189));
    glEnd();

    //воротник
    glColor3ub(99, 117, 117);
    glBegin(GL_TRIANGLE_FAN);
       glVertex2f((285), (152));
       glVertex2f((248), (82));
       glVertex2f((240), (0));
       glVertex2f((310), (64));
       glVertex2f((312), (42));
       glVertex2f((322), (33));
       glVertex2f((368), (125));
       glVertex2f((384), (122));
       glVertex2f((369), (217));
       glVertex2f((382), (225));
       glVertex2f((322), (291));
       glVertex2f((321), (306));
       glVertex2f((295), (274));
       glVertex2f((284), (290));
       glVertex2f((255), (269));
       glVertex2f((227), (284));
       glVertex2f((146), (156));
       glVertex2f((369), (217));
       glVertex2f((224), (80));
       glVertex2f((248), (82));

    glEnd();

    //воротник задняя часть
    glBegin(GL_TRIANGLES);
    glVertex2f((146), (156));
    glVertex2f((225), (80));
    glVertex2f((300), (170));
    glEnd();

    //тень на воротнике
    glColor3ub(78,92,93);
    glBegin(GL_TRIANGLES);
    glVertex2f((296), (260));
    glVertex2f((348), (184));
    glVertex2f((262), (175));

    glVertex2f((260), (104));
    glVertex2f((331), (122));
    glVertex2f((331), (204));

    glVertex2f((280), (253));
    glVertex2f((305), (185));
    glVertex2f((217), (191));

    glVertex2f((217), (191));
    glVertex2f((218), (147));
    glVertex2f((268), (189));

    glVertex2f((223), (160));
    glVertex2f((242), (134));
    glVertex2f((264), (174));
    glEnd();
}
void drawHand(char type)
{
    int change_x = 0;
    char k = -1;

    Color color_gloves;
    Color color_shadow;
    Color color_under;
    Color color_upper;
    Color color_shoulders;

    if(type == 'l')
    {
        color_shoulders = {63,75,75};
        color_gloves = {99,117,117};
        color_shadow =  {76,93,93};
        color_under = {255,156,1};
        color_upper = {254,215,0};

        k = 1;
        change_x = WIDTH_BOX;
    }else
    {
       color_shoulders = {63,75,75};
       color_gloves = {99,117,117};
       color_shadow =  {76,93,93};
       color_under = {130,106,0};
       color_upper = {179,143,3};
       change_x = 0;
       k = -1;
    }
    glPushMatrix();
    //glScalef(1, 1, 1); //масштаб матрицы
    //glTranslatef(0, 0, 0.0f); //перемещение матрицы

    //место стыка
    glColor3ub(color_shoulders.r,color_shoulders.g,color_shoulders.b);

    glBegin(GL_POLYGON);
    glVertex2f(-k*(88 - change_x), (306));
    glVertex2f(-k*(103 - change_x), (290));
    glVertex2f(-k*(139 - change_x), (317));
    glVertex2f(-k*(149 - change_x), (348));
    glVertex2f(-k*(145 - change_x), (375));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-k*(103 - change_x), (290));
    glVertex2f(-k*(110 - change_x), (262));
    glVertex2f(-k*(135 - change_x), (287));
    glVertex2f(-k*(139 - change_x), (317));
    glEnd();

    //когти
    glColor3ub(color_gloves.r,color_gloves.g,color_gloves.b);

    glBegin(GL_POLYGON);
    glVertex2f(-k*(167 - change_x), (353));
    glVertex2f(-k*(153 - change_x), (386));
    glVertex2f(-k*(171 - change_x), (446));
    glVertex2f(-k*(188 - change_x), (377));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-k*(175 - change_x), (405));
    glVertex2f(-k*(172 - change_x), (434));
    glVertex2f(-k*(200 - change_x), (451));
    glVertex2f(-k*(210 - change_x), (419));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-k*(175 - change_x), (405));
    glVertex2f(-k*(228 - change_x), (432));
    glVertex2f(-k*(237 - change_x), (415));
    glVertex2f(-k*(214 - change_x), (374));
    glVertex2f(-k*(188 - change_x), (377));
    glEnd();
//////////////////////
    glBegin(GL_POLYGON);
    glVertex2f(-k*(195 - change_x), (448));
    glVertex2f(-k*(203 - change_x), (436));
    glVertex2f(-k*(261 - change_x), (447));
    glVertex2f(-k*(267 - change_x), (492));
    glVertex2f(-k*(232 - change_x), (492));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-k*(243 - change_x), (467));
    glVertex2f(-k*(261 - change_x), (447));
    glVertex2f(-k*(272 - change_x), (430));
    glVertex2f(-k*(280 - change_x), (477));
    glEnd();

    //тень
    glColor3ub(color_shadow.r, color_shadow.g, color_shadow.b);
    glBegin(GL_POLYGON);
    glVertex2f(-k*(160 - change_x), (372));
    glVertex2f(-k*(137 - change_x), (425));
    glVertex2f(-k*(174 - change_x), (452));
    glVertex2f(-k*(179 - change_x), (400));
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-k*(165 - change_x), (434));
    glVertex2f(-k*(189 - change_x), (425));
    glVertex2f(-k*(242 - change_x), (481));
    glVertex2f(-k*(220 - change_x), (494));
    glEnd();

    //правая(для него) рука

    glColor3ub(color_under.r, color_under.g, color_under.b);

    glBegin(GL_QUADS);
    glVertex2f(-k*(51 - change_x), (151));
    glVertex2f(-k*(15 - change_x), (272));
    glVertex2f(-k*(45 - change_x), (436));
    glVertex2f(-k*(137 - change_x), (505));

    glVertex2f(-k*(142 - change_x), (485));
    glVertex2f(-k*(176 - change_x), (512));
    glVertex2f(-k*(220 - change_x), (512));
    glVertex2f(-k*(137 - change_x), (505));

    glVertex2f(-k*(254 - change_x), (513));
    glVertex2f(-k*(232 - change_x), (518));
    glVertex2f(-k*(150 - change_x), (458));
    glVertex2f(-k*(129 - change_x), (387));

    glVertex2f(-k*(173 - change_x), (455));
    glVertex2f(-k*(172 - change_x), (432));
    glVertex2f(-k*(250 - change_x), (516));
    glVertex2f(-k*(184 - change_x), (430));

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-k*(35 - change_x), (332));
    glVertex2f(-k*(11 - change_x), (327));
    glVertex2f(-k*(46 - change_x), (438));

    glVertex2f(-k*(92 - change_x), (470));
    glVertex2f(-k*(151 - change_x), (520));
    glVertex2f(-k*(142 - change_x), (485));

    glVertex2f(-k*(83 - change_x), (299));
    glVertex2f(-k*(164 - change_x), (397));
    glVertex2f(-k*(134 - change_x), (492));

    glVertex2f(-k*(175 - change_x), (511));
    glVertex2f(-k*(164 - change_x), (397));
    glVertex2f(-k*(135 - change_x), (485));
    glEnd();

    glColor3ub(color_upper.r, color_upper.g, color_upper.b);
    glBegin(GL_TRIANGLES);
    glVertex2f(-k*(25 - change_x), (349));
    glVertex2f(-k*(120 - change_x), (481));
    glVertex2f(-k*(47 - change_x), (424));

    glVertex2f(-k*(120 - change_x), (481));
    glVertex2f(-k*(47 - change_x), (424));
    glVertex2f(-k*(41 - change_x), (280));

    glVertex2f(-k*(41 - change_x), (280));
    glVertex2f(-k*(130 - change_x), (370));
    glVertex2f(-k*(120 - change_x), (481));

    glVertex2f(-k*(81 - change_x), (300));
    glVertex2f(-k*(75 - change_x), (394));
    glVertex2f(-k*(175 - change_x), (480));

    glVertex2f(-k*(113 - change_x), (469));
    glVertex2f(-k*(175 - change_x), (483));
    glVertex2f(-k*(129 - change_x), (420));

    glEnd();
    glBegin(GL_QUADS);
    glVertex2f(-k*(235 - change_x), (500));
    glVertex2f(-k*(238 - change_x), (512));
    glVertex2f(-k*(157 - change_x), (466));
    glVertex2f(-k*(146 - change_x), (437));
    glEnd();
    glPopMatrix();

}
void drawHead()
{
    //темная половина головы
    glColor3ub(178,143,2);
    glBegin(GL_TRIANGLES);
    glVertex2f((304), (119));
    glVertex2f((337), (150));
    glVertex2f((290), (196));

    glEnd();

    //тень на голове
    glColor3ub(130,106,1);
    glBegin(GL_TRIANGLES);
    glVertex2f((309), (112));
    glVertex2f((287), (126));
    glVertex2f((294), (161));

    glVertex2f((292), (152));
    glVertex2f((306), (141));
    glVertex2f((296), (176));

    glVertex2f((294), (184));
    glVertex2f((294), (208));
    glVertex2f((313), (177));

    glVertex2f((311), (176));
    glVertex2f((318), (190));
    glVertex2f((294), (208));
    glEnd();


    //оранжевая голова
    glColor3ub(254,156,0);
    glBegin(GL_TRIANGLE_FAN);
       glVertex2f((268), (149));
       glVertex2f((235), (51));
       glVertex2f((273), (107));
       glVertex2f((278), (89));
       glVertex2f((294), (91));
       glVertex2f((293), (155));
       glVertex2f((296), (153));
       glVertex2f((291), (225));
       glVertex2f((267), (211));
       glVertex2f((241), (169));
       glVertex2f((247), (168));
       glVertex2f((230), (118));
       glVertex2f((241), (123));
       glVertex2f((241), (106));
       glVertex2f((244), (106));
       glVertex2f((235), (51));

    glEnd();
    //желтая морда
    glColor3ub(255,216,0);
    glBegin(GL_TRIANGLES);
    glVertex2f((242), (72));
    glVertex2f((277), (119));
    glVertex2f((255), (154));
    glVertex2f((241), (106));
    glVertex2f((262), (106));
    glVertex2f((255), (154));
    glVertex2f((284), (107));
    glVertex2f((285), (169));
    glVertex2f((255), (150));

    glVertex2f((295), (163));
    glVertex2f((276), (173));
    glVertex2f((255), (143));

    glEnd();

    //глаз левый
    glColor3ub(62,51,38);
    glBegin(GL_TRIANGLES);
    glVertex2f((258), (156));
    glVertex2f((261), (167));
    glVertex2f((273), (176));

    glVertex2f((278), (174));
    glVertex2f((279), (182));
    glVertex2f((268), (181));

    glVertex2f((255), (167));
    glVertex2f((262), (167));
    glVertex2f((269), (181));

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((258), (171));
    glVertex2f((263), (164));
    glVertex2f((278), (180));
    glVertex2f((268), (186));

    glEnd();

    //второй глаз
    glBegin(GL_TRIANGLES);
    glVertex2f((301), (181));
    glVertex2f((305), (169));
    glVertex2f((307), (181));

    glVertex2f((316), (158));
    glVertex2f((316), (168));
    glVertex2f((305), (171));

    glVertex2f((308), (170));
    glVertex2f((311), (153));
    glVertex2f((315), (169));

    glEnd();

    glBegin(GL_QUADS);
    glVertex2f((304), (172));
    glVertex2f((306), (179));
    glVertex2f((316), (167));
    glVertex2f((312), (163));

    glEnd();
}
