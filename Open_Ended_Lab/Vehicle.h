#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string make;
    double dailyRate;
    bool available;

public:
    // Constructor to initialise make and daily rate, sets available to true
    Vehicle(const std::string& make, double dailyRate);

    // Virtual destructor
    virtual ~Vehicle() = default;

    // Pure virtual method to display vehicle details
    virtual void display() const = 0;

    // Pure virtual method to get vehicle type string
    virtual std::string getType() const = 0;

    // Getter for make
    std::string getMake() const;

    // Getter for daily rate
    double getDailyRate() const;

    // Getter for availability status
    bool isAvailable() const;

    // Setter for availability status
    void setAvailable(bool status);
};

#endif // VEHICLE_H
