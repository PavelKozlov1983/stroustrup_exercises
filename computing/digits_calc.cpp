
#include "std_lib_facilities.h"

int word_to_number (const string &s) {
    int n = 10;
    vector<string> words_numbers {"нуль", "один", "два", "три",
        "четыре", "пять", "шесть", "семь", "восемь", "девять", "0",
        "1", "2", "3", "4", "5", "6", "7", "8", "9", "ноль"};
    for (int i = 0; i < words_numbers.size(); ++i) {
        if (s == words_numbers[i]) {
            n = i % 10;
            break;
        }
    }
    return n;
}


int main()
{
    double first_val = 0.0;
    double second_val = 0.0;
    double result_val = 0.0;
    string first_str = " ";
    string second_str = " ";
    char operation = ' ';
    cout << "Введите через пробел пару цифр и знак операции\n"
    << " + - * / и я посчитаю результат\n"
    << "Для выхода используйте символ | вместо операции\n";
    while (operation != '|') {
        cin >> first_str >> second_str >> operation;
        first_val = word_to_number(first_str);
        second_val = word_to_number(second_str);
        if (first_val < 10.0 && second_val < 10.0) {
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
                if (second_val == 0) {
                    cout << "Делить на 0 нельзя!\n";
                    break;
                }
                else {
                result_val = first_val / second_val;
                cout << "Частное чисел " << first_val
                << " и " << second_val << " равно "
                << result_val << "\n";
                break;
                }
            default:
                cout << "Введен неверный символ операции!\n";
                break;
        }
        }
        else {
            cout << "Введена не цифра в первом или втором аргументе\n";
            break;
        }
    }
    cout << "Пока!\n";
    return 0;
}
