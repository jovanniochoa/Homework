#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int counterGood()
{
double userNum;
string filename;
string inputfile;
double counter = 0;
double badcounter = 0;
double total;
cout << fixed << setprecision(4);
cout << "Enter input file name" << endl;
cin >> inputfile;
// open a file given by user input
ifstream finput (inputfile.c_str());
if (!finput.is_open()){
    cout << "File \"" << inputfile << "\" could not be opened"<< endl;
    return 0;
}

cin >> filename;
//open the file and get ready for reading!
ofstream foutput;
foutput.open ("invalid-values.txt");
//if file does not open close all the other files
if (!foutput.is_open()){
    finput.close();
    foutput.close();
    return 0;
}
else{
    cout << "Reading from file \"" << inputfile << "\""<< endl;
// checks if the store number is invalid
while (finput >> userNum){
if (userNum < 0 || userNum > 105){
badcounter += 1;
foutput << fixed << setprecision(5);
foutput << userNum << endl;
}
else{
counter += 1;
total += userNum;
}
}
// outputs total and invalid counter
cout << fixed << setprecision(0);
cout << "Total values: " << counter+badcounter << endl;
cout << "Invalid values: " <<  badcounter << endl;
cout << "Valid values: " << counter << endl;
// checks if the total values is equal to 0
if (counter == 0){
    cout << "An average cannot be calculated" << endl;
    finput.close();
foutput.close();
return 0;
}
else{
        cout << fixed << setprecision(4);
cout << "Average of valid values: " << total/counter << endl;
}

}
// closes files at the end
finput.close();
foutput.close();
return 0;
}



