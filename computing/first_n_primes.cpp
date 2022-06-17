#include<iostream>
#include<vector>

using namespace std;

bool is_a_prime (const int &val, const vector<int> &primes) {
    bool b = true;
    if (val == 0 || val == 1)
        b = false;
    else {
        for (int i = 0; i < primes.size(); ++i) {
            if((val % primes[i]) == 0) {
                b = false;
                break;
            }
            else
            {}
        }
    }
    return b;
}

int main()
{
    int n = 0;
    cout << "Введите нужное число первых простых чисел" << "\n";
    cin >> n;
    vector<int> primes;
    int val = 0;
    while (primes.size() < n) {
        if (is_a_prime(val, primes))
            primes.push_back(val);
        else
        {}
        ++val;
    }
    cout << "Первые " << n << " простых чисел:" << "\n";
    for (int i : primes) {
        cout << i << "\n";
    }
    return 0;
}
