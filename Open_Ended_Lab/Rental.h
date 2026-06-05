#ifndef RENTAL_H
#define RENTAL_H

#include <memory>
#include "Vehicle.h"
#include "Customer.h"

// enum representing the status of the rental
enum class RentalStatus { ACTIVE, CLOSED };

class Rental {
private:
    std::shared_ptr<Vehicle> vehicle;
    std::shared_ptr<Customer> customer;
    int days;
    double totalCost;
    RentalStatus status;

public:
    // constructor to link vehicle and customer, calculating cost immediately
    Rental(const std::shared_ptr<Vehicle>& v, const std::shared_ptr<Customer>& c, int days);

    // gets the rented vehicle
    std::shared_ptr<Vehicle> getVehicle() const;

    // gets the renting customer
    std::shared_ptr<Customer> getCustomer() const;

    // gets the rental duration in days
    int getDays() const;

    // gets the total cost of the rental
    double getTotalCost() const;

    // gets the current status of the rental
    RentalStatus getStatus() const;

    // sets the rental status to CLOSED
    void closeRental();

    // displays the details of the rental transaction
    void display() const;
};

#endif // RENTAL_H
