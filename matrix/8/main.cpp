#include <iostream>
#include<array>

const int N = 5;
int main()
{
    std::array<std::array<int, N>, 2> data;

    for(int i =0; i < 2; i++)
        for(int j = 0; j < N; j++)
            if(i)
                data[i][j] = rand() % 3 + 1;
            else
                data[i][j] = rand() % 50 + 10;

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < N; j++)
            std::cout << data[i][j] << " ";
            std::cout << std::endl;
    }



    int max_index = -1;
    for(int i = 0; i < N; i++)
        if(data[0][i] > data[0][max_index] && data[1][i] == 3)
            max_index = i;
    std::cout << "Power: " << data[0][max_index] << std::endl;


    return 0;
}
