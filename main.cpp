#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;


// ========================================
// Function Declarations
// ========================================

void displayWelcome();
void displayMenu();
void displayLocations();
void displayLocationInformation();

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
string getNavigationAdvice(
    int trafficChoice,
    double distance,
    int transportChoice
);

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
                displayLocationInformation();
                break;

            case 3:
                cout << "Thank you for using GPS Route & Travel Assistant!"
                     << endl;
                cout << "Have a safe journey!" << endl;
                break;
        }

        cout << endl;

    } while (choice != 3);

    return 0;
}


// ========================================
// Welcome Screen
// ========================================

void displayWelcome()
{
    cout << "========================================" << endl;
    cout << "     GPS ROUTE & TRAVEL ASSISTANT" << endl;
    cout << "========================================" << endl;

    cout << "Welcome to the GPS Route & Travel Assistant!"
         << endl;

    cout << "This program helps estimate your travel time,"
         << endl;

    cout << "travel cost, and provides basic navigation"
         << endl;

    cout << "advice based on your selected route."
         << endl;

    cout << "========================================" << endl;

    cout << endl;
}


// ========================================
// Main Menu
// ========================================

void displayMenu()
{
    cout << "--------------- MAIN MENU ---------------" << endl;
    cout << "1. Plan a Route & Estimate Cost" << endl;
    cout << "2. View Location Information" << endl;
    cout << "3. Exit" << endl;
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

            cout << "Invalid input. Please enter a number."
                 << endl;

            continue;
        }

        if (choice >= 1 && choice <= 3)
        {
            return choice;
        }

        cout << "Invalid choice. Please enter 1, 2, or 3."
             << endl;
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
    cout << "3. TRX" << endl;
    cout << "4. KLCC" << endl;
    cout << "5. Pasar Seni" << endl;
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

            cout << "Invalid input. Please enter a number."
                 << endl;

            continue;
        }

        if (choice >= 1 && choice <= 5)
        {
            return choice;
        }

        cout << "Invalid location. Please enter 1 to 5."
             << endl;
    }
}


// ========================================
// Get Transport Choice
// ========================================

int getTransportChoice()
{
    int transportChoice;

    cout << "\nSelect transportation mode:" << endl;
    cout << "1. Car" << endl;
    cout << "2. Motorcycle" << endl;
    cout << "3. Public Transport" << endl;
    cout << "4. Walking" << endl;

    while (true)
    {
        cout << "\nEnter your choice (1-4): ";
        cin >> transportChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number."
                 << endl;

            continue;
        }

        if (transportChoice >= 1 && transportChoice <= 4)
        {
            return transportChoice;
        }

        cout << "Invalid transport mode. Please enter 1 to 4."
             << endl;
    }
}


// ========================================
// Get Traffic Choice
// ========================================

int getTrafficChoice()
{
    int trafficChoice;

    cout << "\nSelect traffic condition:" << endl;
    cout << "1. Light Traffic" << endl;
    cout << "2. Moderate Traffic" << endl;
    cout << "3. Heavy Traffic" << endl;

    while (true)
    {
        cout << "\nEnter your choice (1-3): ";
        cin >> trafficChoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Invalid input. Please enter a number."
                 << endl;

            continue;
        }

        if (trafficChoice >= 1 && trafficChoice <= 3)
        {
            return trafficChoice;
        }

        cout << "Invalid traffic condition. Please enter 1 to 3."
             << endl;
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
            return "TRX";

        case 4:
            return "KLCC";

        case 5:
            return "Pasar Seni";

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
        return "Main Route - Expect Minor Delays";
    }
    else
    {
        return "Alternative Route";
    }
}


// ========================================
// Get Navigation Advice
// Considers traffic, distance and transport
// ========================================

string getNavigationAdvice(
    int trafficChoice,
    double distance,
    int transportChoice
)
{
    if (trafficChoice == 3)
    {
        if (distance >= 25)
        {
            return "Heavy traffic detected on a long journey. "
                   "Consider using the alternative route and "
                   "allow extra travel time.";
        }
        else
        {
            return "Heavy traffic detected. Consider avoiding "
                   "busy roads and using the alternative route.";
        }
    }
    else if (trafficChoice == 2)
    {
        if (distance >= 25)
        {
            return "Moderate traffic detected on a long journey. "
                   "Expect minor delays and allow extra travel time.";
        }
        else
        {
            return "Moderate traffic detected. Expect some delays "
                   "while using the main route.";
        }
    }
    else
    {
        if (transportChoice == 4 && distance >= 10)
        {
            return "The journey is relatively long for walking. "
                   "Consider another transportation mode.";
        }
        else if (transportChoice == 3)
        {
            return "Traffic is light. Public transport is suitable "
                   "for this journey.";
        }
        else
        {
            return "Traffic is light right now. Continue using "
                   "the main route.";
        }
    }
}


// ========================================
// Get Distance
// Predefined distances simulate GPS data
// ========================================

