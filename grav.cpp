#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;


//reads the seconds and prompts the user to retype a number if it's below 0. The program ends if the user types 0. 
double readSeconds(){
    double seconds;
    cout << "Enter the time (in seconds)" << endl;
        cin >> seconds;
    while (seconds < 0){
        cout << "The time must be zero or more" << endl;
        cout << "Enter the time (in seconds)" << endl;
        cin >> seconds;
    }
    if (seconds > 0) {
        return seconds;
    }

}
// calculates the earth distance. given the amount of seconds
double calculateEarthDistance(double seconds){
    double gravity = 9.8;
    double distance = 0.00;
   distance = 0.5 * gravity * seconds * seconds;
   return distance;
}
// calculates the moon distance. given the amount of seconds
double calculateMoonDistance(double seconds){
    double gravity = 1.6;
    double distance = 0.00;
   distance = 0.5 * gravity * seconds * seconds;
   return distance;

}
//displays the results.
void displayResults(double seconds, double earthDistance, double moonDistance){
    cout << "The object traveled " << fixed << setprecision(4) << earthDistance << " meters in " << fixed << setprecision(2) << seconds << " seconds on Earth" << endl;
    cout << "The object traveled " << fixed << setprecision(4) << moonDistance << " meters in " << fixed << setprecision(2) << seconds << " seconds on the Moon" << endl;
}
//outputs the function sto calculate everything.
int grav(){
    while (true){
    double seconds = readSeconds();
    if (seconds == 0.00)
    {
        return false;
    }
    double moonDistance = calculateMoonDistance(seconds);
    double earthDistance = calculateEarthDistance(seconds);
   displayResults(seconds,earthDistance,moonDistance);
    }
}


