 /*
This program gets the number of rows and columns and
outputs the minimum value in the row, the average in the columns,
& processing.
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int MAX_COLUMNS = 5;


   //lowValue function returns the smallest value in each row
double lowValue(double values[][MAX_COLUMNS], int rowNumber)
{
 double minVal = values[rowNumber][0];
 int i;
 for (i = 0; i<MAX_COLUMNS; i++)
 {
  if (values[rowNumber][i] < minVal)
  {
   minVal = values[rowNumber][i];
  }
 }
 return minVal;
}






//finds the column average
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows)
{
 double sum = 0;
 int i;
    //Iterate over rows
 for (i = 0; i<numberRows; i++)
 {
     //Calculate the sum
  sum += values[i][column];
 }
    //Find the avearge and return it
 return (sum / (double)(numberRows));
}




//finds the average of the function
double average(double values[][MAX_COLUMNS], int numberRows)
{
 double sum = 0;
 int i, j;
 for (i = 0; i<numberRows; i++)
 { 
  for (j = 0; j<MAX_COLUMNS; j++)
  {
   sum = sum + values[i][j];
  }
 }
 return (sum / (double)(numberRows*MAX_COLUMNS));
}





int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFile)
{
 int i, j;
 string line;
 fstream    inputs(inputFile, ios::in);
 if (   inputs.fail())
 {
  return -1;
 }
 else
 {
  for (i = 0; i<maxRows &&    inputs.good(); i++)
  {
   for (j = 0; j<MAX_COLUMNS; j++)
   {
       inputs >> values[i][j];
    if (   inputs.fail() && i == 0)
    {
     return 0;
    }
   }

  }
 }
    inputs.close();
 return i;
}





   //Main function
int rowscolumn()
{
int rows, cols;
const int MAX_ROWS = 30;
string inputFile;
double grades[MAX_ROWS][MAX_COLUMNS];
int numRows;
cout << fixed << setprecision(2);
cout << "Enter input file name" << endl;
cin >> inputFile;
numRows = readFile(grades, MAX_ROWS, inputFile);
if (numRows == -1)
 {
  cout << endl << "File \"" << inputFile << "\" could not be opened " << endl;
 }
 else if (numRows == 0)
 {
  cout << endl << "The input file \"" << inputFile << "\" did not contain any data " << endl;
 }
 else
 {
cout << "Processing " << numRows << " rows, and " << MAX_COLUMNS << " columns " << endl;
cout << "Average for all values is " << average(grades, numRows) << endl;
  for (cols = 0; cols < MAX_COLUMNS; cols++)
  {
        cout << "Average for column " << cols << " is " << columnAverage(grades, cols, numRows) << endl;
  }
        for (rows = 0; rows < numRows; rows++)
  {
        cout << "Smallest value for row " << rows << " is " << lowValue(grades, rows) << endl;
  }
 } 
 return 0;
}


