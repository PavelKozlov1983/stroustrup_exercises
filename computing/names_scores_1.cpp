
#include "std_lib_facilities.h"
#include<iostream>
#include<vector>

using namespace std;

int check_name (const vector<string> &names, const string &name) {
    int n = names.size();
    for (int i = 0; i < names.size(); ++i) {
        if(names[i] == name)
        {
            n = i;
            break;
        }
        else
        {}
    }
    return n;
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
        else if (check_name(names, name) == names.size()) {
            names.push_back(name);
            scores.push_back(score);
        }
        else
            cout << "Имя " << name
            << " уже есть в списке\n";
    }
    cout << "Введите имя для поиска количества баллов\n"
    << "Для завершения поиска введите NoName 0\n";
    while (cin >> name) {
        if (name == "NoName" && score == 0) {
            break;
        }
        else if (check_name(names, name) < names.size()) {
            cout << name << " "
            << scores[check_name(names, name)] << "\n";
        }
        
    }
    for (int i = 0; i < names.size(); ++i) {
        cout  << names[i] << " " << scores[i] << "\n";
    }
    
    return 0;
}
