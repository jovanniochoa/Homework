#include <iostream>
using namespace std;
int googleRoute()
{
double routeNum;
double moneyPerMinute;
double minutes;
double toll;
double counter = 1;
double highestToll = 0;
cin >> routeNum;
cin >> moneyPerMinute;
for (int i = 1; i < routeNum+1; i++)
    {
    cin >> minutes;
    cin >> toll;
    if (moneyPerMinute > toll)
        {
        if (highestToll < toll)
            {
            highestToll = toll;
            counter = i;
            }
        }
    }
    cout << "Best route is #" << counter << endl;
}


