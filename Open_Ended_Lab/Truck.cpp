#include "Truck.h"
#include <iostream>

using namespace std;

// constructor to initialize truck details
Truck::Truck(const string& make, double dailyRate, double payloadTonnes)
    : Vehicle(make, dailyRate), payloadTonnes(payloadTonnes) {}

// displays the truck details
void Truck::display() const {
    cout << "[TRUCK] " << getMake() 
         << " | Payload: " << payloadTonnes << "T"
         << " | Rate: $" << getDailyRate() << "/day"
         << " | Available: " << (isAvailable() ? "Yes" : "No") << endl;
}

// gets the type name of the vehicle
string Truck::getType() const {
    return "Truck";
}

// gets the payload capacity in tonnes
double Truck::getPayloadTonnes() const {
    return payloadTonnes;
}
