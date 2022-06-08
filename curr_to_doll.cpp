#include "std_lib_facilities.h"


int main()
{
    constexpr double rur = 0.016405;
    constexpr double cny = 0.15257;
    constexpr double byn = 0.38402;
    constexpr double eur = 1.07;
    constexpr double gpb = 1.26;
    double cash = 1.0;
    char unit = ' ';
    cout << "Введите сумму и валюту(r, c ,b, d)\n";
    cin >> cash >> unit;
    switch (unit){
        case 'r':
            cout << cash <<" руб. == " <<
            cash*rur << " долл.\n";
            break;
        case 'c':
            cout << cash <<" юан. == " <<
            cash*cny << " долл.\n";
            break;
        case 'b':
            cout << cash <<" блр. == " <<
            cash*byn << " долл.\n";
            break;
        case 'd':
            cout << cash << " долл.\n";
            break;
        case 'e':
            cout << cash <<" евро == " <<
            cash*eur << " долл.\n";
            break;
        case 'g':
            cout << cash <<" фунт. == " <<
            cash*gpb << " долл.\n";
            break;
        default:
            cout << "Я не знаю, что такое '" << unit << "'.\n";
            break;
    }
    
    return 0;
}
