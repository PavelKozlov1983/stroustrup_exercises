#include "std_lib_facilities.h"

int main()
{
    double first_val = 0.0;
    double second_val = 0.0;
    double result_val = 0.0;
    char operation = ' ';
    cout << "Введите через пробел пару чисел и знак операции\n"
    << " + - * / и я посчитаю результат\n"
    << "Для выхода используйте символ |\n";
    while (operation != '|') {
        cin >> first_val >> second_val >> operation;
        if (first_val || first_val) {
        switch (operation) {
            case '|':
                break;
            case '+':
                result_val = first_val + second_val;
                cout << "Сумма чисел " << first_val
                << " и " << second_val << " равна "
                << result_val << "\n";
                break;
            case '-':
                result_val = first_val - second_val;
                cout << "Разность чисел " << first_val
                << " и " << second_val << " равна "
                << result_val << "\n";
                break;
            case '*':
                result_val = first_val * second_val;
                cout << "Произведение чисел " << first_val
                << " и " << second_val << " равнао "
                << result_val << "\n";
                break;
            case '/':
                result_val = first_val / second_val;
                cout << "Частное чисел " << first_val
                << " и " << second_val << " равно "
                << result_val << "\n";
                break;
            default:
                cout << "Введен неверный символ операции!\n";
                break;
        }
        }
        else
            break;
    }
    cout << "Пока!\n";
    return 0;
}
