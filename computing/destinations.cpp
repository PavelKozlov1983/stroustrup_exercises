#include "std_lib_facilities.h"


int main()
{
    vector<double> destinations;
    double avg_dest = 0.0;
    double sum_dest = 0.0;
    double dest_min = 0.0;
    double dest_max = 0.0;
    cout << "Введите растояние между двумя точками \n";
    for (double dest; cin >> dest;) {
        destinations.push_back(dest);
        sum_dest += dest;
    }
    avg_dest = sum_dest / destinations.size();
    sort(destinations);
    dest_min = destinations[0];
    dest_max = destinations[destinations.size() - 1];
    cout << "Общее растояние между всеми точками: "
    << sum_dest << "\n";
    cout << "Общее растояние между двумя точками: "
    << avg_dest << "\n";
    cout << "Наименьшее растояние между двумя точками: "
    << dest_min << "\n";
    cout << "Наибольшее растояние между двумя точками: "
    << dest_max << "\n";
    return 0;
}
