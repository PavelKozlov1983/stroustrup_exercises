#include "std_lib_facilities.h"

int main()
{
    vector<string> words_numbers {"zero", "one", "two", "three",
        "four", "five", "six", "seven", "eight", "nine", "0",
        "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    string s = " ";
    cin >> s;
    for (int i = 0; i < words_numbers.size(); ++i) {
        if (s == words_numbers[i] && i < 10) {
            cout << i << "\n";
            break;
        }
        else if (s == words_numbers[i] && i >= 10) {
            cout << words_numbers[i % 10] << "\n";
            break;
        }
      else
        cout << "Введено некорректное значение!\n";
    }
    
    return 0;
}
