#include "std_lib_facilities.h"
#include<iostream>
#include<vector>

using namespace std;

bool check_name (const vector<string> &names, const string &name) {
    bool b = true;
    for (string s : names) {
        if(s == name)
        {
            b = false;
            break;
        }
        else
        {}
    }
    return b;
}

int main()
{
    vector<string> names;
    vector<int> scores;
    cout << "Введите имя и количество баллов через пробел\n"
    << "Для завершения ввода введите NoName 0\n";
    int score = 0;
    string name = " ";
    while (cin >> name >> score) {
        if (name == "NoName" && score == 0) {
            break;
        }
        else if (check_name(names, name)) {
            names.push_back(name);
            scores.push_back(score);
        }
        else
            cout << "Имя " << name
            << " уже есть в списке\n";
    }
    
    for (int i = 0; i < names.size(); ++i) {
        cout  << names[i] << " " << scores[i] << "\n";
    }
    
    return 0;
}
