#include "std_lib_facilities.h"

int main()
{
    string val1 = " ", val2 = " ", val3 = " ", val4 = " ";
    cout << "Введите через пробел три слова\n";
    cin >> val1 >> val2 >> val3;
    val4 = val1;
    if (val4 <= val2 &&  val4 < val3)
    {
     val4 = val2;
        if (val4 >= val3)
        {
            val2 = val3;
            val3 = val4;
        }
    }
    else if (val4 >= val2 && val4 > val3)
    {
        if (val2 < val3)
        {
            val1 = val2;
            val2 = val3;
            val3 = val4;
        }
        else
        {
            val1 = val3;
            val3 = val4;
        }
    }
    else if (val4 < val2 && val3 < val2)
    {
        if(val4 > val3)
        {
            val1 = val3;
            val3 = val2;
            val2 = val4;
        }
        else
        {
            val4 = val2;
            val2 = val3;
            val3 = val4;
        }
    }
    else if (val4 > val2 && val4 < val3)
    {
        val1 = val2;
        val2 = val4;
    }
    
    cout << val1 << ", " << val2
    << ", " << val3 << "\n";
    return 0;
}
