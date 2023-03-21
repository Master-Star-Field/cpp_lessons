/*
 * 3. Объявить динамический массив типа float. Размер массива задаёт пользователь. Заполнить
 * массив случайными числами. Вывести на экран адреса и значения элементов
 * массива.
*/

#include <iostream>
#include<ctime>

int main()
{
    srand(time(0));
    float *p = nullptr;

    int nsize;
    std::cout << "please, enter count of massive elements: ";
    std::cin >> nsize;

    p = new float[nsize];

    for (int i = 0; i < nsize; i++)
    {
        p[i] = (float)(rand())/RAND_MAX*(20 + 10) - 10;
        std::cout << "(" << &p[i] << ") = " << p[i] << std::endl;

    }

    delete [] p;

    return 0;
}
