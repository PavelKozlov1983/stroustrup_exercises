//------------------------------------------------------------------------------
#include "std_lib_facilities.h"


//------------------------------------------------------------------------------
//рекурсия для вычисления факториала
int factorial (int number)
{
	if (number < 0)
	{
		cerr << "Нельзя использовать отрицательные числа!\n";
		return 2;
	}
	else if (number == 1 || number == 0)
		return 1;
	else
	return number * factorial(number - 1);
}

//------------------------------------------------------------------------------
//вычисление перестановок из n по k
int permutation (int n, int k)
{
	if (n < k)
	{
		cerr << "n не может быть меньше k!\n";
		return 2;
		}
	return factorial(n) / factorial(n-k);
}
//------------------------------------------------------------------------------
//вычисление сочетаний из n по k
int combinations (int n, int k)
{
	return permutation(n, k) / factorial(k);
}

//------------------------------------------------------------------------------
void enter_and_choose ()
{
	int n = 0;
	int k = 0;
	char c = ' ';
	cin >> n >> k >> c;
	switch (c)
	{
	case 'P':
		cout << permutation(n, k);
		break;
	case 'C':
		cout << combinations(n, k);
		break;
	default:
		cerr << "неверная команда!\n";
		break;
	}
}

//------------------------------------------------------------------------------


int main()
try
{
	cout << "Введите два числа n и k, \n"
		 << "'P' для вычисления числа комбинаций из n по k\n"
		 << "C для вычисления числа сочетаний из n по k\n";

	enter_and_choose();

}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n';
    keep_window_open("~1");
    return 1;
}
