/*
This program opens two files... It opens the student answers, and the actual answers, to compare.
The program the calculates the grade of the student given that they have the same amount of questions answered.
If The program doesn't have the same amount of questions answered, it displays an error, and quits the program.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>


using namespace std;

// returns an integer to determine how many answers are on the file, and if the given amount causes an error.
unsigned int read(ifstream& finput, ifstream& sinput, char *input, char *answer, int& i, int& j){
while (!finput.eof()){
while (finput >> input[i]){
i++;
}
}
while (!sinput.eof()){
while (sinput >> answer[j]){
j++;
}
}
if (j == i){
    return 0;
}
if (j > 30){
    j = 30;
    return 30;
}
else {
    cout << "The student answers file has " << i << " entries and the correct answers file has " << j << " entries" << endl;
cout << "Grading cannot be done if they are not the same" << endl;
    return i;
}
}

// displays the number of correct and incorrect answers , as well as, calculates the percentage, and shows if the student passed or not.
void display(char *input, char *answer, int& i, int& numWrong, int& j){
int q = 0;
numWrong = 0;
double percentage = 0;
for (int k = 0; k < i; k++){
if (input[k] != answer[k]){
    cout << "Question "<< k+1 <<" has incorrect answer '" << input[k] << "', the correct answer is '" << answer[k] << "'" << endl;
    numWrong += 1;
}
q++;
}
if (q > 30){
    q = 30;
}
double temp = q;
percentage = 100 - ((numWrong/temp)*100);
if (numWrong - j == 0){
    cout << "The number of student answers and correct answers are both 0" << endl;
    cout << "No grade can be calculated" << endl;
    return ;
}
if (j > i || i > j){
    return;
}
else{
cout << numWrong << " questions were missed out of " << temp << endl;
cout << fixed << setprecision(1);
cout << "The student grade is " << percentage << "%" << endl;
if (percentage >= 70){
    cout << "The student passed" << endl;
}
else{
    cout << "The student failed" << endl;
}
}
}


//opens the file, and displays an error if the file could not be found...
int gradeCalcComp()
{
char input[30];
char answer[30];
int numWrong = 0;
int i = 0;
int j = 0;
string inputfile;
string answerfile;
cout << "Enter student answers file name" << endl;
cin >> inputfile;
ifstream finput (inputfile.c_str());
if (!finput.is_open()){
    cout << "File \"" << inputfile << "\" could not be opened"<< endl;
    return -1;
}

cout << "Enter correct answer file name" << endl;
cin >> answerfile;
ifstream sinput (answerfile.c_str());
if (!sinput.is_open()){
    cout << "File \"" << answerfile << "\" could not be opened"<< endl;
    finput.close();
    return -1;
}

int returnval = read(finput, sinput, input, answer, i , j);
if (returnval == 0){
display(input, answer, i, numWrong, j);
}
    finput.close();
    sinput.close();
}



