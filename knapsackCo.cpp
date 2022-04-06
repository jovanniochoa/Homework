#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAXITEMS = 100;
int items[MAXITEMS];
int numItems = 0;
int target = 0, bestTotal = 0;
string bestTotalItems = "";

void knapsack(int nextIndex, int total, string selectedItems) {
    //end conditions: all items considered, total >= target
    if (total > target)  //invalid values
        return;
    if (nextIndex == numItems) { //all items considered?
        if (bestTotal < total) {
            bestTotal = total; //new better total
            bestTotalItems = selectedItems; //corresponding item list
        }
        return;
    }
    //case 1: do NOT include current item
    knapsack(nextIndex+1, total, selectedItems);
    //case 2: include current item // "10 20" --> "10 25 7"
    knapsack(nextIndex+1, total+items[nextIndex],
    selectedItems + " " + to_string(items[nextIndex]));
}

int knapsackCo() {
   string line = "";
   cout << "Enter items: ";
   getline(cin, line);
   istringstream istr(line);
   while (istr >> items[numItems])
      numItems++;
      
   cout << "Enter target: ";
   cin >> target;
   knapsack(0, 0, "");
   cout << "Achieved " << bestTotal<< ":" << bestTotalItems << " " << endl;
}


