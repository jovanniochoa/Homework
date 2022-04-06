#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXPRODUCTS = 100;
string names[MAXPRODUCTS] = {"Bruschetta", "Caprese_Flatbread", "Artichoke-Spinach_Dip", "Lasagna_Fritta", 
"Mozzarella_Fonduta", "Lasagna_Classico", "Capellini_Pomodoro", "Eggplant_Parmigiana", "Fettuccine_Alfredo", 
"Tour_of_Italy", "Tiramisu", "Zeppoli", "Dolcini", "Soda", "Bella_Limonata", "Berry_Acqua_Fresca"};
double prices[MAXPRODUCTS] = {5.29, 6.10, 3.99, 4.99, 5.99, 6.99, 7.99, 8.99, 7.49, 14.99, 2.99, 2.49, 3.49, 1.99, 0.99, 2.88};
string codes[MAXPRODUCTS] = {"A1", "A2", "A3", "A4", "A5", "E1", "E2", "E3", "E4", "E5", "D1", "D2", "D3", "S1", "S2", "S3"};
double numProducts = 0;
string inputCode;


void readConfiguration() {
   cout << fixed << setprecision(2);
   cout << "16 items loaded." << endl;
          cout << "Enter your order string: ";
}

//return valid index if the item is found, return -1 otherwise.
int findItem(string inputCode) {
    int temo = 0;
    // checks if the input code matches any of the codes avaliable
   for (int i = 0; i<16; i++){
if (inputCode == codes[i]){
   cout << names[i] << ": $" << prices[i] << endl;
   numProducts = numProducts + prices[i];
         return numProducts;
    }
   }
   // if the input doesnt equal an avaliable code, it sets an int to 1 which later outputs an error for invalid code.
   for (int i = 0; i<16; i++){
if (inputCode != codes[i]){
    temo = 1;
}
if (temo == 1){
cout << inputCode << " is invalid. Skipping it." << endl;
return -1;
}
}
}

// read order string like "A1 A1 E1 E2 S1" and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() {
   string temp;
getline(cin,temp);
   istringstream fstream(temp);
   while (fstream >> inputCode){
findItem(inputCode);
   }
   cout << "Total: $" << numProducts << endl;
}

int moreArray() {
   readConfiguration();
   process();
}


