#include <iostream>
#include <sstream>

using namespace std;

int
listList ()
{
  string line;
  int value = 0;
  int list[1000];

  cout << "Enter the list: ";
  getline (cin, line);

  istringstream sinput (line);
  int numItems = 0;
  // while (sinput >> value){
  //   list[numItems++] = value;
  //}
  while (sinput >> list[numItems])
    {
      numItems++;
    }

  while (true)
    {
      cout << "Enter a number: ";
      int number = 0;
      cin >> number;
      int i;
      for (i=0; i < numItems; i++)
{
 if (list[i] == number)
   {
     cout << "Yes, it is in the list!" << endl;
     break;
   }
}
 if (i == numItems)
   {
     cout << "No, it is not in the list!" << endl;
   }
    }
  cout << "Got " << numItems << " values.";
}
