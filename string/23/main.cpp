//В текстовом файле, содержащем текст программы на языке С++, проверить соответствие открывающихся и закрывающихся фигурных скобок { и }.
//Результат проверки вывести на экран и записать в виде фразы в текстовый файл.
//Результат работы программы (вывод) поместить в отдельный текстовый файл (например, "out . txt " ), продублировав на экране.

#include<iostream>
#include<fstream>
#include<string>

int main()
{
    std::string file_name;
    std::cout << "Please enter name of file" << std::endl;
    std::getline(std::cin, file_name);

    std::fstream fin;
    fin.open(file_name); // открытие файла

    int counter_open = 0,
        counter_close = 0;

        char symvol;
        fin >> symvol; // считывание символа из файла

        while(fin)
        {
            if(symvol == '{') ++counter_open;

            if(symvol == '}')
            {
                ++counter_close;

                if (counter_close > counter_open) break; //если последовательность уже нарушена
            }
            fin >> symvol;
        }
            fin.close();

            std::ofstream fout;
            std::cout << "Please enter name of file and vave for it" << std::endl;
            std::getline(std::cin, file_name); //указание расположения выходного файла

            fout.open(file_name);  //создание выходного файла

            if(counter_open == 0 && counter_close == 0) //вывод в файл и консоль
                fout << "There are no curly brackets in the file" << std::endl,
                std::cout << "There are no curly brackets in the file" << std::endl;
            else
                if(counter_open == counter_close)
                    fout << "The opening brackets do match the closing ones" << std::endl,
                    std::cout << "The opening brackets == closing breckets" << std::endl;
                else
                    fout << "The opening brackets do not match the closing ones" << std::endl,
                    std::cout << "The opening brackets do not match the closing ones" << std::endl;
            fout.close();
   return 0;
}
