#include "std_lib_facilities.h"

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
    string ending_one = "овая монета";
    string ending_two_four = "овые монеты";
    string ending_others = "овых монет";
    
    cout << "Введите количество одноцентовых монет:\n";
    cin >> coin;
    sum_of_coins = coin;
    cout << "Введите количество пятицентовых монет:\n";
    cin >> nickel;
    sum_of_coins = nickel*5 + sum_of_coins;
    cout << "Введите количество десятицентовых монет:\n";
    cin >> dime;
    sum_of_coins = dime*10 + sum_of_coins;
    cout << "Введите количество двадцатипятицентовых монет:\n";
    cin >> quarter;
    sum_of_coins = quarter*25 + sum_of_coins;
    cout << "Введите количество пятидесятицентовых монет:\n";
    cin >> half_dollar;
    sum_of_coins = half_dollar*50 + sum_of_coins;
    cout << "Введите количество долларовых монет:\n";
    cin >> dollar;
    
    cout << " У вас ";
    if (coin != 0)
    {
        cout << coin << coin_str;
    if (coin % 10 == 1 &&  coin != 11)
        cout << ending_one;
    else if (coin % 10 == 2 && coin != 12)
        cout << ending_two_four;
    else if (coin % 10 == 3 && coin != 13)
        cout << ending_two_four;
    else if (coin % 10 == 4 && coin != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
    
    cout << " У вас ";
    if (nickel != 0)
    {
        cout << nickel << nickel_str;
    if (nickel % 10 == 1 &&  nickel != 11)
        cout << ending_one;
    else if (nickel % 10 == 2 && nickel != 12)
        cout << ending_two_four;
    else if (nickel % 10 == 3 && nickel != 13)
        cout << ending_two_four;
    else if (nickel % 10 == 4 && nickel != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
    
    cout << " У вас ";
    if (dime != 0)
    {
        cout << dime << dime_str;
    if (dime % 10 == 1 &&  dime != 11)
        cout << ending_one;
    else if (dime % 10 == 2 && dime != 12)
        cout << ending_two_four;
    else if (dime % 10 == 3 && dime != 13)
        cout << ending_two_four;
    else if (dime % 10 == 4 && dime != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
    
    cout << " У вас ";
    if (quarter != 0)
    {
        cout << quarter << quarter_str;
    if (quarter % 10 == 1 &&  quarter != 11)
        cout << ending_one;
    else if (quarter % 10 == 2 && quarter != 12)
        cout << ending_two_four;
    else if (quarter % 10 == 3 && quarter != 13)
        cout << ending_two_four;
    else if (quarter % 10 == 4 && quarter != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
    
    cout << " У вас ";
    if (half_dollar != 0)
    {
        cout << half_dollar << half_dollar_str;
    if (half_dollar % 10 == 1 &&  half_dollar != 11)
        cout << ending_one;
    else if (half_dollar % 10 == 2 && half_dollar != 12)
        cout << ending_two_four;
    else if (half_dollar % 10 == 3 && half_dollar != 13)
        cout << ending_two_four;
    else if (half_dollar % 10 == 4 && half_dollar != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
    
    cout << " У вас ";
    if (dollar != 0)
    {
        cout << dollar << dollar_str;
    if (dollar % 10 == 1 &&  dollar != 11)
        cout << ending_one;
    else if (dollar % 10 == 2 && dollar != 12)
        cout << ending_two_four;
    else if (dollar % 10 == 3 && dollar != 13)
        cout << ending_two_four;
    else if (dollar % 10 == 4 && dollar != 14)
        cout << ending_two_four;
    else
        cout << ending_others;
    }
    else
        cout << "";
    cout << "\n";
    
    sum_of_coins = dollar*100 + sum_of_coins;
    cout << "Общая стоимость ваших монет ";
    int dollars = sum_of_coins / 100;
    int coins =sum_of_coins % 100;
  
        if (dollars % 10 == 1 &&  dollars != 11)
            cout << dollars << " доллар ";
        else if (dollars % 10 == 2 && dollars != 12)
            cout << dollars << " доллара ";
        else if (dollars % 10 == 3 && dollars != 13)
            cout << dollars << " доллара ";
        else if (dollars % 10 == 4 && dollars != 14)
            cout << dollars << " доллара ";
        else if (dollars == 0)
            cout << "";
        else
            cout << dollars << " долларов ";

        if (coins % 10 == 1 &&  coins != 11)
            cout << coins << " цент";
        else if (coins % 10 == 2 && coins != 12)
            cout << coins << " цента";
        else if (coins % 10 == 3 && coins != 13)
            cout << coins << " цента";
        else if (coins % 10 == 4 && coins != 14)
            cout << coins << " цента";
        else
            cout << coins << " центов";
        
    
    cout << "\n";
    return 0;
}
