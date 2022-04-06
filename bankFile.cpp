#include <iostream>
#include <fstream> //for file operations
#include <string>
#include <iomanip>

using namespace std;

int bankFile() {
   //instead of hardcoding the filename, we will ask the user!
    string filename;
    cout << "Enter the input filename: " << endl;;
    cin >> filename;

    //open the file kids.txt and get ready for reading!
    ifstream finput(filename.c_str());

    char operation;
    double amount = 0, balance = 0;

    cout << fixed << setprecision(2);

    //if read operation is successful, process it!
    while (finput >> operation >> amount) {
if (operation == 'D'){
    balance += amount;
   cout << "Deposit $" << amount << endl;
    cout << "Balance: $" << balance << endl;
    cout << endl;
    }
if (operation == 'W'){
        if(balance>= amount){
    balance -= amount;
   cout << "Withdraw $" << amount << endl;
    cout << "Balance: $" << balance << endl;
    cout << endl;
        }
         else{
               cout << "Withdraw $" << amount << endl;
         cout << "Insufficient money in the account!" << endl;
             cout << "Balance: $" << balance << endl;
    cout << endl;
}
}
    }
    cout << "Final balance: $" << balance;

}
