#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//"A+" --> 4.0, "A" --> 4.0, "A-" --> 3.7, ... so on.
double letterToPoints(string grade) {
   if (grade == "A+"){
       return 4.0;
   }
   if (grade == "A"){
       return 4.0;
   }
   if (grade == "A-"){
       return 3.7;
   }
   if (grade == "B+"){
       return 3.3;
   }
   if (grade == "B"){
       return 3.0;
   }
   if (grade == "B-"){
       return 2.7;
   }
   if (grade == "C+"){
       return 2.3;
   }
   if (grade == "C"){
       return 2.0;
   }
   if (grade == "C-"){
       return 1.7;
   }
   if (grade == "D+"){
       return 1.3;
   }
   if (grade == "D"){
       return 1.0;
   }
   if (grade == "F"){
       return 0.0;
   }
}

int computeGrade() {
   double numCreditHours;
   int core;
   string letterGrade;
   double totalNumCreditHours;
   double totalCoreNumCreditHours;
   double conversion;
   double firstHalf;
   double secondHalf;
   int counter;
    do{
   cin >> numCreditHours;
   if (numCreditHours == 0){
       break;
   }
   cin >> letterGrade;
   conversion = letterToPoints(letterGrade);
   firstHalf += (numCreditHours*conversion);
   totalNumCreditHours += numCreditHours;
   cin >> core;
   if (core == 1)
   {
   secondHalf += (numCreditHours*conversion);
   totalCoreNumCreditHours += numCreditHours;
   counter++;
   }
   else {
       continue;
   }
    } while(numCreditHours !=0);
   cout << fixed << setprecision(2);
   if (counter == 0){
   cout << "Cumulative GPA: " << firstHalf/totalNumCreditHours << " Core GPA: NA" << endl;
}
else{
   cout << "Cumulative GPA: " << firstHalf/totalNumCreditHours << " Core GPA: " << secondHalf/totalCoreNumCreditHours << endl;
}
}


