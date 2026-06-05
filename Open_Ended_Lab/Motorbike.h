#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle {
private:
    bool hasCargoBox;

public:
    // constructor to initialize motorbike details
    Motorbike(const std::string& make, double dailyRate, bool hasCargoBox);

    // displays the motorbike details
    void display() const override;

    // gets the type name of the vehicle
    std::string getType() const override;

    // gets whether the motorbike has a cargo box
    bool getHasCargoBox() const;
};

#endif // MOTORBIKE_H
