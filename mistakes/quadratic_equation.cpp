#include "std_lib_facilities.h"

double discriminant (const double &a,                   //вычисление дискриминанта
                     const double &b, const double &c)
{
    return ((b * b) - (4.0 * a *  c));
}

void quadratic (const double &a,                     //вычисление  корней
                  const double &b, const double &c)
{
    double first_x = 0.0;
    double second_x = 0.0;
    if (a == 0) {
        first_x = (- c) / b;
        cout << "У уравнения только один корень "
        << first_x << "\n";
    }
    else {
        double d = discriminant(a, b, c);
        if (d < 0)
            error("У Уравнения нет корней\n");
        first_x = (-b - sqrt(d)) / (2.0 * a * c);
        second_x = (-b + sqrt(d)) / (2.0 * a * c);
    }
    if (first_x == second_x)
        cout << "У уравнения только один корень "
        << first_x << "\n";
    else
        cout << "Корни уравнения " << first_x
        << " и " << second_x << "\n";
}

int main()
{
    double a = 0.0;                     //коэф a
    double b = 0.0;                     //коэф b
    double c = 0.0;                     //коэф c
    cout << "Введите коэффиценты  a b и с из уравнения\n"
    << "a * x^2 + b * x + c = 0\n";
    cin >> a >> b >> c;
    if (a == 0 && b == 0)
        error("Уравнение не имеет смысла\n");
    quadratic (a, b, c);
    return 0;
}
