#include <iostream>
#include <string>

using namespace std;


// ========================================
// Function Declarations
// ========================================

void displayWelcome();
void displayMenu();

int getTransportChoice();
int getTrafficChoice();

double calculateTravelTime(double distance, double averageSpeed);
double adjustTravelTime(double estimatedTime, int trafficChoice);

string getTransportName(int transportChoice);
string getTrafficName(int trafficChoice);
string getRecommendedRoute(int trafficChoice);
string getNavigationAdvice(int trafficChoice);

void planRoute();


// ========================================
// Main Function
// ========================================

int main()
{
    displayWelcome();

    planRoute();

    return 0;
}


// ========================================
// Welcome Screen
// ========================================

void displayWelcome()
{
    cout << "========================================" << endl;
    cout << "GPS ROUTE & TRAVEL ASSISTANT" << endl;
    cout << "========================================" << endl;

    cout << "Welcome to the GPS Route & Travel Assistant!" << endl;
    cout << "This program helps estimate your travel time" << endl;
    cout << "and provides basic navigation advice to U!" << endl;
}


// ========================================
// Main Menu
// ========================================

void displayMenu()
{
    cout << "GPS ROUTE & TRAVEL ASSISTANT" << endl;
}


// ========================================
// Get Transport Choice
// ========================================

int getTransportChoice()
{
    int transportChoice;

    cout << "\nSelect transportation mode: " << endl;
    cout << "1.Car" << endl;
    cout << "2.Motorcycle" << endl;
    cout << "3.Walking" << endl;
    cout << "\nEnter your choice(1-3): " << endl;

    cin >> transportChoice;

    return transportChoice;
}


// ========================================
// Get Traffic Choice
// ========================================

int getTrafficChoice()
{
    int trafficChoice;

    cout << "\nSelect traffic condition: " << endl;
    cout << "1.Light Traffic" << endl;
    cout << "2.Moderate Traffic" << endl;
    cout << "3.Heavy Traffic" << endl;
    cout << "\nEnter your choice(1-3): " << endl;

    cin >> trafficChoice;

    return trafficChoice;
}


// ========================================
// Get Transport Name
// ========================================

string getTransportName(int transportChoice)
{
    switch (transportChoice)
    {
        case 1:
            return "Car";

        case 2:
            return "Motorcycle";

        case 3:
            return "Walking";

        default:
            return "Invalid";
    }
}


// ========================================
// Get Traffic Name
// ========================================

string getTrafficName(int trafficChoice)
{
    switch (trafficChoice)
    {
        case 1:
            return "Light Traffic";

        case 2:
            return "Moderate Traffic";

        case 3:
            return "Heavy Traffic";

        default:
            return "Invalid";
    }
}


// ========================================
// Get Recommended Route
// ========================================

string getRecommendedRoute(int trafficChoice)
{
    if (trafficChoice == 1)
    {
        return "Main Route";
    }
    else if (trafficChoice == 2)
    {
        return "Main Route";
    }
    else
    {
        return "Alternative Route";
    }
}


// ========================================
// Get Navigation Advice
// ========================================

string getNavigationAdvice(int trafficChoice)
{
    if (trafficChoice == 1)
    {
        return "Traffic is light right now. Continue usinng the main route.";
    }
    else if (trafficChoice == 2)
    {
        return "Moderate traffic detected but expect some delays.";
    }
    else
    {
        return "Heavy traffic detected. Let's consider avoiding busy roads.";
    }
}


// ========================================
// Calculate Basic Travel Time
// ========================================

double calculateTravelTime(double distance, double averageSpeed)
{
    return distance / averageSpeed;
}


// ========================================
// Adjust Travel Time According to Traffic
// ========================================

double adjustTravelTime(double estimatedTime, int trafficChoice)
{
    if (trafficChoice == 2)
    {
        estimatedTime = estimatedTime * 1.25;
    }
    else if (trafficChoice == 3)
    {
        estimatedTime = estimatedTime * 1.5;
    }

    return estimatedTime;
}


// ========================================
// Plan Route
// ========================================

void planRoute()
{
    double distance;
    int transportChoice;
    int trafficChoice;

    double averageSpeed;
    double estimatedTime;

    string transport;
    string traffic;
    string recommendedRoute;
    string navigationAdvice;


    // ASK FOR INPUT

    cout << "\nEnter travel distance(km): " << endl;
    cin >> distance;


    // ASK FOR TRANSPORTATION MODE

    transportChoice = getTransportChoice();


    // SET TRANSPORTATION INFORMATION

    switch (transportChoice)
    {
        case 1:
            averageSpeed = 60;
            break;

        case 2:
            averageSpeed = 50;
            break;

        case 3:
            averageSpeed = 5;
            break;

        default:
            averageSpeed = 0;
            cout << "Invalid tranportation choice." << endl;
            break;
    }

    transport = getTransportName(transportChoice);


    // ASK FOR TRAFFIC CONDITION

    trafficChoice = getTrafficChoice();

    traffic = getTrafficName(trafficChoice);

    if (trafficChoice < 1 || trafficChoice > 3)
    {
        cout << "Invalid traffic condition." << endl;
    }


    // RECOMMENDATION BASED ON TRAFFIC CONDITION

    recommendedRoute = getRecommendedRoute(trafficChoice);
    navigationAdvice = getNavigationAdvice(trafficChoice);


    // CALCULATE BASIC TRAVEL TIME

    estimatedTime = calculateTravelTime(distance, averageSpeed);


    // ADJUST TIME ACCORDING TO TRAFFIC CONDITION

    estimatedTime = adjustTravelTime(estimatedTime, trafficChoice);


    // PRINT INFORMATION

    cout << "\n========== GPS TRAVEL RESULT ==========" << endl;
    cout << "Distance: " << distance << "km" << endl;
    cout << "Transportation: " << transport << endl;
    cout << "Traffic Condition: " << traffic << endl;

    cout << "\nEstimated Travel Time: "
         << estimatedTime * 60
         << " minutes" << endl;

    cout << "Recommended Route: "
         << recommendedRoute << endl;

    cout << "Navigation Advice: "
         << navigationAdvice << endl;
}