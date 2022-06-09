#include "std_lib_facilities.h"

/*int square (int x) {
    int y = 0;
    for (int i = 0; i<x ; ++i) {
        y +=x;
    }
    return y;
}*/
int square (int x) {
    return x*x;
}
int main()
{
    cout << square(4) << "\n";
    return 0;
}
