#include <iostream>
#include <sstream>
using namespace std;

    //array: index = 10 n-1
    //recursive way
    // find the smallest value
    // exchange array[0] with array[smallestIndex]
    //now sort remaining index -1 to 1
    
int items[] = {40, 10, 46, 23, 22, 16, 27, 6, 100, 1, 9};
int numItems = 11;
    
void selectionSort(int startIndex, int endIndex){
    if (startIndex == endIndex)
        return;
        
    //find the smallest iem in specidied range
    int smallestItem = items[startIndex];
    int smallestItemIndex = startIndex;
    for(int i = startIndex+1; i <= endIndex; i++)
        if (items[i] < smallestItem) { //current item smaller?
            smallestItem = items[i];
            smallestItemIndex = i;
        }
    //swapping values require 3 sequential steps
    //swap it with items[startIndex]
    int temp = items[smallestItemIndex];
    items[smallestItemIndex] = items[startIndex];
    items[startIndex] = temp;
    
    //sort the ramaining array!
    selectionSort(startIndex+1, endIndex);
}

int numSortRe()
{
    selectionSort(0, numItems-1);
    for(int i = 0; i<numItems; i++)
        cout << items[i] << endl;
}

