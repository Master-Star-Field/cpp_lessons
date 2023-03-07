/*
 * 3. Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
считывать из файла in.txt. Результат записывать в текстовый файл out.txt. Формат
записи данных:
x0, y(x0)
x1, y(x1)
x2, y(x2)
и т.д.
a. 𝑦 = 𝑥 + 2𝑥 + 3𝑥 + ⋯ + Ч𝑥
*/

#include <iostream>
#include <fstream>
#include <cmath>

int main() {
    double x0, x1, step, C; // параметр Ч - это C
    std::ifstream f("in.txt");
    f >> x0 >> x1 >> step >> C;
    f.close();

    std::ofstream fout("out.txt");
    for (double x = x0; x <= x1; x += step) {
        double y = 0;
        for (int i = 1; i <= C; i++) {
            y += i * x;
        }
        fout << x << ", " << y << std::endl;
    }
    fout.close();

    std::cout << "Tabulling be save in out.txt" << std::endl;

    return 0;
}
