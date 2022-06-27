
#include "std_lib_facilities.h"



int main()
{
    try {
        int n = 0;
        cin >> n;
        int val = 1;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (v.size() == 0)
                v.push_back(1);
            else if (val < 0)
                throw overflow_error("too big");
            else {
                v.push_back(val);
                val = (val + v[i - 1]);
            }
        }
        for (auto i : v) {
            cout << i << "\n";
        }
        return 0;
    }
    catch (overflow_error& e) {
        cerr << e.what() << "\n";
        keep_window_open();
        return 1;
    }
    catch (runtime_error& e) {
        cerr << e.what() << "\n";
        keep_window_open();
        return 2;
    }
}
