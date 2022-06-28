 
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
    cout << "cows " << cows << "\n"
    << "bulls " << bulls << "\n";
}

int main()
{
    constexpr int num_size = 4; // фиксируем размер вектора для игры быки и коровы
    vector<int> comp_nums{2, 4, 5, 9};
    vector<int> user_nums(num_size);
    cout << "Введите 4 числа\n";
    for (int i = 0; i < num_size; ++i){
        int n;
        cin >> n;
        if (unique_num(user_nums, n) == true)
            user_nums[i] = n;
        else
            error("повторять числа нельзя!\n");
    }
    bulls_cows(comp_nums, user_nums);
    
    return 0;
}
