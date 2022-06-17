#include "std_lib_facilities.h"

int main()
{
    double curr_val = 0.0;
    double max_val = 0.0;
    double min_val = 0.0;
    while (cin >> curr_val) {
        if (max_val == 0.0 && min_val == 0.0) {
            max_val = curr_val;
            min_val = curr_val;
            cout << curr_val
            << " наибольшее из ранее введенных\n";
        }
        else if (curr_val > max_val) {
            max_val = curr_val;
            cout << curr_val
            << " наибольшее из ранее введенных\n";
        }
        else if (curr_val < min_val) {
            min_val = curr_val;
            cout << curr_val
            << " наименьшее из ранее введенных\n";
        }
    }
    return 0;
}
