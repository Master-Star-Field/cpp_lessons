//14. Дана строка. Если она начинается на 'abc', то заменить их на 'www', иначе добавить в конец строки 'zzz'.

#include <iostream>
#include<string>

void ReplaceStartChars(std::string &str)
{
    if(str.find("abc") == 0)
        str.replace(0, 3, "www");
    else
        str += "zzz";
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    ReplaceStartChars(str);
    std::cout << str;

    return 0;
}
