#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int fileCorrectOpen(){
unsigned int storeNum;
long long int salesValue;
string fileName;

ifstream inputFile;
inputFile.open(fileName);
int num;
if (inputFile)
{
   // the file opened successfully
   while (inputFile >> num)
   {
      // process the num value
      cout << num << endl;
   }
   inputFile.close();
}
else
{
   cout << "The file could not be opened" << endl;
}
}
