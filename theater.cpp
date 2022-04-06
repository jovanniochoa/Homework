#include <iostream>
#include <string>

using namespace std;

const int NUMROWS = 20;
const int SEATSPERROW = 10;
int allocated[NUMROWS];

void allocate(int seats){
 for (int row = 0; row<NUMROWS; row++){
    if (SEATSPERROW - allocated[row] >= seats){
            while (seats--){
        cout << (row + 1) << (char) (allocated[row]+ 'A') << " ";
        allocated[row]++;
            }
            cout << endl;
            return;
    }
 }
}

int theater (){
    int tickets = 0;
    while (true){
    cout << "Enter # of people in your party: ";
    cin >> tickets;
    allocate(tickets);
    }
}


