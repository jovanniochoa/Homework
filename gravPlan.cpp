#include <iostream>
#include <iomanip>
using namespace std;
int gravPlan()
{
const double earthGrav = 9.81;
const double moonGrav = 1.62;
const double venusGrav = 8.87;
double earthMass;

cout << "Enter the mass in kg" << endl;
cin >> earthMass;

cout << fixed << setprecision(4);
cout << "The mass is " << earthMass << " kg" << endl;;
if (earthMass < 0){
 cout << "The mass must be greater than zero" << endl;
}

else
    {
    cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)" << endl;
    cout << setw(8) << left << "Earth" << setw(14) << right << earthMass*earthGrav << endl;
    cout << setw(8) << left << "Moon" << setw(14) << right << earthMass*moonGrav << endl;
    cout << setw(8) << left << "Venus" << setw(14) << right << earthMass*venusGrav << endl;

    if (earthMass*earthGrav >= 1500)
        {
        cout << "The object is heavy" << endl;
        }
    if (earthMass*earthGrav < 5)
        {
        cout << "The object is light" << endl;
        }
    }


}
