#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isLeapYear(int year) {
    if (year % 4)
        return false;
       
    // year is divisible by 4
    if (year % 400 == 0)
        return true;
   
    // year is not divisible by 400
    if (year % 100 == 0)
        return false;
       
    // year is not divisible by 100
    return true;        
}

//returns # of days in specified month of the year
//jan/march/may/july/august/oct/dec --> 14
//april/june/sep/nov --> 30
//feb: 29 for leap year, 28 for other years
int getDaysInMonth(int year, int month) {
   if (month <1 || month > 12){
   return 0;
   }
   if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
   return 31;
   }
   if (month == 4 || month == 6 || month ==9 || month == 11){
   return 30;
   }
   if (month ==2){
   return (isLeapYear(year) ? 29 : 28);
   }
 return 0;
}

//returns day # for the date in the whole year
int getDayNumber(int day, int month, int year) {
   int totaldays = 0;
   for (int m=1; m<month; m++){
   totaldays += getDaysInMonth(year, m);
   }
      totaldays += day;
   return totaldays;
}

int dayYearCal() {
    int day, month, year;
    char temp; //to read '/' characters in the date input
    cin >> month >> temp >> day >> temp >> year;
   
    cout << "It is day # " << getDayNumber(day, month, year) << " of the year!";
}


