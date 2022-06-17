#include "std_lib_facilities.h"

int main()
{
    vector<string> words; // вектор для хранения последовательности
    cout << "Введите через пробел последовательность слов\n"
    << "Для завершения последовательности введите | \n";
    string word = " ";  // строка для ввода последовательности
    while (cin >> word) {
        if (word == "|")
        break;
        else
        words.push_back(word);
    }
    int first_counter = 1;  //счетчик максимального числа вхождений
    string moda = " ";
    for (string s : words) {
        int second_counter = 0; //счетчик вхождений для проверки
        for (string ss : words) {
            if (s == ss)
               ++second_counter;
            else
            {}
        }
        if (second_counter > first_counter) {
            first_counter = second_counter;
            moda = s;
        }
        
        else
        {}
    }
    
    cout << "Слово "<< moda
    << " встречается "<< first_counter << " раз(а)\n";
    sort(words);
    cout << "Наименьшее " << words[0] << "\n";
    cout << "Набиольшее " << words[words.size() - 1] << "\n";
    return 0;
}
