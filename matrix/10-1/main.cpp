/**
 * 10. Реализовать вычисление матричных норм из списка выше (только для квадратных
матриц). По варианту L-норма
*/

#include <iostream>
#include<array>
#include<ctime>
#include<string>
#include<fstream>

const int N = 10;

//FillMatrix. Заполняет квадратную матрицу размера N
//случайными целочисленными значениями от 0 до 2.
void FillMatrix(std::array<std::array<int, N>, N> &matr);

//PrintMatrix. Выводит матрицу в формате таблицы
void PrintMatrix(const std::array<std::array<int, N>, N> &matr);


//FileWrite. Выводит переданную строку в файл result.txt
void FileWrite(const std::array<std::array<int, N>, N> &matr);

//суммирует все элементы столбца, переданного индекса
int SumCol(const std::array<std::array<int, N>, N> &matr, int col);


void FillMatrix(std::array<std::array<int, N>, N> &matr)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matr[i][j] = rand() % 3;

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

void FileWrite(const std::string str)
{
    std::ofstream outFile;
    outFile.open("result.txt");
    outFile << str << std::endl;
    outFile.close();
}

int SumCol(const std::array<std::array<int, N>, N> &matr, int col)
{
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += matr[i][col];
    return sum;
}


int main()
{
    srand(time(0));
    std::array<std::array<int, N>, N> matrix;

    FillMatrix(matrix);
    PrintMatrix(matrix);

    int max = 0;
    for(int i = 0; i < N; i++)
    {
        if (SumCol(matrix, i) > max)
            max = SumCol(matrix, i);
    }

    std::cout << "Max sum of colum is " << max << std::endl;
    FileWrite("L-norm of matrix is " + std::to_string(max));

    return 0;
}
