 
#include "std_lib_facilities.h"

 bool unique_num (const vector<int>& v, int n) // проверка уникальности чисел
{
     bool b = true;
      if (v.size() == 0)
          b = true;
     else
     {
         for (int i = 0; i < v.size(); ++i) {
             if (n == v[i])
                 b = false;
         }
     }
     return b;
 }
 
void bulls_cows(const vector<int>& comp_nums,  // сравнение значений в двух векторах
               const vector<int>& user_nums) {
    int cows = 0;
    int bulls = 0;
    for (int i = 0; i < comp_nums.size(); ++i) {
        for (int j = 0; j < user_nums.size(); ++j) {
            if (user_nums[j] == comp_nums[i] && j == i)
                ++bulls;
            else if (user_nums[j] == comp_nums[i] && j != i)
                ++cows;
        }
    }
    cout << "коров " << cows << "\n"
    << "быков " << bulls << "\n";
}

int main()
{
    constexpr int num_size = 4; // фиксируем размер вектора для игры быки и коровы
    bool choise = true;            // переменная для продолжения игры
    int user_num = 0;
    int comp_num = 0;
    while (choise) {
        vector<int> comp_nums(num_size);
        vector<int> user_nums(num_size);
        cout << "Введите 4 числа\n";
        for (int i = 0; i < num_size; ++i){     // заполняем вектор чисел пользователя
            cin >> user_num;
            if (unique_num(user_nums, user_num) == true) {
                user_nums[i] = user_num;
            }
            else
                error("повторять числа нельзя!\n");
        }
        srand(user_num);
        comp_num = randint(10);
        for (int i = 0; i < num_size; ++i) {     // заполняем вектор машины
            while (!unique_num(comp_nums, comp_num)) {
                comp_num = randint(9);
            }
            comp_nums[i] = comp_num;
        }
        
        bulls_cows(comp_nums, user_nums);
        
        cout <<" Сыграем еще? 1 - да, 0 - нет.\n";
        cin >> choise;
    }
    return 0;
}
