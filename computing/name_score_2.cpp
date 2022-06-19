
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
    cout << "Введите количество баллов для поиска студента\n"
    << "Для завершения поиска введите | 0\n";
    while (cin >> score) {
        int name_counter = 0;
        for (int i = 0; i < scores.size(); ++i) {
            if(scores[i] == score) {
                cout  << names[i] << " " << scores[i] << "\n";
                name_counter ++;
            }
            else
            {}
        }
        if (name_counter == 0)
            cout << "Баллы не найдены\n";
    }
    for (int i = 0; i < names.size(); ++i) {
        cout  << names[i] << " " << scores[i] << "\n";
    }
    
    return 0;
}
