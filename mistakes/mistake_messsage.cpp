
#include "std_lib_facilities.h"


using namespace std;

class Bad_area {};

int area (int lenght, int widht) {
    if (lenght <= 0 || widht <= 0) throw Bad_area{};
    return lenght * widht;
}

int framed_area (int x, int y) {
    constexpr int frame_width = 2;
    return area(x - frame_width, y - frame_width);
}

int main()
{
    try {
        int x = 0;
        int y = 0;
        int z = 0;
        cin >> x >> y >> z;
        int area1 = area(x, y);
        int area2 = framed_area(4, z);
        int area3 = framed_area(y, z);
        double ratio = double(area1) / area3;
        cout << "площадь 1 равна " << area1 << "\n "
            << "площадь 2 равна " << area2 << "\n "
            << "площадь 3 равна " << area3 << "\n "
            << "отношение площади 1 к площади 3 равно "
            << ratio << "\n";
        return 0;
    }
    catch (Bad_area) {
        cout << "Неверный аргумент area()\n";
    }
}