double getDistance(int start, int destination)
{
    int routeCode = start * 10 + destination;

    switch (routeCode)
    {
        // From MMU Cyberjaya
        case 12:
            return 13.0;

        case 13:
            return 33.0;

        case 14:
            return 35.0;

        case 15:
            return 32.0;


        // From IOI City Mall
        case 21:
            return 13.0;

        case 23:
            return 28.0;

        case 24:
            return 31.0;

        case 25:
            return 26.0;


        // From TRX
        case 31:
            return 33.0;

        case 32:
            return 28.0;

        case 34:
            return 4.3;

        case 35:
            return 4.6;


        // From KLCC
        case 41:
            return 35.0;

        case 42:
            return 31.0;

        case 43:
            return 4.3;

        case 45:
            return 6.3;


        // From Pasar Seni
        case 51:
            return 32.0;

        case 52:
            return 26.0;

        case 53:
            return 4.6;

        case 54:
            return 6.3;

        default:
            return 0.0;
    }
}


// ========================================
// Get Average Speed
// ========================================

double getSpeed(int transportChoice)
{
    switch (transportChoice)
    {
        case 1:
            return 65.0;

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
// Calculate Travel Cost
// Assumed fuel price = RM4.57 per litre
// Public Transport = RM2.00 per hour
// ========================================

double calculateFuelCost(
    double distance,
    int transportChoice
)
{
    double fuelEfficiency;
    double fuelPrice = 4.57;

    if (transportChoice == 3)
    {
        double averageSpeed = getSpeed(transportChoice);

        return (distance / averageSpeed) * 2.00;
    }

    fuelEfficiency = getFuelEfficiency(transportChoice);

    if (fuelEfficiency > 0)
    {
        return (distance / fuelEfficiency) * fuelPrice;
    }

    return 0.0;
}


// ========================================
// Calculate Basic Travel Time
// ========================================

double calculateTravelTime(
    double distance,
    double averageSpeed
)
{
    return distance / averageSpeed;
}


// ========================================
// Adjust Travel Time According to Traffic
// ========================================

double adjustTravelTime(
    double estimatedTime,
    int trafficChoice
)
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
// Display Location Information
// ========================================

void displayLocationInformation()
{
    cout << "========== LOCATION INFORMATION =========="
         << endl;

    cout << "\n1. MMU Cyberjaya" << endl;
    cout << "   Multimedia University campus in Cyberjaya."
         << endl;
    cout << "   Where students study, rush assignments and survive deadlines."
         << endl;

    cout << "\n2. IOI City Mall" << endl;
    cout << "   A popular shopping and entertainment destination in Putrajaya."
         << endl;
    cout << "   A popular shopping mall in Putrajaya with many shops, restaurants and fun activities."
         << endl;
    
    cout << "\n3. TRX" << endl;
    cout << "   A major commercial and financial area in Kuala Lumpur."
         << endl;
    cout << "   A modern business, shopping and lifestyle district in Kuala Lumpur."
         << endl;

    cout << "\n4. KLCC" << endl;
    cout << "   A major commercial and tourist area in Kuala Lumpur."
         << endl;
    cout << "   A popular city area known for the Petronas Twin Towers."
         << endl;

    cout << "\n5. Pasar Seni" << endl;
    cout << "   A well-known cultural and transportation area in Kuala Lumpur."
         << endl;
    cout << "   A cultural area where you can explore local art, food and souvenirs.."
         << endl;

    cout << "\n==========================================="
         << endl;
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

    cout << "\n========== PLAN YOUR ROUTE =========="
         << endl;

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

    navigationAdvice = getNavigationAdvice(
        trafficChoice,
        distance,
        transportChoice
    );


    // CALCULATE BASIC TRAVEL TIME

    estimatedTime = calculateTravelTime(
        distance,
        averageSpeed
    );


    // ADJUST TIME ACCORDING TO TRAFFIC CONDITION

    estimatedTime = adjustTravelTime(
        estimatedTime,
        trafficChoice
    );


    // CALCULATE TRAVEL COST

    travelCost = calculateFuelCost(
        distance,
        transportChoice
    );


    // SIMULATE GPS CALCULATION

    cout << "\nCalculating route..." << endl;

    this_thread::sleep_for(
        chrono::seconds(2)
    );

    cout << "Route calculated successfully!" << endl;

    this_thread::sleep_for(
        chrono::seconds(1)
    );


    // PRINT INFORMATION

    cout << fixed << setprecision(2);

    cout << "\n========== GPS TRAVEL RESULT =========="
         << endl;

    cout << "From: "
         << getLocationName(start)
         << endl;

    cout << "To: "
         << getLocationName(destination)
         << endl;

    cout << "Distance: "
         << distance
         << " km"
         << endl;

    cout << "Transportation: "
         << transport
         << endl;

    cout << "Average Speed: "
         << averageSpeed
         << " km/h"
         << endl;

    cout << "Traffic Condition: "
         << traffic
         << endl;

    cout << "\nEstimated Travel Time: "
         << estimatedTime * 60
         << " minutes"
         << endl;

    cout << "Estimated Travel Cost: RM "
         << travelCost
         << endl;

    cout << "Recommended Route: "
         << recommendedRoute
         << endl;

    cout << "Navigation Advice: "
         << navigationAdvice
         << endl;

    cout << "========================================"
         << endl;
}