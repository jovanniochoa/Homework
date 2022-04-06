#include <iostream>
#include <iomanip>

using namespace std;

// A -> 4, B -> 3, C -> 2, D -> 1, otherwise return 0
int letterToPoints(char grade) 
{
   int numberReturned = 100;
   cin >> grade;
   if (grade == 'A')
   {
   numberReturned = 4;
   return numberReturned;
   }
   if (grade == 'B')
   {
   numberReturned = 3;
   return numberReturned;
   }
   if (grade == 'C')
   {
   numberReturned = 2;
   return numberReturned;
   }
   if (grade == 'D')
   {
   numberReturned = 1;
   return numberReturned;
   }
   else
   {
   numberReturned = 0;
   return numberReturned;
   }
}

int returnGPAAg() 
{
    cout << fixed << setprecision(2);
   int numClasses = 0;
   double number = 0;
   char grade = ' ';
   int creditHours = 0;
   double multiple = 0;
   double creditTotal = 0;
   double total = 0;
   cout << "# of courses: ";
   cin >> numClasses;
   for (int i = 0; i<numClasses; i++)
   {
    cout << "Enter credit hours & grade for course " << i+1 << ": ";
    cin >> creditHours;
    number = letterToPoints(grade);
    total = (multiple + (number*creditHours))/(creditTotal + creditHours);
    multiple = (number*creditHours) + multiple;
    creditTotal = creditHours + creditTotal;
    cout << "GPA so far: " << total << endl;
   }
   cout << "Final GPA: " << total << endl;
}


