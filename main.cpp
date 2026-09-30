#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// ========================================
// Function Declarations
// ========================================

void displayWelcome();
void displayMenu();
void displayLocations();

int getMenuChoice();
int getLocationChoice();
int getTransportChoice();
int getTrafficChoice();

double getDistance(int start, int destination);
double getSpeed(int transportChoice);
double getFuelEfficiency(int transportChoice);
double calculateTravelTime(double distance, double averageSpeed);
double adjustTravelTime(double estimatedTime, int trafficChoice);
double calculateFuelCost(double distance, int transportChoice);

string getLocationName(int location);
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
    int choice;

    displayWelcome();

    do
    {
        displayMenu();

        choice = getMenuChoice();

        cout << endl;

        switch (choice)
        {
            case 1:
                planRoute();
                break;

            case 2:
                cout << "Thank you for using GPS Route & Travel Assistant!"
                     << endl;
                cout << "Have a safe journey!" << endl;
                break;
        }

        cout << endl;

    } while (choice != 2);

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

    cout << endl;
}


// ========================================
// Main Menu
// ========================================

void displayMenu()
{
    cout << "--------------- MAIN MENU ---------------" << endl;
    cout << "1. Plan a Route" << endl;
    cout << "2. Exit" << endl;
    cout << "------------------------------------------" << endl;
}


// ========================================
// Get Main Menu Choice
// ========================================

int getMenuChoice()
{
    int choice;

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice >= 1 && choice <= 2)
        {
            return choice;
        }

        cout << "Invalid choice. Please enter 1 or 2." << endl;
    }
}


// ========================================
// Display Available Locations
// ========================================

void displayLocations()
{
    cout << "Available Locations:" << endl;
    cout << "1. MMU Cyberjaya" << endl;
    cout << "2. IOI City Mall" << endl;
    cout << "3. Putrajaya" << endl;
    cout << "4. KLCC" << endl;
}


// ========================================
// Get Location Choice
// ========================================

int getLocationChoice()
{
    int choice;

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice >= 1 && choice <= 4)
        {
            return choice;
        }

        cout << "Invalid location. Please enter 1 to 4." << endl;
    }
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
    cout << "3.Public Transport" << endl;
    cout << "4.Walking" << endl;

    while (true)
    {
        cout << "\nEnter your choice(1-4): " << endl;
        cin >> transportChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (transportChoice >= 1 && transportChoice <= 4)
        {
            return transportChoice;
        }

        cout << "Invalid transport mode. Please enter 1 to 4." << endl;
    }
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

    while (true)
    {
        cout << "Enter your choice: ";
        cin >> trafficChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (trafficChoice >= 1 && trafficChoice <= 3)
        {
            return trafficChoice;
        }

        cout << "Invalid traffic condition. Please enter 1 to 3." << endl;
    }
}


// ========================================
// Get Location Name
// ========================================

