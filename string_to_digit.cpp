#include "std_lib_facilities.h"

int main()
{
    string zero = "нуль", one = "один", two = "два",
    three = "три", four = "четыре", five = "пять",
    six = "шесть", seven = "семь", eight = "восемь",
    nine = "девять", incoming_number = " ";
    cout << "Введите цифру в виде слова:\n";
    cin >> incoming_number;
    if  (incoming_number == zero)
        cout << 0 << "\n";
    else if (incoming_number == one)
        cout << 1 << "\n";
    else if (incoming_number == two)
        cout << 2 << "\n";
    else if (incoming_number == three)
        cout << 3 << "\n";
    else if (incoming_number == four)
        cout << 4 << "\n";
    else if (incoming_number == five)
        cout << 5 << "\n";
    else if (incoming_number == six)
        cout << 6 << "\n";
    else if (incoming_number == seven)
        cout << 7 << "\n";
    else if (incoming_number == eight)
        cout << 8 << "\n";
    else if (incoming_number == nine)
        cout << 9 << "\n";
    else
        cout << "Я такого не знаю!\n";
    return 0;
}
