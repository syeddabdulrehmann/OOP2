#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include <vector>
#include <memory>
#include <string>
#include "Fleet.h"
#include "Vehicle.h"
#include "Customer.h"
#include "Rental.h"

class RentalSystem {
private:
    Fleet<Vehicle> fleet;
    std::vector<std::shared_ptr<Customer>> customers;
    std::vector<std::shared_ptr<Rental>> rentalHistory;

public:
    // R1: adds a vehicle to the fleet
    void addVehicle(const std::shared_ptr<Vehicle>& v);

    // R2: registers a customer in the system
    void registerCustomer(const std::shared_ptr<Customer>& c);

    // R3: processes a rental transaction
    bool processRental(const std::string& customerID, const std::string& vehicleMake, int days);

    // R4: Cost calculation is delegated to the Rental constructor.
    // Truck +20%, Motorbike -10% if days > 7, Car no modifier.

    // R5: returns a rented vehicle
    bool returnVehicle(const std::string& customerID);

    // R6: prints a summary of fleet status and active rentals
    void printSummary() const;
};

#endif // RENTALSYSTEM_H
