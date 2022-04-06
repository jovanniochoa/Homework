#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//let us assume we won't go over 100 numbers
const int MAXITEMS = 100;
int items[MAXITEMS], binAssignments[MAXITEMS];
int numItems=0; //stores actual # of items
const int BINCAPACITY = 100;

void validate() {
    //ERROR checking
    bool doesWork = true;
    //checks for bin out of ranged
    for (int i = 0; i<numItems; i++){
    if (binAssignments[i] > numItems){
    cout << "Bin " << binAssignments[i] << " out of range" << endl;
    doesWork = false;
    }
    }
    
     //checks for input out of ranged
    for (int x = 0; x<numItems; x++){
    if (items[x] > MAXITEMS){
    cout << "Input item " << items[x] << " out of range" << endl;
    doesWork = false;
    }
    }
    
    //checks which inputs go above 100 per bin
    double count = 0;
    double total = 0;
    for(int q = 0; q < numItems; q++){
    if (binAssignments[q] == count){
       total += items[q];
    }
    else{
    count++;
    }
    if (total > MAXITEMS){
    cout << "bin " << count << " total goes above 100" << endl;
    doesWork = false;
    }
    }
    
    //checks if a bin has been skipped
    double counts = 0;
    for (int t = 0; t < numItems; t++){
    if (binAssignments[t] > counts){
    if (binAssignments[t] == counts+1){
    counts = counts+1;
    }
    else{
    cout << "Bin " << counts+1 << " not used" << endl;
    doesWork = false;
    }
    }
    }
    
    if (doesWork == true){
    cout << "Valid" << endl;
    }


}

int binPack() {
   string line;
   int numAssignments = 0;

   //get all the items first.
   getline(cin, line);  //get one line of input
   istringstream istr(line);  //convert it to inputstringstream
   //extract the numbers from the stream into the array
   while (istr >> items[numItems])
      numItems++;

    //get bin assignments now.
   getline(cin, line);
   istringstream istr2(line);
   while (istr2 >> binAssignments[numAssignments]) //ERROR checking here too?
      numAssignments++;

    if (numItems != numAssignments) {
        cout << "# of items and # of bin assignments mismatch.";
        exit(1);
    }
    validate();
}



