#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int seats;

public:
    // constructor to initialize car details
    Car(const std::string& make, double dailyRate, int seats);

    // displays the car details
    void display() const override;

    // gets the type name of the vehicle
    std::string getType() const override;

    // gets the number of seats in the car
    int getSeats() const;
};

#endif // CAR_H
