/*12. Задача *. Сосчитать количество чёрных пятен на белой шкуре. Шкуру представить
в виде 0 и 1 матрицы, где 0 - белый, а 1 - чёрный цвет.
*/

#include<iostream>
#include<array>
#include<ctime>
#include<string>
#include<fstream>

const int N =   5;
//Заполняет матрицу случайно нулями и единицами.
void FillMatr(std::array<std::array<int, N> , N> & matr);
//Выводит матрицу на экран.
void ViewMatr(std::array<std::array<int, N> , N> & matr);
//Рекурсивно проходит по всем ячейкам связанным с единичной, заменяя единичные на 0. Удаляет пятно со шкуры.
void DeleteSpots(std::array<std::array<int, N> , N> & matrix, int x, int y);
//Находит черный пиксель, вызывает для него DeleteSpots, проходит так по всей матрице, увеличивая счетчик находя черные пиксели.
int CountSpots(std::array<std::array<int, N> , N> & matrix);
//Вывод в файл матрицы, либо строки
void FileWrite(const std::array<std::array<int, N>, N> &matr);
void FileWrite(const std::string str);

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

void FileWrite(const std::string str)
{
    std::ofstream outFile;
    outFile.open("result.txt", std::ios::app);
    outFile << std::endl << str << std::endl;
    outFile.close();
}


void FillMatr(std::array<std::array<int, N> , N> & matr)
{
    for( int i =  0; i <  N; i++)
        for(int j =  0; j <    N; j++)
            matr[i][j] =  rand() % 2;
}

void ViewMatr(std::array<std::array<int, N> , N> & matr)
{
    for( int i =  0; i <  N; i++){
        std::cout <<    std::endl;
        for(int j =  0; j <    N; j++)
            std::cout <<    matr[i][j] <<    " ";
    }
}

void DeleteSpots(std::array<std::array<int, N> , N> & matrix, int x, int y)
{
    //проверка выходит ли переденное значение в рекурсивно вызванную функцию в допустимые размеры.
    if (x < 0 || y < 0  || x >= N  || y >= N || matrix[x][y] == 0) {
            return;
    }
        matrix[x][y] = 0;

        DeleteSpots(matrix, x - 1, y);
        DeleteSpots(matrix, x + 1, y);
        DeleteSpots(matrix, x, y - 1);
        DeleteSpots(matrix, x, y + 1);
}

int CountSpots(std::array<std::array<int, N> , N> & matrix)
{
        //переменная, хранящая кол-во островов:
        int numIsPots = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (matrix[i][j] == 1) {
                    numIsPots++;
                    DeleteSpots(matrix, i, j);
                }
            }
        }
        return numIsPots;
}
int main(){
   srand(time(0));
   std::array<std::array<int, N> , N>    matrix;

   FillMatr(matrix);
   ViewMatr(matrix);
   FileWrite(matrix);
   std::cout << std::endl;
   int count = CountSpots(matrix);
   std::cout << count << std::endl;

   FileWrite("Count of plots is " + std::to_string(count));
   return 0;
}
