#include <iostream>
using namespace std;
int lottolotto(){
int num1;
int num2;
int num3;
int num4;
int num5;
int num6;

cout << "You need to input 6 unique numbers between 1 and 50." << endl;
cout << " Enter number #1" << endl;

cin >> num1;
while (num1 >50 || num1 <1){
cout << "That is outside the range of 1 to 50. Please re-enter." << endl;
cin >> num1;
}

cout << " Enter number #2" << endl;
cin >> num2;
while (num2 == num1 || (num2 > 50 || num2 <1) ){
if (num2 == num1){
cout << "It's a duplicate - Please re-enter." << endl;
cin >> num2;
}
if (num2 >50 || num2 <1){
cout << "That is outside the range of 1 to 50. Please re-enter." << endl;
cin >> num2;
}
}

cout << " Enter number #3" << endl;
cin >> num3;
while ((num3 == num2 || num3 ==num1) || (num3 > 50 || num3 <1)){
if (num3 == num2 || num3 ==num1){
cout << "It's a duplicate - Please re-enter." << endl;
cin >> num3;
}
if (num3 >50 || num3 <1){
cout << "That is outside the range of 1 to 50. Please re-enter." << endl;
cin >> num3;
}
}

cout << " Enter number #4" << endl;
cin >> num4;
while ((num4 == num3 || num4 ==num2 || num4 == num1) || (num4 >50 || num4 <1)){
if (num4 == num3 || num4 ==num2 || num4 == num1){
cout << "It's a duplicate - Please re-enter." << endl;
cin >> num4;
}
if (num4 >50 || num4 <1){
cout << "That is outside the range of 1 to 50. Please re-enter." << endl;
cin >> num4;
}
}

cout << " Enter number #5" << endl;
cin >> num5;
while ((num5 == num4 || num5 ==num3 || num5 == num2 || num5 == num1)|| (num5 >50 || num5 <1)){
if (num5 == num4 || num5 ==num3 || num5 == num2 || num5 == num1){
cout << "It's a duplicate - Please re-enter." << endl;
cin >> num5;
}
if (num5 >50 || num5 <1){
cout << "That is outside the range of 1 to 50. Please re-enter." << endl;
cin >> num5;
}
}

cout << " Enter number #6" << endl;
cin >> num6;
while ((num6 == num5 || num6 ==num4 || num6 == num3 || num6 == num2 || num6 == num1) || (num6 >50 || num6 <1)){
if (num6 == num5 || num6 ==num4 || num6 == num3 || num6 == num2 || num6 == num1){
cout << "It's a duplicate - Please re-enter." << endl;
cin >> num6;
}
if (num6 >50 || num6 <1){
cout << "That is outside the range of 1 to 50. Please re-enter." << endl;
cin >> num6;
}
}
cout << "Great! Final numbers are" << num1 << ", " << num2 << ", " << num3 << ", " << num4 << ", " << num5 << ", " << num6 << endl;
}


