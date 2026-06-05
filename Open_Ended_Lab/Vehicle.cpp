#include "Vehicle.h"

using namespace std;

// constructor to initialize make and dailyRate
Vehicle::Vehicle(const string& make, double dailyRate)
    : make(make), dailyRate(dailyRate), available(true) {}

// gets the make of the vehicle
string Vehicle::getMake() const {
    return make;
}

// gets the daily rate of the vehicle
double Vehicle::getDailyRate() const {
    return dailyRate;
}

// checks if the vehicle is available for rent
bool Vehicle::isAvailable() const {
    return available;
}

// sets the availability status of the vehicle
void Vehicle::setAvailable(bool status) {
    available = status;
}
