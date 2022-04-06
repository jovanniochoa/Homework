#include <iostream>

using namespace std;

//print n in specified radix r - without using recursion
void printRadixNonRec(int n, int r) {
        string output = "";
        while (n>0){
            output = (char) (n%r + '0') + output;//compute the last digit
            n = n/r;
        }
        cout << output;
}
int num,radix;
//print n in specified radix r - using recursion
void printRadixRec(int n, int r) {
        if (n >0){
            printRadixRec(n/r,r); // recursion first! // outputs "14"

        }
}


int radixSpec() {
    int num, radix;
    cout << "Enter number & radix ";
    cin >> num >> radix;

    printRadixRec(num, radix);
    cout << " ";
    printRadixNonRec(num, radix);
    printRadixRec(num, radix);
    cout << " ";
    printRadixNonRec(num, radix);
    cout << endl;
}


