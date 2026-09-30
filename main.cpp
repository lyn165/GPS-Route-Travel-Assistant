#include <iostream>
#include <string>
using namespace std;

int main(){

    double distance;
    int transportChoice,trafficChoice;
    double averageSpeed,estimatedTime;
    string transport,traffic,recommendedRoute,navigationAdvice;

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
            averageSpeed = 60;
            break;
        case 2:
            transport = "Motorcycle";
            averageSpeed = 50;
            break;
        case 3:
            transport = "Walking";
            averageSpeed = 5;
            break;
        default:
            transport = "Invalid";
            averageSpeed = 0;
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

    //RECOMMENDATION BASED ON TRAFFIC CONDITION
    if(trafficChoice==1){
        recommendedRoute = "Main Route";
        navigationAdvice = "Traffic is light right now. Continue usinng the main route.";
    }
    if(trafficChoice==2){
        recommendedRoute = "Main Route";
        navigationAdvice = "Moderate traffic detected but expect some delays.";
    }
    else if(trafficChoice==3){
        recommendedRoute = "Alternative Route";
        navigationAdvice = "Heavy traffic detected. Let's consider avoiding busy roads.";
    }

    //CALCULATE BASIC TRAVEL TIME
    estimatedTime = distance/averageSpeed;

    //ADJUST TIME ACCORDING TRAFFIC CONDITION
    if (trafficChoice==2){
        estimatedTime = estimatedTime*1.25;
    }
    else if (trafficChoice==3){
        estimatedTime = estimatedTime*1.5;
    }

    //PRINT INFORMATION
    cout << "\n========== GPS TRAVEL RESULT ==========" << endl;
    cout << "Distance: " << distance << "km" << endl;
    cout << "Transportation: " << transport << endl;
    cout << "Traffic Condition: " << traffic << endl;
    cout << "\nEstimated Travel Time: " << estimatedTime*60 << " minutes" << endl;
    cout << "Recommended Route: " << recommendedRoute << endl;
    cout << "Navigation Advice: " << navigationAdvice << endl;

    return 0;
}