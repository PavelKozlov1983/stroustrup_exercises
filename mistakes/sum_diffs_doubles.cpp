
#include "std_lib_facilities.h"

vector<double> incoming_values () {
    vector<double> v;
    double val = 0.0;
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
        vector<double> values = incoming_values();
        vector<double> differences;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += values[i];
        };
        cout << "Разности соседних " << n - 1
        << " чисел равны\n";
        for (int i = 0; i < n - 1; ++i) {
            differences.push_back(values[i + 1] - values[i]);
        }
        for (auto d : differences)
            cout << d << "\n";
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
