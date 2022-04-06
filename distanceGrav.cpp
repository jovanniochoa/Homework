#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

double readSeconds(){
    double seconds;
    cout << "Enter the time (in seconds)" << endl;
        cin >> seconds;
    while (seconds < 0){
        cout << "The time must be zero or more" << endl;
        cout << "Enter the time (in seconds)" << endl;
        cin >> seconds;
    }

}

double calculateEarthDistance(double seconds){
    double gravity = 9.8;
    double distance = 0;
   distance = 0.5 * gravity * pow(seconds, 2);
   return distance;
}

double calculateMoonDistance(double seconds){
    double gravity = 1.6;
    double distance = 0;
   distance = 0.5 * gravity * pow(seconds, 2);
   return distance;

}
void displayResults(double seconds, double earthDistance, double moonDistance){

    cout << "The object traveled " << earthDistance << " meters in " << seconds << " seconds on Earth" << endl;
    cout << "The object traveled " << moonDistance << " meters in " << seconds << " seconds on the Moon" << endl;
}

int distanceGrav(){
    while (true){
    double seconds = readSeconds();
    if (seconds == 0){
        return 0;
    }
    double moonDistance = calculateMoonDistance(seconds);
    double earthDistance = calculateEarthDistance(seconds);
   displayResults(seconds, moonDistance, earthDistance);
    }
}


