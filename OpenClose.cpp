#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int OpenClose()
{
string fileName;
ifstream inputFile;
getline(cin,fileName);
inputFile.open(fileName);
int x = 0;
int y = 0;
char par;
char table[x][y];
int multiple = 0;

cin >> multiple;
if (inputFile){
}
   while (inputFile >> par)
    {
        table[x][y] = par;
      y++;
      if (y>x){
          x+=1;
          y=0;
      } 
    }

for (int i = 0; i < multiple; i++){
for (int j = 0; j < multiple; j++){
    cout << table[i][j];
} 
}
cout << table[0][0];
inputFile.close();
}


