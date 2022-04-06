#include <iostream>
#include <iomanip>
using namespace std;

//define a class to store & print the date, also do increment operation
class Date
{
public:
    Date(int mm = 0, int dd = 0, int yy = 0)
    {
        year = yy;
        month = mm;
        day = dd;
    }
    void display()
    {
        cout << month << '/' << day << '/' << year;
    }

    //function to return true if year is leap year, false otherwise.
    bool isLeapYear()
    {
        if (year % 4)
            return false;

        // year is divisible by 4
        if (year % 400 == 0)
            return true;

        // year is not divisible by 400
        if (year % 100 == 0)
            return false;

        // year is divisible by 4, but not divisible by 100
        return true;
    }

    //increment the day, if needed, increment the month,
    //if needed, increment the year
    void increment()
    {
        //static makes this array to be allocated like a global variable
        //but it is used only within this function
        static int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30,
                                           31, 31, 30, 31, 30, 31
                                          };
        if ((month == 2) && isLeapYear())
            daysInMonths[2] = 29;
        else
            daysInMonths[2] = 28;

        day+=1;
        if (daysInMonths[month] < day ){
            month += day/daysInMonths[month];
            day = day%daysInMonths[month-1];
        }
        if (month > 12){
            year += month/12;
            month = month%12;
        }
    }
private:
    int day, month, year;
};

//class to store time and display and do increment() operation
class Time
{
public:
    Time(int hh = 0, int mm = 0, int ss = 0)
    {
        hour = hh;
        minute = mm;
        second = ss;
    }

    //second: 59 --> 60: increment minute
    //minute: 59 --> 60: increment hour
    //hour: 23-->24: hour=0
    //return true if the day rolls over, return false otherwise.
    bool increment()
    {
      second += 1;
        if (second >= 60){
            minute += second/60;
            second = second%60;
        }
        if (minute >= 60){
            hour += minute/60;
            minute = minute%60;
        }
        if (hour >= 24){
            hour = 0;
            return true;
        } else {
            return false;
        }
    }

    void display()
    {
        cout << setfill('0');
        if (hour == 0)
            cout << 12 << ':' << setw(2) << minute << ':' << setw(2) << second << " AM";
        else if (hour < 12)
            cout << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second << " AM";
        else if (hour == 12)
            cout << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second << " PM";
        else
            cout << setw(2) << hour-12 << ':' << setw(2) << minute << ':' << setw(2) << second << " PM";
    }

private:
    int hour, minute, second;
};

//composition - we used 2 objects: Date & Time objects
class DateTime
{
public:
    //pass the necessary parameters to each constructor
    //to populate member objects
    DateTime(int mm=0, int dd=0, int yy=0, int hh=0, int mmm=0, int ss=0)
    {
        date = Date(mm, dd, yy);
        time = Time(hh, mmm, ss);
    }

    void increment()
    {
        // if day rolled over, increment the date
        if (time.increment())
            date.increment();
    }

    void display()
    {
        date.display();
        cout << " ";
        time.display();
    }

private:
    Date date;
    Time time;
};

int PrintDate()
{
    string info = " ";
    cin >> info;
    if (info == "D"){
        int mm = 0, dd = 0, yy = 0, inc = 0;
        char random = ' ';
        cin >> mm >> random >> dd >> random >> yy >> inc;
        Date(mm, dd, yy);
        Date Date(mm, dd, yy);
        Date.isLeapYear();
        for (int i =0; i< inc; i++)
            Date.increment();
        Date.display();
    }
    
    if (info == "T"){
        int hh = 0, mm = 0, ss = 0, inc = 0;
        char random = ' ';
        cin >> hh >> random >> mm >> random >> ss >> inc;
        Time(hh, mm, ss);
        Time Time(hh, mm, ss);
        for (int i = 0; i < inc; i++)
            Time.increment();
        Time.display();
    }
    
    if(info == "DT"){
        int mm = 0, dd = 0, yy = 0, hh = 0, mmm = 0, ss = 0, inc = 0;
        char random = ' ';
        cin >> mm >> random >> dd >> random >> yy >> hh >> random >> mmm >> random >> ss >> inc;
        DateTime(mm, dd, yy, hh, mmm, ss);
        DateTime DateTime(mm, dd, yy, hh, mmm, ss);
        for (int i = 0; i < inc; i++)
            DateTime.increment();
        DateTime.display();
    }
}



