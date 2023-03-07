/*
 * 4. Разработать программу для считывания данных о студентах из файла в следующем
формате: 1 строка Фамилия, 2 строка Средняя оценка, 3 строка Курс. Остальные
строки повторяют тройками эти данные для других студентов. Организовать
считывание данных из файла в массив структур. Организовать переменные для
хранения информации.
*/

#include <iostream>
#include <fstream>
#include <string>
#include<array>

const int N = 10;
struct Student {
    std::string lastName;
    double averageGrade;
    int course;
};

void showInfo(Student &student)
{
    std::cout <<student.lastName << std::endl;
    std::cout <<student.averageGrade << std::endl;
    std::cout <<student.course << std::endl;
    std::cout << std::endl;
}
int main() {
    std::array<Student, N> students;
    std::ifstream fin("D:/data_samples/students.txt");

    int count = 0;
    while (!fin.eof() && count < N) {
        std::getline(fin, students[count].lastName);
        fin >> students[count].averageGrade;
        fin >> students[count].course;
        fin.ignore();
        count++;
    }

    fin.close();

    std::cout << "Read " << count << " students from file." << std::endl;

    for(int i  = 0; i < count; i++)
        showInfo(students[i]);

    return 0;
}
