#include <iostream>

using namespace std;

int process(int amount, string itemName, int itemValue) {
int howmany = amount / itemValue;
if (howmany == 0)
{
return amount;
}
cout << howmany << " " << itemName;
if (howmany > 1)
{
    cout << "s";
    cout << " ";
    amount = amount % itemValue;
}
if (amount > 0){
    cout << ",";
    cout << " ";
}
return amount;
}

int calcCents(){
int cents = 0;
cout << "Enter an amount (in cents): ";
cin >> cents;

//Quarters
cents = process(cents, "Quarter", 25);
//Dimes
cents = process (cents, "Dime", 10);
//Nickels
cents = process(cents, "Nickel", 5);
//cents
cents = process(cents, "Cent", 1);
}


