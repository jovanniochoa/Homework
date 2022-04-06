#include <iostream>
using namespace std;
int numbers[] = {40,10,46,23,22,16,27,6};
int numItems = 8;
int target = 70;

int knapsack(int nextIndex, int total){
    // end conditions: all items considered, total >= target
    if (total > target)
        return 0;
    if (nextIndex == numItems)
        return total;
    // do NOT include current item
    int total1 = knapsack(nextIndex+1, total);
    //with includint current iostream
    int total2 = knapsack(nextIndex+1, total+numbers[nextIndex]);
    return max(total1, total2); //return best total
}
int knapSackRe(){
    for(int n = 1; n<100; n++){
        target = n;
    cout << target << ": " << knapsack(0,0) << endl;

    }
}


