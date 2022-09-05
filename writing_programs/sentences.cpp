

#include "std_lib_facilities.h"


//------------------------------------------------------------------------------
// 
bool sentence();

//------------------------------------------------------------------------------
bool conjunction() {
	string word;
	cin >> word;
	if (word == "but" || word == "and" || word == "or")
		return sentence();
	else
		return true;
}

//------------------------------------------------------------------------------
bool verb() {
	string word;
	cin >> word;
	if (word == "swim" || word == "fly")
		return conjunction();
	else
		return false;
}


//------------------------------------------------------------------------------

bool noun() {
	string word;
	cin >> word;
	if (word == "the" || word == "The") {
		cin >> word;
		if (word == "birds" || word == "fish")
			return verb();
	}
	else if (word == "birds")
		return verb();
	else if (word == "fish")
		return verb();
	else
	return false;
}


//------------------------------------------------------------------------------

bool sentence() {
	return noun();
}

//------------------------------------------------------------------------------

int main() {
	vector<string> vs;
	string s;
	cout << "Программа проверки предложений" << "\n"
			<< "Введите набор слов через пробел"  << "\n"
			<< "Для выхода введите #" << "\n";
	while(cin) {
		cin >> s;
		if(s != "#") {
			if (sentence())
				cout << "Да\n";
			else
				cout << "Нет\n";
		}
		else
			break;
	}

	return 0;
}

//------------------------------------------------------------------------------
