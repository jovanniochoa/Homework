#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;
int typos(){

ifstream inputFile;
inputFile.open("typo.in");
ofstream outputFile;
outputFile.open("typo.out");
char par;
int count = 0;
int count1 = 0;
int count2 = 0;
if (inputFile)
{
   // the file opened successfully. Start calculating paranthesis
   while (inputFile >> par)
   {
       count++;
      if (par == '('){
          count1++;
      }
      if (par == ')'){
          count2++;
      }
      if (count1-count2 <= -1){
          outputFile << count2;
          break;
      }
   }
   if (count1-count2 > 0){
       outputFile << count/2;
   }
}
inputFile.close();
outputFile.close();
return 0;
}



