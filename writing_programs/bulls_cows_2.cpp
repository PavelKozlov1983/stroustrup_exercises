#include "std_lib_facilities.h"

//------------------------------------------------------------------------------
// проверка уникальности букв
bool unique_letter (const vector<char>& letters, char letter)
{
	bool b = true;
	if (letters.size() == 0)
		return b;
	else {
		for (auto c : letters) {
			if (c == letter)
				b = false;
         	 }
	}
	return b;
 }
//------------------------------------------------------------------------------
// преобразыем случайные числа в буквы для вектора машины
char comp_letter (const int& incoming_num)
{
	int first_num_to_char = 97; //чиисло соответствует указателю на букву a
	char letter = int(first_num_to_char + incoming_num);
	return letter;
}
//------------------------------------------------------------------------------
// сравнение значений в двух векторах
void bulls_cows(const vector<char>& comp_letters,
               const vector<char>& user_letters) {
    int cows = 0;
    int bulls = 0;
    for (int i = 0; i < comp_letters.size(); ++i) {
        for (int j = 0; j < user_letters.size(); ++j) {
            if (user_letters[j] == comp_letters[i] && j == i)
                ++bulls;
            else if (user_letters[j] == comp_letters[i] && j != i)
                ++cows;
        }
    }
    cout << "коров " << cows << "\n"
    << "быков " << bulls << "\n";
}
//------------------------------------------------------------------------------

int main()
{
	const int number_of_chars = 4; // Максимальное  число участвующих символов
    bool choise = true;            // переменная для продолжения игры
    while (choise) {
    	char user_letter = ' ';
    	 char computed_letter = ' ';
    	vector<char> comp_letters;
    	vector<char> user_letters;
        cout << "Введите 4 строчные буквы\n";
        //заполняем вектор чисел пользователя
        while (user_letters.size() < 4) {
        	cin >> user_letter;
        	switch (unique_letter(user_letters, user_letter)) {
        	case true:
        		user_letters.push_back(user_letter);
        		break;
        	case false:
        		cout << "Буква " << user_letter << " уже была\n";
        		break;
        	}
        }
        while (comp_letters.size() < 4) {
                	computed_letter = comp_letter(randint(22));
                	switch (unique_letter(comp_letters, computed_letter)) {
                	case true:
                		comp_letters.push_back(computed_letter);
                		break;
                	case false:
                		break;
                	}
                }

        bulls_cows(comp_letters, user_letters);

        cout <<" Сыграем еще? 1 - да, 0 - нет.\n";
        cin >> choise;
    }
    return 0;
}
