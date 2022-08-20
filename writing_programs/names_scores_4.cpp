#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Name_value {
public:
    string name;
    int val;
};

//------------------------------------------------------------------------------

bool check_name (const vector<Name_value> &names_scores,
                 const string &incoming_name)
{
    bool b = true;
    for (int i = 0; i < names_scores.size(); ++i) {
        if(names_scores[i].name == incoming_name)
        {
            b = false;
            break;
        }
        else
        {}
    }
    return b;
}

//------------------------------------------------------------------------------

int main()
{
    vector<Name_value> names_scores;
    cout << "Введите имя и количество баллов через пробел\n"
      << "Для завершения ввода введите NoName 0\n";
      int score = 0;
      string incoming_name = " ";
      while (cin >> incoming_name >> score) {
          if (incoming_name == "NoName" && score == 0) {
              break;
          }
          else if (check_name(names_scores, incoming_name)) {
              Name_value nv = {incoming_name, score};
              names_scores.push_back(nv);
          }
          else
              cout << "Имя " << incoming_name
              << " уже есть в списке\n";
      }
      
      for (int i = 0; i < names_scores.size(); ++i) {
          cout  << names_scores[i].name << " " << names_scores[i].val << "\n";
      }
      
    return 0;
}
