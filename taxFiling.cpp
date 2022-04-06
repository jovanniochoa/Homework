#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

const int NUM_BRACKETS = 7;

double rates[] = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};

double singleLimits[] = {0, 9525, 38700, 82500, 157500, 200000, 500000};
double singleTaxBase[] = {0, 952.50, 4453.50, 14089.50, 32089.50, 45689.50, 150689.50};

double jointLimits[] = {0, 19050, 77400, 165000, 315000, 400000, 600000};
double jointTaxBase[] = {0, 1905, 8907, 28179, 64179, 91379, 161379};

double separateFilingLimits[] = {0, 9525, 38700, 82500, 157500, 200000, 300000};
double separateFilingTaxBase[] = {0, 952.50, 4453.50, 14089.50, 32089.50, 45689.50, 80689.50};

double headLimits[] = {0, 13600, 51800, 82500, 157500, 200000, 500000};
double headTaxBase[] = {0, 1360, 5944, 12696, 30696, 44298, 149298};

double computeTax(double taxableAmount, double limits[], double taxBase[]) {
    // rates[] can be accessed directly, since it is global variable & it is common for all status's.
    // but if it was defined inside main(), then it will be a local variable & it has to be passed in as well.

    //CODE HERE
    double tax = 0;
    if (taxableAmount <= limits[1] && taxableAmount >= limits[0]){
        tax = (rates[0]*taxableAmount);
        return tax;
    }
        if (taxableAmount < limits[2] && taxableAmount >= limits[1]){
        tax = (((rates[1]*(taxableAmount-limits[1])) + taxBase[1]));
        return tax;
    }
            if (taxableAmount < limits[3] && taxableAmount >= limits[2]){
        tax = (((rates[2]*(taxableAmount-limits[2])) + taxBase[2]));
        return tax;
    }
            if (taxableAmount < limits[4] && taxableAmount >= limits[3]){
        tax = (((rates[3]*(taxableAmount-limits[3])) + taxBase[3]));
        return tax;
    }
            if (taxableAmount < limits[5] && taxableAmount >= limits[4]){
        tax = (((rates[4]*(taxableAmount-limits[4])) + taxBase[4]));
        return tax;
    }
            if (taxableAmount < limits[6] && taxableAmount >= limits[5]){
        tax = (((rates[5]*(taxableAmount-limits[5])) + taxBase[5]));
        return tax;
    }
            if (taxableAmount >= limits[6]){
        tax = (((rates[6]*(taxableAmount-limits[6])) + taxBase[6]));
        return tax;
    }
}

int taxFiling() {
    string status = "";
    double taxableAmount = 0, tax = 0;

    cout << "Tax filing options: Single(X), Married Filing Jointly (Y1)," << endl;
    cout << "Married filing separately (Y2), Head of household (Z)." << endl;
    cout << "Select your status (X, Y1, Y2, Z): ";
    cin >> status;

    cout << "Enter the yearly taxable income: ";
    cin >> taxableAmount;

    //CODE HERE to invoke computeTax() as many times as needed and store the return value in tax.
    if (status == "X"){
   tax = computeTax(taxableAmount, singleLimits, singleTaxBase);
    }
    if (status == "Y1"){
    tax = computeTax(taxableAmount, jointLimits, jointTaxBase);
    }
    if (status == "Y2"){
    tax = computeTax(taxableAmount, separateFilingLimits, separateFilingTaxBase);
    }
    if (status == "Z"){
    tax = computeTax(taxableAmount, headLimits, headTaxBase);
    }
    if (status == "Z" || status == "Y2" || status == "Y1" || status == "X"){
    cout << "Your taxable amount: $" << fixed << setprecision(2) << tax << endl;}
    else{
    cout << "Filing option has to be one of X, Y1, Y2, Z." << endl;
    }
}




