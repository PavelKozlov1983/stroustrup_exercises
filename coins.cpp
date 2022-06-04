#include "std_lib_facilities.h"

void coins_naming (const int & coin_num, const string & coin_name)
{
    string ending_one = "овая монета";
    string ending_two_four = "овые монеты";
    string ending_others = "овых монет";
    cout << " У вас ";
    if (coin_num != 0)
    {
        cout << coin_num << coin_name;
    if (coin_num % 10 == 1 &&  coin_num != 11)
        cout << ending_one;
    else if (coin_num % 10 == 2 && coin_num != 12)
        cout << ending_two_four;
    else if (coin_num % 10 == 3 && coin_num != 13)
        cout << ending_two_four;
    else if (coin_num % 10 == 4 && coin_num != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
}

void cash_summary (const int &coins, const string &coin_name)
{
    if (coins % 10 == 1 &&  coins != 11)
        cout << coins << coin_name;
    else if (coins % 10 == 2 && coins != 12)
        cout << coins << coin_name <<"а ";
    else if (coins % 10 == 3 && coins != 13)
        cout << coins << coin_name <<"а ";
    else if (coins % 10 == 4 && coins != 14)
        cout << coins << coin_name <<"а ";
    else if (coins == 0)
        cout << "";
    else
        cout << coins << coin_name <<"ов ";
}

int main()
{
    int coin = 0;
    int nickel = 0;
    int dime = 0;
    int quarter = 0;
    int half_dollar = 0;
    int dollar = 0;
    int sum_of_coins = 0;
    string coin_str = " одноцент";
    string nickel_str = " пятицент";
    string dime_str = " десятицент";
    string quarter_str = " двадцатипятицент";
    string half_dollar_str = " пятидесятицент";
    string dollar_str = " доллар";
    
    cout << "Введите количество одноцентовых монет:\n";
    cin >> coin;
    sum_of_coins = coin;
    cout << "Введите количество пятицентовых монет:\n";
    cin >> nickel;
    sum_of_coins += nickel*5;
    cout << "Введите количество десятицентовых монет:\n";
    cin >> dime;
    sum_of_coins += dime*10;
    cout << "Введите количество двадцатипятицентовых монет:\n";
    cin >> quarter;
    sum_of_coins += quarter*25;
    cout << "Введите количество пятидесятицентовых монет:\n";
    cin >> half_dollar;
    sum_of_coins += half_dollar*50;
    cout << "Введите количество долларовых монет:\n";
    cin >> dollar;
    sum_of_coins += dollar*100;
    
    coins_naming(coin, coin_str);
    coins_naming(nickel, nickel_str);
    coins_naming(dime, dime_str);
    coins_naming(quarter, quarter_str);
    coins_naming(half_dollar, half_dollar_str);
    coins_naming(dollar, dollar_str);
    
    cout << "Общая стоимость ваших монет ";
    cash_summary(sum_of_coins / 100, dollar_str);
    cash_summary(sum_of_coins % 100, cent_str);
    cout << "\n";
    return 0;
}
