
#include "std_lib_facilities.h"

vector<int> incoming_nums () {
    vector<int> v;
    int val = 0;
    while(cin >> val) {
        v.push_back(val);
    };
    return v;
}
int main()
{
    try
    {
        int n = 0;
        cout << "Введите число первых чисел, сумму которых нужно вычислить\n";
        cin >> n;
        if (!cin)
            error("Не число!\n");
        cout <<"Введите ряд целых чисел\n";
        vector<int> nums = incoming_nums();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        };
        cout << "Сумма " << n << " первых чисел равна " << sum << "\n";
        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << "\n";
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "unknown\n";
        keep_window_open();
        return 2;
    }
}
