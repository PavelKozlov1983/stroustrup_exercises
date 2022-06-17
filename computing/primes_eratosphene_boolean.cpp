#include <vector>
#include <iostream>

using namespace std;

vector<bool> eratosphene (vector<bool> primes) {
    int i = 2;
    while(i < primes.size()) {
        if (primes[i]) {
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
    vector<bool> vals_f_primes(max, true);
    vector<bool> primes = eratosphene(vals_f_primes);
    for (int i = 2; i < primes.size(); ++i) {
        if (primes[i])
            cout << i << "\n";
        else
            {}
    }
    return 0;
}
