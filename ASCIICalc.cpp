/*
This program is supposed to get the minimum number and maximum number of the user
and convert the users number range to ASCII character mappings
*/
#include <iostream>
using namespace std;
int ASCIICalc()
{
    unsigned int lower;
    unsigned int higher;
    unsigned char i;
// this code asks the user for the range and stores the information
do{  cout << "Enter lower and upper values" << endl;
  cin >> lower;
  cin >> higher;
  if (lower > higher || lower < 32 || higher > 126){
    cout << "Values must be in range 32 to 126 inclusive" << endl;
  }
}
// This code reads in the user input and displays an error message/ tells them to retype their answer if not within the range
  while (lower > higher || lower < 32 || higher > 126);
    cout << "Characters for ASCII values between " << lower <<  " and " << higher << endl;
  cout << "----+----+----+----+" << endl;
// this code converts the code to ADCII character mappings
  for (i = lower; i <= higher; ++i) {
    cout << i;
    if ((i-lower) % 20 == 19)
      cout << endl;
  }
  if ((higher - lower)%20 == 19){
    cout << "----+----+----+----+" << endl;
  }
  else{
cout << endl;
cout << "----+----+----+----+" << endl;
  }
}


