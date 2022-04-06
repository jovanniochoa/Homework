/*
This program is supposed to get interest rate, present value, and months from a file.
Next, the program will calculate the future value.
Finally, the program will display it in a chart called "output.xls".
*/
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//a function to calculate the future value. The program also converts the interest rate to decimals
double futureValue(double& presentValue, double& interestRate,
int& months){
    double futureValue = presentValue * pow((1 + interestRate),months);
    return futureValue;
}

//reads in the values and displays an error if they are not working.
unsigned int read(ifstream& inputfile, double& presentValue, double& interestRate, int& months){
while (!inputfile.eof()){
while (inputfile >> presentValue >> interestRate >> months){
    if (presentValue <= 0 || interestRate <= 0 || months <= 0){
    cout << fixed << setprecision(2) << presentValue << " "  << fixed << setprecision(3) << interestRate << " " << months << endl;
    cout << "One or more of the above values are not greater than zero" << endl;
    return 2;
    }
    else{
        return 1;
    }
}
}
return 0;
}

//this function displays the result in another file.
void display(double& presentValue, double& interestRate, int& months, double& futureValues, ofstream& foutput){
    foutput << fixed << setprecision(2) << futureValues << "\t" << fixed << setprecision(2) << presentValue << "\t" << fixed << setprecision(3) << interestRate << "\t" << fixed << setprecision(0)<< months << endl;
}

// driver functions opens and creates all the files necessary.
//It checks if the program opened correctly and displays an error if it didn't.
int futureValues()
{
double presentValue = 0;
double interestRate = 0;
double futureValues = 0;
int months = 0;
unsigned int reads;

string filename;
cout << "Enter input file name" << endl;
string inputfile;
cin >> inputfile;
ifstream finput (inputfile.c_str());
if (!finput.is_open()){
    cout << "File \"" << inputfile << "\" could not be opened"<< endl;
    return 1;
}

ofstream foutput;
foutput.open ("output.xls");
if (!foutput.is_open()){
    finput.close();
    foutput.close();
    return 1;
}
else{
foutput << "Future Value\tPresent Value\tMonthly Interest\tMonths" << endl;
while (!finput.eof()){
reads = read(finput, presentValue, interestRate, months);
if (reads == 1){
interestRate /= 100;
futureValues = futureValue( presentValue, interestRate, months);
interestRate *= 100;
display(presentValue, interestRate, months, futureValues, foutput);
}
}
}
    finput.close();
    foutput.close();
}









