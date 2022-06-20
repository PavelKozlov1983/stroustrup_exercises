
#include "std_lib_facilities.h"


using namespace std;

int area (int lenght, int widht) {
    if (lenght <= 0 || widht <= 0)
        return -1;
    return lenght * widht;
}

int framed_area (int x, int y) {
    constexpr int frame_width = 2;
    if (x - frame_width <= 0 || y - frame_width <= 0)
        error(" Неположительный аргумент функции area()"
              "при вызове из функции framed_area()");
    return area(x - frame_width, y - frame_width);
}

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    cin >> x >> y >> z;
    int area1 = area(x, y);
    if (area1 <= 0)
        error("Неположительная яплощадь");
    int area2 = framed_area(4, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1) / area3;
    cout << "площадь 1 равна " << area1 << "\n "
    << "площадь 2 равна " << area2 << "\n "
    << "площадь 3 равна " << area3 << "\n "
    << "отношение площади 1 к площади 3 равно " << ratio << "\n ";
    
    return 0;
}
