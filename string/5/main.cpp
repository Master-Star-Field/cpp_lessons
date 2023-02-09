//5. Составить алгоритм, находящий, является ли частью данного слова слово “раз”. Ответ должен быть “да” или “нет”.

#include <iostream>
#include<string>

void FindSubStr(std::string &str, std::string substr)
{
    if(str.find(substr) != std::string::npos) //если find не возращает -1, т. е. подстрока найдена
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    FindSubStr(str, "ras");

    return 0;
}
