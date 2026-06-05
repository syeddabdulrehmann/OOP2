#include "Rental.h"
#include <iostream>
#include <iomanip>

using namespace std;

// constructor to link vehicle and customer, calculating cost immediately
Rental::Rental(const shared_ptr<Vehicle>& v, const shared_ptr<Customer>& c, int days)
    : vehicle(v), customer(c), days(days) {
    double base = v->getDailyRate() * days;
    if (v->getType() == "Truck") {
        totalCost = base * 1.20;
    } else if (v->getType() == "Motorbike" && days > 7) {
        totalCost = base * 0.90;
    } else {
        totalCost = base;
    }
    status = RentalStatus::ACTIVE;
}

// gets the rented vehicle
shared_ptr<Vehicle> Rental::getVehicle() const {
    return vehicle;
}

// gets the renting customer
shared_ptr<Customer> Rental::getCustomer() const {
    return customer;
}

// gets the rental duration in days
int Rental::getDays() const {
    return days;
}

// gets the total cost of the rental
double Rental::getTotalCost() const {
    return totalCost;
}

// gets the current status of the rental
RentalStatus Rental::getStatus() const {
    return status;
}

// sets the rental status to CLOSED
void Rental::closeRental() {
    status = RentalStatus::CLOSED;
}

// displays the details of the rental transaction
void Rental::display() const {
    ios::fmtflags oldFlags = cout.flags();
    streamsize oldPrecision = cout.precision();

    cout << "  Customer: " << customer->getName() 
         << " | Vehicle: " << vehicle->getMake() 
         << " | Days: " << days 
         << " | Cost: $" << fixed << setprecision(2) << totalCost 
         << " | Status: " << (status == RentalStatus::ACTIVE ? "ACTIVE" : "CLOSED") 
         << endl;

    cout.flags(oldFlags);
    cout.precision(oldPrecision);
}
