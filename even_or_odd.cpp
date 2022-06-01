#include "std_lib_facilities.h"

int main()
{
    int number = 0;
    cout << "Введите целое число:\n";
    cin >> number;
    if (number % 2 == 0)
        cout << "Число " << number
        << " четное!\n";
    else
        cout << "Число " << number
        << " нечетное!\n";
    return 0;
}
