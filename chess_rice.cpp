#include "std_lib_facilities.h"


int main()
{
   
    int riсe = 1;
    int counter = 0;
    for (int i = 1; riсe < 1000000000; ++i) {
        riсe *= 2;
        counter = i;
    }
    cout << riсe << " зерен риса на "
    << counter << " клеток.\n";
    return 0;
}
