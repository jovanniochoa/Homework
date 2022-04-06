#include <iostream>

using namespace std;

//returns the index of minimum value in array[startIndex .. stopIndex]
int findMinIndex(int *array, int startIndex, int stopIndex) {
int minimum = array[startIndex];
int minIndex = startIndex;
for (int i = startIndex;i <= stopIndex; i++){
if (array[i] < minimum){
minimum = array[i];
minIndex = i;
}
}
return minIndex;
}

//SWAPs contents of 2 variables.
void exchange(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int SortBub() {
	int numbers[100], arraySize;

	cin >> arraySize;
	for(int i=0; i<arraySize; i++)
        cin >> numbers[i];

    //UPDATE THIS CODE - Step 2
    for (int i = 0; i <= arraySize; i++){
    int index = findMinIndex(numbers, i, arraySize-1);
    exchange(numbers[i], numbers[index]);
    }

	for(int i=0; i<arraySize; i++)
        cout << numbers[i] << " ";
}


