/**
 * 11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц
(разрешается фиксированный размер матриц).
*/

#include <iostream>
#include<array>
#include<ctime>

const int N = 10;

//заполняет матрицу случайными значениями от 0 до 9
void FillMatrix(std::array<std::array<int, N>, N> &matr);
//выводит матрицу на экран
void PrintMatrix(const std::array<std::array<int, N>, N> &matr);
//производит сложение первой переданной матрицы со второй, результат записывается в первую переданную матрицу.
void Addition(std::array<std::array<int, N>, N> &A, const std::array<std::array<int, N>, N> &B);
//производит вычитание первой переданной матрицы со второй, результат записывается в первую переданную матрицу.
void Subtraction(std::array<std::array<int, N>, N> &A, const std::array<std::array<int, N>, N> &B);
//производит умножение первой переданной матрицы со второй, результат записывается в первую переданную матрицу.
void Increase(std::array<std::array<int, N>, N> &A, const std::array<std::array<int, N>, N> &B);
//производит транспонирование переданной матрицы.
void Transposition(std::array<std::array<int, N>, N> &A);

void FillMatrix(std::array<std::array<int, N>, N> &matr)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matr[i][j] = rand() % 10;

}

void PrintMatrix(const std::array<std::array<int, N>, N> &matr)
{
    std::cout << "   ---<Matrix>---" << std::endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            std::cout << matr[i][j] << " ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Addition(std::array<std::array<int, N>, N> &A, const std::array<std::array<int, N>, N> &B)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            A[i][j] += B[i][j];
}

void Subtraction(std::array<std::array<int, N>, N> &A, const std::array<std::array<int, N>, N> &B)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            A[i][j] -= B[i][j];
}

void Increase(std::array<std::array<int, N>, N> &A, const std::array<std::array<int, N>, N> &B)
{
   std::array<std::array<int, N>, N> C;

   for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
      {
          C[i][j] = 0;
          for(int k = 0; k < N; k++)
             C[i][j]+=A[i][k]*B[k][j];
      }
   A = C;
}

void Transposition(std::array<std::array<int, N>, N> &A)
{
    int temp = 0;
        for(int i = 0; i < 5; ++i)
        {
            for(int j = i; j < 5; ++j)
            {
                temp = A[i][j];
                A[i][j] = A[j][i];
                A[j][i] = temp;
            }
        }
}


int main()
{
    srand(time(0));
    std::array<std::array<int, N>, N> A;
    std::array<std::array<int, N>, N> B;

    FillMatrix(A);
    FillMatrix(B);

    PrintMatrix(A);
    PrintMatrix(B);

    Addition(A, B);
    PrintMatrix(A);

    Increase(A, B);
    PrintMatrix(A);

    Transposition(A);
    PrintMatrix(A);

    return 0;
}
