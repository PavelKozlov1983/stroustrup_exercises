#include "std_lib_facilities.h"

int main()
{
    int val1 = 0, val2 = 0;
    cout << "Введите два целочисленных значения через пробел\n";
    cin >> val1 >> val2;
    if (val1 > val2)
        cout << val1 << " наибольшее значение\n"
        << val2 << " наименьшее значеие\n";
    else if (val1 == val2)
        cout << val1 << " равно "
        << val2 << "\n";
    else
        cout << val2 << " наибольшее значение\n"
        << val1 << " наименьшее значеие\n";
    cout << "Сумма " << val1 << " и "
    << val2 << " равна " << val1 + val2 << "\n";
    cout <<"Разность " << val1 << " и "
    << val2 << " равна " << val1 - val2 << "\n";
    cout <<"Произведение " << val1 << " и "
    << val2 << " равно " << val1 * val2 << "\n";
    cout <<"Частное " << val1 << " и "
    << val2 << " равно " << val1 / val2 << "\n";
    return 0;
}
