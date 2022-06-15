#include "std_lib_facilities.h"

vector<int> eratosphene (vector<int> primes) {
    int i = 2;
    while(i < primes.size()) {
        if (primes[i] == 1) {
            int j = i * i;
            while (j < primes.size()) {
                primes[j] = 0;
                j += i;
            }
        }
        else
        {}
        ++i;
    }
    return primes;
}

int main()
{
    int max;
    cin >> max;
    vector<int> vals_f_primes(max, 1);
    vector<int> primes = eratosphene(vals_f_primes);
    for (int i = 2; i < primes.size(); ++i) {
        if (primes[i] == 1)
            cout << i << "\n";
        else
            {}
    }
    return 0;
}
