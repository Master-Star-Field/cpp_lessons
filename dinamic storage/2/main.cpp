/*
 * 2. Написать функцию для обмена значений переменных(типа float), указанных выше. Передача по
 * указателю. Выполнить программу по шагам и выписать в тетрадь адреса указателей
 * и величины переменных.
*/
#include <iostream>

void swap(float * pnum_1, float * pnum_2)
{
    std::cout << "Pointer info after start function swap" << std::endl;
    std::cout << "pfloat_num_1: " << "adress: " << &pnum_1 << " value: " << pnum_1 << " value for adress: " << *pnum_1 << std::endl;
    std::cout << "pfloat_num_2: " << "adress: " << &pnum_2 << " value: " << pnum_2 << " value for adress: " << *pnum_2 << std::endl;
    std::cout << std::endl;

    float temp = *pnum_1;
    *pnum_1 = *pnum_2;

    std::cout << "Pointer info after *pnum_1 = *pnum_2" << std::endl;
    std::cout << "pfloat_num_1: " << "adress: " << &pnum_1 << " value: " << pnum_1 << " value for adress: " << *pnum_1 << std::endl;
    std::cout << "pfloat_num_2: " << "adress: " << &pnum_2 << " value: " << pnum_2 << " value for adress: " << *pnum_2 << std::endl;
    std::cout << std::endl;

    *pnum_2 = temp;

    std::cout << "Pointer info after *pnum_2 = temp" << std::endl;
    std::cout << "pfloat_num_1: " << "adress: " << &pnum_1 << " value: " << pnum_1 << " value for adress: " << *pnum_1 << std::endl;
    std::cout << "pfloat_num_2: " << "adress: " << &pnum_2 << " value: " << pnum_2 << " value for adress: " << *pnum_2 << std::endl;
    std::cout << std::endl;
}

int main()
{
    float float_num_1 = 0.04;
    float float_num_2 = 0.02;

    float * pfloat_num_1 = &float_num_1;
    float * pfloat_num_2 = &float_num_2;

    std::cout << "Values of variables before function swap:\n"
              << "float_num_1: " <<float_num_1 << std::endl
              << "float_num_2: " <<float_num_2 << std::endl;
    std::cout << std::endl;

    swap(pfloat_num_1, pfloat_num_2);

    std::cout << "Values of variables after function swap:\n"
              << "float_num_1: " <<float_num_1 << std::endl
              << "float_num_2: " <<float_num_2 << std::endl ;

    return 0;
}
