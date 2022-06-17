#include "std_lib_facilities.h"

int main()
{
    int picked_num = 100;
    char users_answer = ' ';
    int difference = 100;
    int counter = 0;
    cout << "Я буду угадывать число, а вы отвечайте:"
    << " + больше , - меньше, ! угадал\n"
    << "и нажимайте ввод.\n"
    << "Загадайте число от 0 до 100\n";
    while (users_answer != '!') {
        cout << "Это число  " << picked_num
        <<" ?\n";
        cin >> users_answer;
        switch (users_answer) {
            case '+':
                difference /= 2;
                picked_num += difference;
                break;
            case '-':
                difference /= 2;
                picked_num -= difference;
                break;
            case '!':
                break;
            default:
                cout << "Вы ввели не тот символ!\n";
                break;
        }
        ++counter;
    }
    cout << "Ура, это число " << picked_num << "!\n";
    cout << "Угадал за " << counter << " ходов!\n";
    return 0;
}
