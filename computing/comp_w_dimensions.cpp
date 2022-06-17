
#include "std_lib_facilities.h"

bool check_dimension_name (string name) {
    if (name == "m" || name == "cm")
        return true;
    else if (name == "ft" || name == "inch")
        return true;
    else
        return false;
}

double val_converter (double val, string name) {
    double m = 100.0;
    double ft = 12;
    double inch = 2.54;
    if (name == "m")
        val *= m;
    else if (name == "cm")
    {}
    else if (name == "ft")
        val *= ft*inch;
    else if (name == "inch")
        val *= inch;
    return val;
}



int main()
{
    double curr_val = 0.0;
    double max_val = 0.0;
    double min_val = 0.0;
    double sum_val = 0.0;
    vector<double> values;
    int val_counter = 0;
    string dimension_name = "";
    cout << "Введите число и через пробел "
    << "единицу измерения(m, cm, inch, ft)\n";
    while (cin >> curr_val >> dimension_name) {
        switch (check_dimension_name(dimension_name)) {
            case true:
                curr_val = val_converter(curr_val, dimension_name);
                if (max_val == 0.0 && min_val == 0.0) {
                    max_val = curr_val;
                    min_val = curr_val;
                    cout << curr_val
                    << " см наибольшее из ранее введенных\n";
                }
                else if (curr_val > max_val) {
                    max_val = curr_val;
                    cout << curr_val
                    << " см наибольшее из ранее введенных\n";
                }
                else if (curr_val < min_val) {
                    min_val = curr_val;
                    cout << curr_val
                    << " см наименьшее из ранее введенных\n";
                }
                values.push_back(curr_val/100.0);
                sum_val += curr_val;
                ++val_counter;
                break;
            case false:
                cout << "Неподходящая единица измерения!\n";
                break;
        }
    }
    cout << "Сумма всех измерний равна " << sum_val/100.0 << " м.\n";
    cout << "Количество введенных измерений равно " << val_counter << "\n";
    sort(values);
    for(auto val : values) {
        cout << val << " м.\n";
    }
    return 0;
}
