// 3. Составить алгоритм, находящий, сколько слов в тексте состоит из 6 символов.

#include <iostream>
#include<string>

int FoundNWord (std::string &str, int n)
{
    int temp = 0, count = 0;
    int found = str.find(" ", temp);

    while(found != -1)
    {
       found = str.find(" ", temp);

       if(found == -1)
           break;

       if (found - temp == n)
           temp = found + 1, ++count; // смещаем индекс начала поиска на первую букву нового слова
       else
           temp = found + 1;
    }
    if(str.length() - temp == n) // проверка последнего в строке слова
        count += 1;

    return count;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    std::cout << FoundNWord(str, 6);

    std::cin.get();
    return 0;
}
