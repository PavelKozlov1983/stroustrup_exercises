#include "std_lib_facilities.h"


int main()
{
    vector<double> values;
    double median = 0.0;
    for (double val; cin >> val;) {
        values.push_back(val);
    }
    sort(values);
    if (values.size() % 2 != 0) {
        median = values[values.size() / 2];
    }
    else {
        median = values[values.size() / 2] +
        values[(values.size() / 2) - 1];
        median /= 2.0 ;
    }
    cout << median << "\n";
    return 0;
}
