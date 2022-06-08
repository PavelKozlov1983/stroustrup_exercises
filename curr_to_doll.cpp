#include "std_lib_facilities.h"


int main()
{
    constexpr double rur = 0.016405;
    constexpr double cny = 0.15257;
    constexpr double byn = 0.38402;
    double cash = 1.0;
    char unit = ' ';
    cout << "Введите сумму и валюту(r, c ,b, d)\n";
    cin >> cash >> unit;
    if (unit == 'r')
        cout << cash <<" руб. == " <<
        cash*rur << " долл.\n";
    else if (unit == 'c')
        cout << cash <<" юан. == " <<
        cash*cny << " долл.\n";
    else if (unit == 'b')
        cout << cash <<" блр. == " <<
        cash*byn << " долл.\n";
    else if (unit == 'd')
        cout << cash << " долл.\n";
    else
        cout << "Я не знаю, что такое '" << unit << "'.\n";
    
    return 0;
}
