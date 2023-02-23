/**
 * 1. Преобразовать матрицу: элементы строки, в которой находится минимальный
элемент матрицы, заменить нулями.
*/

#include <iostream>
#include<array>
#include<ctime>
#include <fstream>

const int nrows = 10;
const int ncols = 10;

//FillMatrix. Заполняет двухмерный массив размерами nrows на ncols
//случайными целочисленными значениями от 0 до 29.
void FillMatrix(std::array<std::array<int, ncols>, nrows> &matr);

//PrintMatrix. Выводит матрицу в формате табллицы
void PrintMatrix(const std::array<std::array<int, ncols>, nrows> &matr);

//IndexOfMin. Возвращает индекс строки с минимальным элементом.
int IndexOfMin(const std::array<std::array<int, ncols>, nrows> &matr);

//RowToZero. Заменяет в строке матрицы соответствующей индексу каждое значение на 0.
void RowToZero(std::array<std::array<int, ncols>, nrows> &matr, int n);

//FileWrite. Сохраняет матрицу в табличном формате в файл result.txt
void FileWrite(const std::array<std::array<int, ncols>, nrows> &matr);

void FillMatrix(std::array<std::array<int, ncols>, nrows> &matr)
{
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++)
            matr[i][j] = rand() % 30;

}

void PrintMatrix(const std::array<std::array<int, ncols>, nrows> &matr)
{
    std::cout << "\t---<Matrix>---" << std::endl;
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++)
            std::cout << matr[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void FileWrite(const std::array<std::array<int, ncols>, nrows> &matr)
{
    std::ofstream outFile;
    outFile.open("result.txt");

    outFile << "\t---<Matrix>---" << std::endl;
    for(int i = 0; i < nrows; i++){
        for(int j = 0; j < ncols; j++)
            outFile << matr[i][j] << " ";
        outFile << std::endl;
    }
    outFile.close();
}

int IndexOfMin(const std::array<std::array<int, ncols>, nrows> &matr)
{
    int min = matr[0][0];
    int min_index = 0;
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++)
            if(matr[i][j] < min)
                min = matr[i][j], min_index = i;
    return min_index;
}

void RowToZero(std::array<std::array<int, ncols>, nrows> &matr, int n)
{
    for(int i = 0; i < nrows; i++)
        for(int j = 0; j < ncols; j++)
            if(i == n)
                matr[i][j] = 0;
}

int main()
{
    srand(time(0));
    std::array<std::array<int, ncols>, nrows> matrix;

    FillMatrix(matrix);
    PrintMatrix(matrix);

    RowToZero(matrix, IndexOfMin(matrix));

    std::cout << "Matrix after change" << std::endl;
    PrintMatrix(matrix);
    FileWrite(matrix);

    return 0;
}
