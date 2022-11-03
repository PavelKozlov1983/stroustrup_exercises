//#include "std_lib_facilities.h"

int main()
{
    int picked_num = 50;
    char users_answer = ' ';
    int difference = 50;
    int counter = 0;
    std::cout << "Я буду угадывать число, а вы отвечайте:"
    << " + больше , - меньше, ! угадал\n"
    << "и нажимайте ввод.\n"
    << "Загадайте число от 0 до 100\n";
    while (users_answer != '!') {
    	std::cout << "Это число  " << picked_num
        <<" ?\n";
    	std::cin >> users_answer;
        switch (users_answer) {
            case '+':
            	difference > 1 ? difference /= 2 : difference;
                picked_num += difference;
                break;
            case '-':
                difference > 1 ? difference /= 2 : difference;
                picked_num -= difference;
                break;
            case '!':
                break;
            default:
            	std::cout << "Вы ввели не тот символ!\n";
                break;
        }
        ++counter;
    }
    std::cout << "Ура, это число " << picked_num << "!\n";
    std::cout << "Угадал за " << counter << " ходов!\n";
    return 0;
}
