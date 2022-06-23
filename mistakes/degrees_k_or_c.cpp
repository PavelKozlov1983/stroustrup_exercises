#include "std_lib_facilities.h"

double degree_c_or_k (double degree, char unit) {         // Преобразование градусов Цельсия
    if (unit == 'c') {                                    // в Фаренгейт или наоборот
        if (degree < - 273.15)
            error("Указанное значение ниже абсолютного минимума!/n");
        degree = 9.0 / 5 * degree + 32.0;
    }
    else if (unit == 'f') {
        if (degree < - 459.0)
            error("Указанное значение ниже абсолютного минимума!/n");
        degree = 5 / 9 * (degree - 32.0);
    }
    else
        error("Введена не та еденица измерения!/n");
    return degree;
}

int main()
{
    cout << "Введите  через пробел значение и единицу измерения  с или f\n";
    double degree = 0.0;                     // Входная переменная градусы
    char unit = ' ';                         // Входная переменная единицы иизмерения
    cin >> degree >> unit;                   // Ввод значения
    cout << degree_c_or_k(degree, unit) << "\n";          // Вывод результата
  return 0;
}
