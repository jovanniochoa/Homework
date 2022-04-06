#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAXPEOPLE = 100;
int ages[MAXPEOPLE];
string firstNames[MAXPEOPLE], lastNames[MAXPEOPLE];
double incomes[MAXPEOPLE];
int count = 0; //actual # of people in group.txt

void bubbleDown(int lastIndex){
    for(int i=0; i<lastIndex; i++)
        //check ages[i] vs. ages[i+1]
        if (ages[i] > ages[i+1]) {
            swap(ages[i], ages[i+1]); //let the heavy item bubble down!
            swap(firstNames[i], firstNames[i+1]);
            swap(lastNames[i], lastNames[i+1]);
            swap(incomes[i], incomes[i+1]);
        }
}

//invoke bubbleDown (count-1) times!
//bubbles down untill there is only one item left to sort
void bubbleSort(){
    for(int last = count-1; last > 0; last--)
        bubbleDown(last);
    //bubbleDown: [0...count-1]
    //bubbleDown: [0...count-2]
    //bubbleDown: [0...count-3]
    //...
    //bubbleDown: [0...2]
    //bubbleDown: [0...1]
    //bubbleDown: [0...0]
}

int BubbleDownSwap(){
    
    // read group.txt and load up arrays
    ifstream finput ("group.txt");
    finput >> count;
    for (int i = 0; i<count; i++)
        finput >> ages[i] >> firstNames[i] >> lastNames[i] >> incomes[i];
    finput.close();
    
    bubbleSort();
    
    for (int i = 0; i<count; i++)
        cout << ages[i] << " " << firstNames[i] << " " << lastNames[i] << " " << incomes[i] << " " << endl;
    
    return 0;
}

