#include "Customer.h"

using namespace std;

// constructor to initialize customer details
Customer::Customer(const string& name, const string& id)
    : name(name), customerID(id), hasActiveRental(false) {}

// gets the name of the customer
string Customer::getName() const {
    return name;
}

// gets the ID of the customer
string Customer::getID() const {
    return customerID;
}

// gets whether the customer has an active rental
bool Customer::getHasActiveRental() const {
    return hasActiveRental;
}

// sets whether the customer has an active rental
void Customer::setHasActiveRental(bool val) {
    hasActiveRental = val;
}
