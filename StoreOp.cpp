#include <iostream>
#include <iomanip> // Input/output manipulation
#include <string>
#include <fstream>

using namespace std;

const int MAXPRODUCTS = 1000; //just for MAX memory allocation
int numProducts=0;

string products[MAXPRODUCTS];
double prices[MAXPRODUCTS];
int codes[MAXPRODUCTS];

//read everything from products.txt
void setup()
{
    ifstream finput("products2.txt");
    
    //read the product plucodes, names & prices.
    while ( finput >> codes[numProducts] >> products[numProducts] >> prices[numProducts]){
       numProducts ++;
}
}

void listProducts() {
    cout << "Available products: " << numProducts << endl;
    for(int i=0; i<numProducts; i++)
        cout << codes[i] << " " << products[i] << " @ " << prices[i] << "/pound.\n";
}

//Write a function named validatePLU
//check whether inputCode is in codes[] array
//if so, return that index, otherwise return -1
int validatePLU(int input) {   
   for (int i = 0; i<numProducts; i++){
if (input == codes[i]){
return i;
}
}
return -1;
}

//displays all the products & get the next selection from the user
int getNextSelection()
{
    while (true)
    {
        int plu = 0, selection = 0;

        cout << "Enter PLU code (0 to end): ";
        cin >> plu;

        //user entered 0, go ahead and return!
        if (!plu)
            return -1;

        selection = validatePLU(plu);

        //invalid cases - output a message & go to top
        if (selection < 0)
        {
            cout << "Invalid selection.\n";
            continue;
        }
        return selection;
    }
}

//finish checkout operation and return the total
double checkout()
{
    //always a good practice to initialize variables!
    double weight=0, total = 0;

    listProducts();
    cout << fixed << setprecision(2);
    while (true)
    {
        int selection = getNextSelection();
        //at this point, we guarantee selection has 0 to NUMPRODUCTS only.
        if (selection < 0) //checkout is done! It is same as (selection == 0)
            break;

        cout << "Enter the weight: ";
        cin >> weight;

        total += weight * prices[selection];

        cout << "Total so far: $ " << total << endl;
    }

    cout << "Final total: $ " << total << endl;
    return total;
}

int StoreOp()
{
    double grandTotal = 0;
    char response = 'n';

    setup(); //get per-pound prices

    do
    {
        //since checkout() returns the total,
        //we can simply add the return value to grandTotal.
        grandTotal += checkout();
        cout << "(n)ext customer or (q)uit? ";
        cin >> response;
    }
    while (response == 'n');

    //now that the register is closed, output the grand total.
    cout << "Grand total: $" << grandTotal << endl;
    cout << "Good bye.";


}


