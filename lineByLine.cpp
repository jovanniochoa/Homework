#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int lineByLine() {
   string temp = "";
   while(getline(cin, temp)){
      int total = 0;
      int age =0;
      int dollars =0;
      istringstream sstr(temp);
      cout << "List the age(s) of each person: ";
      while (sstr >> age){
         if (age < 0){
            dollars = 0;
            total += dollars;
         }
         if (age < 10 && age >= 5){
            dollars = 5;
            total += dollars;
         }
         if (age >= 10 && age < 60){
            dollars = 10;
            total += dollars;
         }
         if (age >= 60){
            dollars = 8;
            total += dollars;
         }
      }
   if (total == 0){
      cout << "Good bye!" << endl;
   }
   else{
   cout << "Total entry fee: $" << total << endl;
   }
   }
}


