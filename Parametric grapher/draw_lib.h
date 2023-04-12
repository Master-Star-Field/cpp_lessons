#include <cmath>

#ifndef DRAW_LIB_H
#define DRAW_LIB_H

struct Color
{
    double r;
    double g;
    double b;
};

//размер экрана
const int WIDTH = 1000;
const int HEIGHT = 1000;

//диапозон t
const double first_value = 0;
const double last_value = 20 * M_PI;

//цвет графика функции
const Color CLINE = {1, 0, 0};

// раз во сколько миллисекунд будет обновляться график
const short TICKS = 7;

/* функции зависимости координат для гипоциклоиды 1
inline double x(double t){ return 24.8 * (cos(t) + cos(6.2 * t) / 6.2); }
inline double y(double t){ return 24.8 * (sin(t) - sin(6.2 * t)/6.2); }
*/

// функции зависимости для гипоциклоиды 2
inline double x(double t){ return 4.4 * (cos(t) + cos(1.1 * t)/1.1); }
inline double y(double t){ return 4.4 * (sin(t) - sin(1.1 * t) / 1.1); }

//возвращают наибольшее и наименьшие значения в диапазоне t соответствующих переменных
double max_y();
double min_y();

double max_x();
double min_x();

const double dx = (max_x()*1.1 - min_x());
const double dy = (max_y()*1.1 - min_y());

//рисует сетку
void drawGrid();

//отрисовывает график функций, в определенном диапазоне значений t
void drawLineFunction(double t, Color cline, short width);

#endif // DRAW_LIB_H
