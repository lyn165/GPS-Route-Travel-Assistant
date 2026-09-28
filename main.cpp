#include <iostream>
using namespace std;

int main(){

    double distance;
    int transportChoice;
    string transport;

    //TOPIC
    cout << "========================================" << endl;
    cout << "GPS ROUTE & TRAVEL ASSISTANT" << endl;
    cout << "========================================" << endl;

    //WELCOME MESSSAGE
    cout << "Welcome to the GPS Route & Travel Assistant!" << endl;
    cout << "This program helps estimate your travel time" << endl;
    cout << "and provides basic navigation advice to U!" << endl;

    //ASK FOR INPUT
    cout << "\nEnter travel distance(km): " << endl;
    cin >> distance;

    //ASK FOR SELECT TRANSPORTATION MODE
    cout << "\nSelect transportation mode: " << endl;
    cout << "1.Car" << endl;
    cout << "2.Motorcycle" << endl;
    cout << "3.Walking" << endl;
    cout << "\nEnter your choice(1-3): " << endl;
    cin >> transportChoice;

    //SWITCH
    switch(transportChoice){
        case 1:
            transport = "Car";
            break;
        case 2:
            transport = "Motorcycle";
            break;
        case 3:
            transport = "Walking";
            break;
        default:
            transport = "Invalid";
            cout << "Invalid tranportation choice." << endl;
            break;
    }

    //PRINT INFORMATION
    cout << "\n========== TRAVEL INFORMATION ==========" << endl;
    cout << "Distance: " << distance << "km" << endl;
    cout << "Transportation: " << transport << endl;

    return 0;
}