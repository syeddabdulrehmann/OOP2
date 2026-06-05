#include "Motorbike.h"
#include <iostream>

using namespace std;

// constructor to initialize motorbike details
Motorbike::Motorbike(const string& make, double dailyRate, bool hasCargoBox)
    : Vehicle(make, dailyRate), hasCargoBox(hasCargoBox) {}

// displays the motorbike details
void Motorbike::display() const {
    cout << "[MOTORBIKE] " << getMake() 
         << " | CargoBox: " << (hasCargoBox ? "Yes" : "No") 
         << " | Rate: $" << getDailyRate() << "/day"
         << " | Available: " << (isAvailable() ? "Yes" : "No") << endl;
}

// gets the type name of the vehicle
string Motorbike::getType() const {
    return "Motorbike";
}

// gets whether the motorbike has a cargo box
bool Motorbike::getHasCargoBox() const {
    return hasCargoBox;
}
