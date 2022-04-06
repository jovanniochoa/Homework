#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;
int jeopardyGam (){

int score1 = 0;
int score2 = 0;
int score3 = 0;
int player = 10;
int scoreTemp = 10;

string line ="";
getline(cin, line);
istringstream(line) >> player >> scoreTemp;
if (player == 1){
    score1 = scoreTemp + score1;
}
if (player == 2){
    score2 = scoreTemp + score2;
}
if (player == 3){
    score3 = scoreTemp + score3;
}
while (player !=0){
getline(cin, line);
istringstream(line) >> player >> scoreTemp;
if (player == 1){
    score1 = scoreTemp + score1;
}
if (player == 2){
    score2 = scoreTemp + score2;
}
if (player == 3){
    score3 = scoreTemp + score3;
}
}

cout << "Final scores: " << endl;
cout << "Player 1: " << score1 << endl;
cout << "Player 2: " << score2 << endl;
cout << "Player 3: " << score3 << endl;

if (score1 > score2 && score1 > score3){
cout << "Player 1 is the winner!" << endl;
}
if (score2 > score1 && score2 > score3){
cout << "Player 2 is the winner!" << endl;
}
if (score3 > score1 && score3 > score2){
cout << "Player 3 is the winner!" << endl;
}
if (score3 == score1 && score3 == score2 && score2 == score1){
cout << "Player 1 is the winner!" << endl;
}
if (score2 == score3){
cout << "Player 2 is the winner!" << endl;
}

}
