#include <iostream>
#include <string>
#include <cstdlib> // used to create a random number of passengers (Just to simulate, since I don't have an actual list)

using namespace std;

int numPassengers = 0;
int upgradeCost = 400;
int quality = 0; // economy = 1 and premium = 2
int hasMoney = 0; // he has money to pay = 1 and he has no money = 2

void printTicket(){ // prints the ticket and say's the goodbye
    //prints ticket... ("ofstream printer(ticket_Information);") 
    cout << "Pick up the boarding pass below." << endl;
    cout << "Thanks for choosing us. Have a great flight!" << endl;
}

void passengerQuestions(){
    if(numPassengers > 4){
        cout << "Please see agent to check-in your group. Thank you!" << endl;
        }
    else{
        if (quality == 1){
            string upgradeAnswer = "";
            cout << "Are you interested in upgrading to first class for $" << upgradeCost << " each?" << endl;
            cin >> upgradeAnswer;
            if(upgradeAnswer == "y" || upgradeAnswer == "yes" || upgradeAnswer == "1"){
                cout << "Slide credit card to pay for the upgrade." << endl;
                hasMoney = rand() %2 + 1; //for simulation, I got a random number to decide if his credit card is declined 1 is yes, 2 is no
                if (hasMoney = 1){
                    quality = 2; //changes to premium ticket
                    printTicket();
                }
                else{
                    cout << "Credit card was declined. See agent for assistance" << endl;
                }
            }
            else{
                printTicket();
            }
        }
        else{
            printTicket();
        }
    }
}

//checks if confirmation number is valid
bool isconfNumberValid(int confNumber){
    if (confNumber > 99999 && confNumber < 1000000){
         srand (time(NULL));
         numPassengers = rand() % 10 + 1; //for simulation, I got a random number of passengers (assuming group is less than 10)
         quality = rand() %2 + 1; //for simulation, I got a random number to decide the quality they "chose"
        return true;
    }
    else{
        return false;
    }
}

//checks if confirmation number is valid
bool isflyerNumberValid(int flyerNumber){
    if (flyerNumber > 0){
         srand (time(NULL));
         numPassengers = rand() % 10 + 1; //for simulation, I got a random number of passengers (assuming group is less than 10)
         quality = rand() %2 + 1; //for simulation, I got a random number to decide the quality they "chose"
        return true;
    }
    else{
        return false;
    }
}

int airlineTicket(){ //processess airline... I assume they keypad input has numbers AND letter, but no way to capitalize. (i've never seen one)
    while(true){
        string choice = "";
        cout << "Welcome to Alice Airlines. Please choose an option to check-in" << endl;
        cout << "Confirmation number, Frequent flyer number, credit card" << endl;
        cout << "If you do not have any of these, please see agent." << endl;
        getline(cin, choice);
        if (choice == "1" || choice == "confirmation number" || choice == "confirmation"){
            int confNumber = -1;
            cout << "enter 6-digit confirmation number: " << endl;
            cin >> confNumber;
            isconfNumberValid(confNumber);
            while (isconfNumberValid(confNumber) == false){
                cout << "Invalid confirmation number. Please re-enter: " << endl;
                cin >> confNumber;
                isconfNumberValid(confNumber);
            }
            passengerQuestions();
        }
        if (choice == "2" || choice == "frequent flyer number" || choice == "frequent flyer" || choice == "frequent"){
            int flyerNumber = -1;
            cout << "enter your frequent flyer number: " << endl;
            cin >> flyerNumber;
            while (isflyerNumberValid(flyerNumber) == false){
                cout << "Invalid frequent flyer number. Please re-enter: " << endl;
                cin >> flyerNumber;
                isflyerNumberValid(flyerNumber);
            }
            passengerQuestions();
        }
        if (choice == "3" || choice == "credit card" || choice == "credit"){
            //user selected the credit car option
            cout << "Please swipe the credit card." << endl; // waits for credit card swipe 
            string passengers = "John"; //for simulation, I will have his name be john (I would do rand, but name is arbitrary) 
            cout << "Enter the destination city for your trip today: " << endl;
            string destination = "Egypt"; //for simulation, I will have his destination be egypt, it's arbitrary too(since im not doing print function).
            int confirmationNumber = rand()%2 +1; //for simulation, it will confirm his flight or not. confirmed = 1 and denied = 2
            if (confirmationNumber = 1){
                passengerQuestions();
            }
            else{
                cout << "sorry, I could not pull up your reservation. Please see agent." << endl;
            }
        }
    cin.ignore();
    }
}



