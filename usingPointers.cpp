#include <iostream>
using namespace std;

int countItems(char *array) {
  int count = 0;
  while (*array++){
  cout << (void *) array << " ";
  count++;
  array++;
  }
  cout << endl;
  return count;
}

int countItems(int *array) {
  int count = 0;
  while (*array != 0){
  cout << array << " ";
  array++;
  count++;
  }
  cout << endl;
  return count;
}

int countItems(string *array) {
   int count = 0;
  while (*array++ != ""){
  cout << array << " ";
  count++;
  }
  cout << endl;
  return count;
}

int usingPointers() {

   cout << sizeof(char) << " " << sizeof(int) << " " << sizeof(string) << endl;
   char name[100] = "Jeyakesavan";
   cout << countItems(name) << endl;
   
   int values[] = {10, 20, 30, 0};
   cout << countItems(values) << endl;
   
   string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", ""};
   cout << countItems(days) << endl;

   return 0;
}


