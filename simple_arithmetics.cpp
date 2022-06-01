#include "std_lib_facilities.h"

int main()
{
    char operation = ' ';
    double first_val = 0.0, second_val = 0.0;
    cout << "Введите символ операции и два числа:\n";
    cin >> operation >> first_val >> second_val;
    if (operation == '+')
    {
        cout << "Сумма чисел " << first_val << " и " << second_val
        << " равна " << first_val + second_val;
    }
    else if (operation == '-')
    {
        cout << "Разность чисел " << first_val << " и " << second_val
        << " равна " << first_val - second_val;
    }
    else if (operation == '*')
    {
        cout << "Произведение чисел " << first_val << " и " << second_val
        << " равно " << first_val * second_val;
    }
    else if (operation == '/')
    {
        if (second_val != 0)
        {
        cout << "Частное от деления чисел " << first_val << " и " << second_val
        << " равно " << first_val / second_val;
        }
        else
            simple_error("Делить на 0 нельзя!\n");
    }
    cout << "\n";
    return 0;
}
