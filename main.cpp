#include <iostream>
using namespace std;

int main(){

    double distance;
    int transportChoice,trafficChoice;
    string transport,traffic;

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

    //SWITCH for TRANSPORT CHOICE
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

    //ASK FOR TRAFFIC CONDITION
    cout << "\nSelect traffic condition: " << endl;
    cout << "1.Light Traffic" << endl;
    cout << "2.Moderate Traffic" << endl;
    cout << "3.Heavy Traffic" << endl;
    cout << "\nEnter your choice(1-3): " << endl;
    cin >> trafficChoice;

    //SWITCH for TRAFFIC CHOICE
    switch(trafficChoice){
        case 1:
            traffic = "Light Traffic";
            break;
        case 2:
            traffic = "Moderate Traffic";
            break;
        case 3:
            traffic = "Heavy Traffic";
            break;
        default:
            traffic = "Invalid";
            cout << "Invalid traffic condition." << endl;
            break;
    }

    //PRINT INFORMATION
    cout << "\n========== TRAVEL INFORMATION ==========" << endl;
    cout << "Distance: " << distance << "km" << endl;
    cout << "Transportation: " << transport << endl;
    cout << "Traffic Condition: " << traffic << endl;

    return 0;
}