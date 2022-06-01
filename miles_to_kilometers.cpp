#include "std_lib_facilities.h"

int main()
{
    const long double km_in_mile = 1609.0;
    long double miles = 0.0;
    cout << "Введите количество миль с точностью до сотых:\n";
    cin >> miles;
    if (miles < 0)
        simple_error("Некорректное значение!\n");
    long double kilometers = km_in_mile * miles;
    cout << kilometers << "км.\n";
    return 0;
}
