//19. В данной строке вставить после каждого символа 'a' символ 'b'.

#include <iostream>
#include<string>

std::string Bappend (std::string &str)
{
    std::string str1 = "";
    for(char x : str) //проходим в цикле по всем символам в строке
        if (x == 'a')
            str1 += "ab";
        else
            str1 += x;
    return str1;

}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::cout << Bappend(str);

    std::cin.get();
    return 0;
}
