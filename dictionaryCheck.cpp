#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const int MAXLETTERS = 6;
const int row = 26;
char eachLetter[row][MAXLETTERS];
int numCharacters[26];
string charWords[1000000];
int counter = 0;

//checks if the number of characters matches those in dictonary
//if so, stores it in an array.
void charMatch(string& word){ 
   int size = 0;
   int wordLength = word.length();
   string line = " ";
   ifstream finputs("words.txt");
   while(getline(finputs,line)){
      istringstream istr(line);
      stringstream boss(line);
      size = boss.str().size();
      size -=1;
      
      if(wordLength == size){
      charWords[counter] = line;
      counter++;
      }
}
}

/*
//checks if function charMatch is working correctly
//only for testing purposes
void checkingSameChar(){
for (int j = 0; j < 1000000; j++){
cout << charWords[j];
}
}
*/

//find suggestions for words. Use recursion.
void recursion(string& word){
   int length = word.length();
for (int i = 0; i < length; i++){
if (word.at(i) == 'c'){
   word.at(i) = 'v';
}
}
cout << word;
}

/*
If (nextIndex == word.length())
	Search dictionary for searchWord && increment counter if found
	Return;
Consider inputWord[nextIndex] & its alternates
//int typoIndex = inputWord[nextIndex] - ‘a’;
//typoWords[typoIndex] has the character and its alternates
For each of those characters c
	recursiveFunction(inputWord, searchWord + c, nextIndex+1);
*/



//stores the letters in a 2D array
//stores the amount of characters per letter in a different array
void storeLetters(){
   int x = 0;
   int i = 0;
   int size = 0;
   string line = " ";
   ifstream finput("typo2.txt");
   while(getline(finput,line)){
      istringstream istr(line);
      stringstream oss(line);
      size = oss.str().size();
      numCharacters[i] = size-1;
      i++;
      int temp = line.length();
      for (int i = 0; i < temp; i++){
      istr >> eachLetter[x][i];
   }
      x++;
   }
   finput.close();
}

/*
//prints the values from 2D array (mostly for testing)
void print(){
for (int i = 0; i < 26; i++){
   for (int j = 0; j < numCharacters[i]; j++){
      cout << eachLetter[i][j];
   }
   cout << endl;
}
}
*/


int dictionaryCheck()
{
string word;
cin >> word;
charMatch(word);
storeLetters(); 
//print();
//checkingSameChar();
recursion(word);
}



