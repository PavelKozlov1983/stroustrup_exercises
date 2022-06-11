#include "std_lib_facilities.h"

void dimension_name_check() {
    
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

bool check_dimension_name (string name) {
    if (name == "m" || name == "cm")
        return true;
    else if (name == "ft" || name == "inch")
        return true;
    else
        return false;
}

int main()
{
    double curr_val = 0.0;
    double max_val = 0.0;
    double min_val = 0.0;
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
                break;
            case false:
                cout << "Неподходящая единица измерения!\n";
                break;
        }
    }
    return 0;
}
