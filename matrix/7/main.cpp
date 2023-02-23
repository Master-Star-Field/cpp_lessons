/**
 * 7. Дана матрица. Элементы первой строки — количество осадков в соответствующий
день, второй строки — сила ветра в этот день. Найти, был ли в эти дни ураган?
(ураган — когда самый сильный ветер был в самый дождливый день).
*/

#include <iostream>
#include<array>
#include<ctime>
#include<string>
#include<fstream>

const int cols = 10;
const int rows = 2;

//FillMatrix. Заполняет двухмерный массив размерами rows на cols
//случайными целочисленными значениями. Первую строку значенями от 0 до 99, вторую от 10 до 59.
void FillMatrix(std::array<std::array<int, cols>, rows> &matr);

//PrintMatrix. Выводит матрицу в формате табллицы
void PrintMatrix(const std::array<std::array<int, cols>, rows> &matr);

//FileWrite. Сохраняет переданную строку в файл result.txt
void FileWriteRes(std::string str);

//BeStorm. Выводит на экран подтверждение, если максимальные по значению элементы строк
//имеют одинаковые индексы столбцов, и отрицание в противном случае.
void BeStorm(const std::array<std::array<int, cols>, rows> &matr);


void FillMatrix(std::array<std::array<int, cols>, rows> &matr)
{
    for(int i =0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(i)
                matr[i][j] = rand() % 100;
            else
                matr[i][j] = rand() % 50 + 10;

}

void PrintMatrix(const std::array<std::array<int, cols>, rows> &matr)
{
    std::cout << "\t---<Matrix>---" << std::endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            std::cout << matr[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void FileWriteRes(std::string str)
{
    std::ofstream outFile;
    outFile.open("result.txt");
    outFile << str << std::endl;
    outFile.close();
}

void BeStorm(const std::array<std::array<int, cols>, rows> &matr)
{
    int index_rain(0), index_wind(0);
    for(int i = 0; i < cols; i++){
        if(matr[0][i] > matr[0][index_rain])
            index_rain = i;
        if(matr[1][i] > matr[1][index_wind])
            index_wind = i;
    }
    std::string str1 = "Storm be on " + std::to_string(index_rain + 1) + " day\n";
    std::string str2 = "Weather not be storm\n";

    if(index_wind == index_rain)
        std::cout << str1, FileWriteRes(str1);
    else
        std::cout << str2, FileWriteRes(str2);
}

int main()
{
    srand(time(0));
    std::array<std::array<int, cols>, rows> matrix;

    FillMatrix(matrix);
    PrintMatrix(matrix);

    BeStorm(matrix);

    return 0;
}
