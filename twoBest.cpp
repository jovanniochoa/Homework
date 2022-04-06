#include <iostream>
#include <string>

using namespace std;

int numbers[] = {40, 10, 46, 23, 22, 16, 27, 57, 75, 6};
int count = 10;
// return the item that is closest to the target, but do not go over.
int bestOne(int target){
    int bestSoFar = 0;
    for (int i = 0; i < count; i++){
    if (numbers[i] <= target && numbers[i] > bestSoFar){
        bestSoFar = numbers[i];
    }
    }
    return bestSoFar;
}
int bestTwo (int target){
    int bestSoFar = 0;
    for (int i = 0; i < count; i++){
        for (int j = i+1; j < count; j++){
            int total = numbers[i]+numbers[j];
    if (total <= target && total > bestSoFar){
        bestSoFar = total;
    }
    }
    }
    return bestSoFar;   
}

int twoBest(){
    for(int i=1; i<=100;i++){
        cout << i << ": " << bestOne(i) << " "<< bestTwo(i) << endl;
    }   
}


