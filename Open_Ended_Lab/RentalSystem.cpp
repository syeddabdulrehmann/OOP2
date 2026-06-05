#include "RentalSystem.h"
#include <iostream>
#include <iomanip>

using namespace std;

// R1: adds a vehicle to the fleet
void RentalSystem::addVehicle(const shared_ptr<Vehicle>& v) {
    fleet.add(v);
}

// R2: registers a customer in the system
void RentalSystem::registerCustomer(const shared_ptr<Customer>& c) {
    customers.push_back(c);
}

// R3: processes a rental transaction
bool RentalSystem::processRental(const string& customerID, const string& vehicleMake, int days) {
    // 1. Find customer by ID in customers vector.
    shared_ptr<Customer> customer = nullptr;
    for (const auto& c : customers) {
        if (c && c->getID() == customerID) {
            customer = c;
            break;
        }
    }
    if (!customer) {
        cout << "ERROR: Customer not found." << endl;
        return false;
    }

    // 3. Search fleet.getAvailable() for vehicle whose getMake() == vehicleMake.
    shared_ptr<Vehicle> vehicle = nullptr;
    for (const auto& v : fleet.getAvailable()) {
        if (v && v->getMake() == vehicleMake) {
            vehicle = v;
            break;
        }
    }
    if (!vehicle) {
        cout << "ERROR: Vehicle not available or does not exist." << endl;
        return false;
    }

    // 2. If customer->getHasActiveRental() is true:
    if (customer->getHasActiveRental()) {
        cout << "ERROR: Customer already has an active rental." << endl;
        return false;
    }

    // 4. Create shared_ptr r = make_shared<Rental>(vehicle, customer, days)
    auto r = make_shared<Rental>(vehicle, customer, days);

    // 5. vehicle->setAvailable(false)
    vehicle->setAvailable(false);

    // 6. customer->setHasActiveRental(true)
    customer->setHasActiveRental(true);

    // 7. rentalHistory.push_back(r)
    rentalHistory.push_back(r);

    // 8. Print SUCCESS message
    cout << "SUCCESS: Rental created for " << customer->getName() 
         << " — " << vehicle->getMake() << " for " << days 
         << " days. Total: $" << fixed << setprecision(2) << r->getTotalCost() << endl;

    // 9. return true
    return true;
}

// R5: returns a rented vehicle
bool RentalSystem::returnVehicle(const string& customerID) {
    // 1. Loop through rentalHistory.
    // 2. Find the rental where status == ACTIVE and customer ID matches.
    shared_ptr<Rental> activeRental = nullptr;
    for (const auto& r : rentalHistory) {
        if (r && r->getStatus() == RentalStatus::ACTIVE && r->getCustomer()->getID() == customerID) {
            activeRental = r;
            break;
        }
    }

    // 3. If not found: print error and return false.
    if (!activeRental) {
        cout << "ERROR: No active rental found for this customer." << endl;
        return false;
    }

    // 4. Call rental->getVehicle()->setAvailable(true)
    activeRental->getVehicle()->setAvailable(true);

    // 5. Call rental->getCustomer()->setHasActiveRental(false)
    activeRental->getCustomer()->setHasActiveRental(false);

    // 6. Call rental->closeRental()
    activeRental->closeRental();

    // 7. Print success message.
    cout << "SUCCESS: Vehicle " << activeRental->getVehicle()->getMake() 
         << " returned by " << activeRental->getCustomer()->getName() << "." << endl;

    // 8. return true
    return true;
}

// R6: prints a summary of fleet status and active rentals
void RentalSystem::printSummary() const {
    cout << "\n========== FLEET SUMMARY ==========" << endl;
    cout << "Available vehicles : " << fleet.availableCount() << endl;
    cout << "Rented vehicles    : " << fleet.rentedCount() << endl;
    cout << "\n--- Active Rentals ---" << endl;

    bool hasActive = false;
    for (const auto& r : rentalHistory) {
        if (r && r->getStatus() == RentalStatus::ACTIVE) {
            r->display();
            hasActive = true;
        }
    }

    if (!hasActive) {
        cout << "  No active rentals." << endl;
    }

    cout << "===================================" << endl;
}
