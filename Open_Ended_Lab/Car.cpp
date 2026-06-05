#include "Car.h"
#include <iostream>

using namespace std;

// constructor to initialize car details
Car::Car(const string& make, double dailyRate, int seats)
    : Vehicle(make, dailyRate), seats(seats) {}

// displays the car details
void Car::display() const {
    cout << "[CAR] " << getMake() 
         << " | Seats: " << seats 
         << " | Rate: $" << getDailyRate() << "/day"
         << " | Available: " << (isAvailable() ? "Yes" : "No") << endl;
}

// gets the type name of the vehicle
string Car::getType() const {
    return "Car";
}

// gets the number of seats in the car
int Car::getSeats() const {
    return seats;
}
