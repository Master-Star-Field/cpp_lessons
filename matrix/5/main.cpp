/**
 * 5. В квадратной матрице для каждой строки найти минимальный элемент и
переставить его с элементом, стоящим в этой строке на главной диагонали.
*/

#include <iostream>
#include<array>
#include<ctime>
#include<fstream>

const int N = 10;

//FillMatrix. Заполняет квадратную матрицу размера N
//случайными целочисленными значениями от 0 до 29.
void FillMatrix(std::array<std::array<int, N>, N> &matr);

//PrintMatrix. Выводит матрицу в формате таблицы
void PrintMatrix(const std::array<std::array<int, N>, N> &matr);

//IndexOfMin. Возвращает индекс минимального элемента в строке с индексом row.
int IndexOfMin(const std::array<std::array<int, N>, N> &matr, int row);

//FileWrite. Сохраняет матрицу в табличном формате в файл result.txt
void FileWrite(const std::array<std::array<int, N>, N> &matr);

void FillMatrix(std::array<std::array<int, N>, N> &matr)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matr[i][j] = rand() % 30;

}

void PrintMatrix(const std::array<std::array<int, N>, N> &matr)
{
    std::cout << "\t---<Matrix>---" << std::endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            std::cout << matr[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void FileWrite(const std::array<std::array<int, N>, N> &matr)
{
    std::ofstream outFile;
    outFile.open("result.txt");

    outFile << "\t---<Matrix>---" << std::endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            outFile << matr[i][j] << " ";
        outFile << std::endl;
    }
    outFile.close();
}

int IndexOfMin(const std::array<std::array<int, N>, N> &matr, int row)
{
    int min = matr[row][0];
    int min_index = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(row == i && matr[i][j] < min)
                min = matr[i][j], min_index = j;
    return min_index;
}


int main()
{
    srand(time(0));
    std::array<std::array<int, N>, N> matrix;

    FillMatrix(matrix);
    PrintMatrix(matrix);

    for(int i = 0; i < N; i++)
    {
        int temp = matrix[i][IndexOfMin(matrix, i)];
        matrix[i][IndexOfMin(matrix, i)] = matrix[i][i];
        matrix[i][i] = temp;
    }

    PrintMatrix(matrix);
    FileWrite(matrix);

    return 0;
}
