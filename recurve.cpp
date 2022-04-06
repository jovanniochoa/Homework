#include <iostream>
using namespace std;
int fib(int n) {
    if (n <= 1)
        return n;
    else
        return fib(n-1) + fib(n-2);
}
int fibNonRec(int n){
    // use an array for bottom-up computation
    // recursion did top-down computation in brute-force manner
    
    // allocate dynamic array
    int *results = new int [n+1];
    results[0] = 0;
    results[1] = 1;
    for (int i =2; i <= n; i++) //compute up all the way to n
        results[i] = results[i-1] + results [i-2];
    return results[n]; //ignoring memory release for now.
}

int recurve(){
    for (int i = 0; i <100; i++)
        cout << i << ": " << fibNonRec(i) << endl;
}


