#include "std_lib_facilities.h"
//------------------------------------------------------------------------------
void int_to_words (const int& number)
{
	int temp_digit = number;
	int rank = 1000; //старший разряд для вывода чисел
	cout << "В числе " << number << ":" << endl;
	cout << "тысяч " << temp_digit / rank << endl;
	temp_digit %= 1000;
	rank /= 10;
	cout << "сотен " << temp_digit / rank << endl;
	temp_digit %= 100;
	rank /= 10;
	cout << "десятков " << temp_digit / rank << endl;
	temp_digit %= 10;
	rank /= 10;
	cout << "единиц " << temp_digit / rank << endl;

}
//------------------------------------------------------------------------------

int string_to_int (const string& digits)
{
	int final_num = 0;
	for(int i = 0; i < digits.size(); ++i) {
		int temp_from_char = digits[i] - '0';
		if (temp_from_char < 10) {
			final_num *= 10;	//повышаем разряд числа каждую итерацию
			final_num += temp_from_char; //добавляем число меньшего разряда
		}
		else {
			 error("Введена не цифра");
			 return 1;
			 break;
		}
	}
	return final_num;
}

//------------------------------------------------------------------------------

int main()
try {
	string digits = " ";
	cin >> digits;
	vector<int> nums;
	int_to_words (string_to_int(digits));

}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
