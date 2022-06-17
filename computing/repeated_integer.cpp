#include "std_lib_facilities.h"

int main()
{
    vector<int> vi; // вектор для хранения последовательности
    cout << "Введите через пробел последовательность чисел\n"
    << "Для завершения последовательности введите | \n";
    int n;  // число для ввода последовательности
    while (cin >> n) {
        vi.push_back(n);
    }
    int first_counter = 1;  //счетчик максимального числа вхождений
    int val = 0;
    for (int i : vi) {
        int second_counter = 0; //счетчик вхождений для проверки
        for (int j : vi) {
            if (i == j)
               ++second_counter;
            else
            {}
        }
        if (second_counter > first_counter) {
            first_counter = second_counter;
            val = i;
        }
        
        else
        {}
    }
    
    cout << "Число "<< val
    << " встречается "<< first_counter << " раз(а)\n";
    return 0;
}
