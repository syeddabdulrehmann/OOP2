#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string customerID;
    bool hasActiveRental;

public:
    // constructor to initialize customer details
    Customer(const std::string& name, const std::string& id);

    // gets the name of the customer
    std::string getName() const;

    // gets the ID of the customer
    std::string getID() const;

    // gets whether the customer has an active rental
    bool getHasActiveRental() const;

    // sets whether the customer has an active rental
    void setHasActiveRental(bool val);
};

#endif // CUSTOMER_H
