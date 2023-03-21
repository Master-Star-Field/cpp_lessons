/*
 * 1. Объявить указатели на две переменные указанного типа. Используя указатели
 * произвести операции сложения и вычитания над переменными. Вывести адреса
 * указателей. Типы переменных указаны по таблице float
*/

#include <iostream>

int main()
{
    float float_num_1 = 0.04;
    float float_num_2 = 0.02;

    float * pfloat_num_1 = &float_num_1;
    float * pfloat_num_2 = &float_num_2;

    float addition = *pfloat_num_1 + *pfloat_num_2;
    float subtraction = *pfloat_num_1 - *pfloat_num_2;

    std::cout << "Sum operation \n"
              << "float_num_1 + float_num_2 = " << addition << std::endl;

    std::cout << std::endl;

    std::cout << "Subtraction operation \n"
              << "float_num_1 + float_num_2 = " << subtraction << std::endl;

    std::cout << std::endl;

    std::cout << "Pointer addresses: \n"
              << "pfloat_num_1: " << pfloat_num_1 << std::endl
              << "pfloat_num_2: " << pfloat_num_2 << std::endl;

    return 0;
}
