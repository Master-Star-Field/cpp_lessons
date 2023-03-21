/*
 * 4. Объявить сущность и описать её свойства. Объявить динамический массив
 * сущностей. Реализовать функцию, которая изменяет значения элемента (структура)
 * массива. Заполнить атрибуты числовыми и текстовыми значениями (диапазон
 * значений определить самостоятельно).
 * a. автомобиль
*/

#include <iostream>
#include <string>
#include <iomanip>

struct Car {
    std::string brand;   // марка
    std::string model;   // модель
    int yearOfIssue;     // год выпуска
    int mileage;         // пробег (км)
    int power;           // мощность (л.с.)
};

// функция для изменения свойств автомобиля
void modifyCar(Car &car) {
    car.yearOfIssue = rand() % 21 + 2000;  // год выпуска от 2000 до 2020
    car.mileage = rand() % 100001;  // пробег от 0 до 100000 км
    car.power = rand() % 201 + 100;  // мощность от 100 до 300 л.с.
}

// функция для заполнения данными структур в массиве
void FillCarsData(Car *cars, int size)
{
    for (int i = 0; i < size; i++) {
        (cars + i)->brand = "Brand " + std::to_string(i+1);
        (cars + i)->model = "Model " + std::to_string(i+1);
        (cars + i)->yearOfIssue = rand() % 21 + 2000;
        (cars + i)->mileage = rand() % 100001;
        (cars + i)->power = rand() % 201 + 100;
    }
}

// функция для красивого вывода массива
void printCars(Car *cars, int size) {
    std::cout << std::setw(10) << "Brand" << std::setw(10) << "Model"
              << std::setw(10) << "Year" << std::setw(10) << "Mileage"
              << std::setw(10) << "Power" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(10) << cars[i].brand
                  << std::setw(10) << cars[i].model
                  << std::setw(10) << cars[i].yearOfIssue
                  << std::setw(10) << cars[i].mileage
                  << std::setw(10) << cars[i].power << std::endl;
    }
}

int main() {
    int size;
    std::cout << "Enter the length of cars array: ";
    std::cin >> size;

    Car *cars = new Car[size];
    FillCarsData(cars, size);
    printCars(cars, size);

    int index;
    std::cout << "Enter the index of the car to modify: ";
    std::cin >> index;

    modifyCar(cars[index]);
    printCars(cars, size);

    delete[] cars;

    return 0;
}
