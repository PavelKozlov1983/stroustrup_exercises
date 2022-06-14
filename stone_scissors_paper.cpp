#include "std_lib_facilities.h"

int main()
{
    vector<int> comp_words = {3, 2, 1, 3, 1, 2, 1,
                              1, 3, 1, 2, 2, 3, 3};
    string users_word = " ";
    cout << "Введите камень, ножницы или бумага\n";
    for (int i : comp_words) {
        cin >> users_word;
        switch (i) {
            case 1:
                cout << "Камень\n";
                break;
            case 2:
                cout << "Ножницы\n";
                break;
            case 3:
                cout << "Бумага\n";
                break;
            default:
                break;
        }
    }
    return 0;
}
