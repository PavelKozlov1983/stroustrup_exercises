#include "std_lib_facilities.h"

int main()
{
    int first_val = 0;
    int second_val = 0;
    while (cin >> first_val >> second_val) {
        if (first_val > second_val) {
            cout << "Наибольшее значение равно: "
            << first_val << "\n"
            << "Наименьшее значение равно: "
            << second_val << "\n";
        }
        else if (first_val == second_val)
            cout << "Числа равны " << first_val
            << "\n";
        else {
            cout << "Наибольшее значение равно: "
            << second_val << "\n"
            << "Наименьшее значение равно: "
            << first_val << "\n";
        }
    }
    return 0;
}
