#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int FromOne()
{
unsigned int numStore;
string filename;
string inputfile;
long long int salesData;
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
foutput.open ("saleschart.txt");
//if file does not open close all the other files
if (!foutput.is_open()){
    finput.close();
    foutput.close();
    return 0;
}
else{
foutput << "SALES BAR CHART" << endl;
foutput << "(Each * equals 5,000 dollars)" << endl;
// checks if the store number is invalid
while (finput >> numStore >> salesData){
if (numStore < 1 || numStore > 99){
cout << "The store number "<< numStore << " is not valid" << endl;
}
//checks if the sales data is negative
if (salesData < 0){
    cout << "The sales value for store " << numStore << " is negative" << endl;
}

if (salesData >= 0 && (numStore >= 1 && numStore <= 99)){
foutput << "Store " << setw(2) << numStore << ": ";
for (int i = 0; i < salesData/5000; i++){
foutput << "*";
}
foutput << endl;
}

}
}
// closes files at the end
finput.close();
foutput.close();
return 0;
}