string getLocationName(int location)
{
    switch (location)
    {
        case 1:
            return "MMU Cyberjaya";

        case 2:
            return "IOI City Mall";

        case 3:
            return "Putrajaya";

        case 4:
            return "KLCC";

        default:
            return "Unknown";
    }
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
            return "Public Transport";

        case 4:
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
// Get Distance
// Predefined distances simulate GPS data
// ========================================

double getDistance(int start, int destination)
{
    if (start == destination)
    {
        return 0.0;
    }

    // MMU Cyberjaya
    if (start == 1)
    {
        if (destination == 2)
            return 8.0;

        if (destination == 3)
            return 12.0;

        if (destination == 4)
            return 35.0;
    }

    // IOI City Mall
    if (start == 2)
    {
        if (destination == 1)
            return 8.0;

        if (destination == 3)
            return 6.0;

        if (destination == 4)
            return 28.0;
    }

    // Putrajaya
    if (start == 3)
    {
        if (destination == 1)
            return 12.0;

        if (destination == 2)
            return 6.0;

        if (destination == 4)
            return 30.0;
    }

    // KLCC
    if (start == 4)
    {
        if (destination == 1)
            return 35.0;

        if (destination == 2)
            return 28.0;

        if (destination == 3)
            return 30.0;
    }

    return 0.0;
}


// ========================================
// Get Average Speed
// ========================================

double getSpeed(int transportChoice)
{
    switch (transportChoice)
    {
        case 1:
            return 60.0;

        case 2:
            return 50.0;

        case 3:
            return 40.0;

        case 4:
            return 5.0;

        default:
            return 0.0;
    }
}


// ========================================
// Get Fuel Efficiency
// ========================================

double getFuelEfficiency(int transportChoice)
{
    switch (transportChoice)
    {
        case 1:
            return 15.0;

        case 2:
            return 35.0;

        case 3:
            return 0.0;

        case 4:
            return 0.0;

        default:
            return 0.0;
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
// Calculate Travel Cost
// ========================================

double calculateFuelCost(double distance, int transportChoice)
{
    const double fuelPrice = 2.05;

    double fuelEfficiency = getFuelEfficiency(transportChoice);

    if (fuelEfficiency == 0.0)
    {
        return 0.0;
    }

    double fuelUsed = distance / fuelEfficiency;

    return fuelUsed * fuelPrice;
}


// ========================================
// Plan Route
// ========================================

void planRoute()
{
    int start;
    int destination;
    int transportChoice;
    int trafficChoice;

    double distance;
    double averageSpeed;
    double estimatedTime;
    double travelCost;

    string transport;
    string traffic;
    string recommendedRoute;
    string navigationAdvice;


    // ASK FOR CURRENT LOCATION

    cout << "\nCurrent Location" << endl;

    displayLocations();

    start = getLocationChoice();


    // ASK FOR DESTINATION

    cout << "\nDestination" << endl;

    displayLocations();

    destination = getLocationChoice();


    // CHECK SAME LOCATION

    if (start == destination)
    {
        cout << endl;
        cout << "Your current location and destination are the same."
             << endl;
        cout << "No travel is required." << endl;

        return;
    }


    // GET DISTANCE

    distance = getDistance(start, destination);


    // ASK FOR TRANSPORTATION MODE

    transportChoice = getTransportChoice();

    averageSpeed = getSpeed(transportChoice);

    transport = getTransportName(transportChoice);


    // ASK FOR TRAFFIC CONDITION

    trafficChoice = getTrafficChoice();

    traffic = getTrafficName(trafficChoice);


    // RECOMMENDATION BASED ON TRAFFIC CONDITION

    recommendedRoute = getRecommendedRoute(trafficChoice);
    navigationAdvice = getNavigationAdvice(trafficChoice);


    // CALCULATE BASIC TRAVEL TIME

    estimatedTime = calculateTravelTime(distance, averageSpeed);


    // ADJUST TIME ACCORDING TO TRAFFIC CONDITION

    estimatedTime = adjustTravelTime(estimatedTime, trafficChoice);


    // CALCULATE TRAVEL COST

    travelCost = calculateFuelCost(distance, transportChoice);


    // PRINT INFORMATION

    cout << "\n========== GPS TRAVEL RESULT ==========" << endl;
    cout << "From: " << getLocationName(start) << endl;
    cout << "To: " << getLocationName(destination) << endl;
    cout << "Distance: " << distance << "km" << endl;
    cout << "Transportation: " << transport << endl;
    cout << "Traffic Condition: " << traffic << endl;

    cout << fixed << setprecision(2);

    cout << "\nEstimated Travel Time: "
         << estimatedTime * 60
         << " minutes" << endl;

    cout << "Estimated Travel Cost: RM "
         << travelCost << endl;

    cout << "Recommended Route: "
         << recommendedRoute << endl;

    cout << "Navigation Advice: "
         << navigationAdvice << endl;
}