#include "std_lib_facilities.h"

int main()
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    double first_x = 0.0;
    double second_x = 0.0;
    cout << "Введите коэффиценты  a b и с из уравнения\n"
    << "a * x^2 + b * x + c = 0\n";
    cin >> a >> b >> c;
    if (a == 0 && b == 0)
        cout << "Уравнение не имеет смысла\n";
    else if (a == 0)
    {
        first_x = (- c) / b;
        cout << "У уравнения только один корень "
        << first_x << "\n";
    }
    else
    {
        double d = (b * b) - (4.0 * a * c); //вычисляем дискриминант
        if (d < 0)
            cout << "У Уравнения нет корней\n";
        else if(d == 0)
        {
            first_x = -b / (2.0 * a * c);
            cout << "У уравнения только один корень "
            << first_x << "\n";
        }
        else
        {
            first_x = (-b - sqrt(d)) / (2.0 * a * c);
            second_x = (-b + sqrt(d)) / (2.0 * a * c);
            cout << "Корни уравнения " << first_x
            << " и " << second_x << "\n";
        }
    }

    return 0;
}
