#include <iostream>
#include <string>

using namespace std;

int palindromeCheck(string word) {
   // word contents can be accessed like an array
   // how to find the # of mismatches?
   //iterate through the first half of the array
   //carefully check each item with corresponding item in second half.
   //int n = word.length();
   //word[i] vs.word[n-1-i]
int mismatches = 0;
int n = word.length();
for (int i = 0; i<n/2; i++)
   if (word[i] != word[n-1-i])
   mismatches++;
  
  return mismatches;
}

int palindrome() {
   string input;

   cout << "Enter word: ";
   cin >> input;
   int mismatchCount = palindromeCheck(input);
   if (mismatchCount)
      cout << "# of mismatches: " << mismatchCount << endl; 
   else
      cout << "It is a palindrome!\n";
}


