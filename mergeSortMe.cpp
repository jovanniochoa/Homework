#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAXITEMS = 100;
int items[MAXITEMS];
int numItems = 0;

void printArray(int first, int last) {
    for(int i=first; i<=last; i++)
        cout << items[i] << " ";
    cout << endl;
}

//partition the specified subarray and return pivot index
int mergeSort(int first, int last)
{
    //let us take the first item as pivot to keep things simple.
    int pivot = items[first];
    int smallIndex = first+1;
    int bigIndex = last;

    while (smallIndex <= bigIndex) //more to partition?
    {
        //skip all small items, but don't go beyond the array
        while ((items[smallIndex] < pivot) && (smallIndex <= last))
            smallIndex++;

        //skip all big items, but don't step on pivot
        while ((items[bigIndex] > pivot) && (bigIndex > first))
            bigIndex--;

        //index values still valid? does it make sense to swap?
        if ((smallIndex <= last) && (bigIndex > first) && (smallIndex < bigIndex)) {
            swap(items[smallIndex], items[bigIndex]); //exchange big & small items
            smallIndex++;   //continue to partition...
            bigIndex--;
        }
    }

    //swap pivot with last item of left side sub-array
    smallIndex--;
    swap(items[first], items[smallIndex]);
    return smallIndex;
}

void merge(int first, int last)
{
    cout << "Invoke: " << first << "," << last << ": ";
    printArray(first, last);

    //check end condition
    if (first >= last) //1 item or less --> no work to do!
        return;

    //if not, do partition and invoke for each sub-array.
    int pivotIndex = mergeSort(first, last);
    merge(first, pivotIndex-1); //left side sub-array (<)
    merge(pivotIndex+1, last); //right-side sub-array (>)

    cout << "Done: " << first << "," << last << ": ";
    printArray(first, last);
}



int mergeSortMe()
{
    string line;

    //enter all array items in one line
    cout << "Enter items: ";
    getline(cin, line);
    istringstream istr(line);
    while (istr >> items[numItems])
        numItems++;

    merge(0, numItems-1);

    cout << "Sorted output: ";
    printArray(0, numItems-1);
}

