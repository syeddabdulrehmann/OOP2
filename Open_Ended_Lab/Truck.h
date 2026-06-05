#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double payloadTonnes;

public:
    // constructor to initialize truck details
    Truck(const std::string& make, double dailyRate, double payloadTonnes);

    // displays the truck details
    void display() const override;

    // gets the type name of the vehicle
    std::string getType() const override;

    // gets the payload capacity in tonnes
    double getPayloadTonnes() const;
};

#endif // TRUCK_H
