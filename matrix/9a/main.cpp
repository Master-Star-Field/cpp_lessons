/**
 * 9. Объявить, реализовать заполнение данными с клавиатуры ИЛИ из файла и вывести
на экран матрицу, описывающую следующие сущности. Предложите свой вариант.
 * a. Двумерное изображение. Изображение состоит из пикселей. Каждый пиксель
характеризуется яркостью цветовых каналов: красный, синий, зелёный.
*/

#include <iostream>
#include<array>
#include<ctime>
#include<fstream>

const int width = 50;
const int height = 50;

struct Pixel
{
    int r, g, b;
};

void FillMatrix(std::array<std::array<Pixel, width>, height> &pic)
{
    for(int i =0; i < width; i++)
        for(int j = 0; j < height; j++){
                pic[i][j].r = rand() % 255;
                pic[i][j].g = rand() % 255;
                pic[i][j].b = rand() % 255;
        }


}

int main()
{
    srand(time(0));
    std::array<std::array<Pixel, width>, height> matrix;

    FillMatrix(matrix);
    int i = 10, j = 10;

    std::cout << "Info of pixel" << std::endl;
    std::cout << "\t r: " << (int) matrix[i][j].r << std::endl;
    std::cout << "\t g: " << (int) matrix[i][j].g << std::endl;
    std::cout << "\t b: " << (int) matrix[i][j].b << std::endl;



    return 0;
}
