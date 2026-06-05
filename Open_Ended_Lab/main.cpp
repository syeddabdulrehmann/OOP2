#include <iostream>
#include <memory>
#include "Vehicle.h"
#include "Car.h"
#include "Motorbike.h"
#include "Truck.h"
#include "Customer.h"
#include "Rental.h"
#include "RentalSystem.h"

using namespace std;

// function template to print details of any displayable item
template <typename T>
void printDetails(const T& item) {
    item.display();
}

int main() {
    // STEP 1 — Create RentalSystem
    RentalSystem rs;

    // STEP 2 — Add 4 vehicles
    rs.addVehicle(make_shared<Car>("Toyota Corolla", 40.0, 5));
    rs.addVehicle(make_shared<Motorbike>("Yamaha R1", 25.0, false));
    rs.addVehicle(make_shared<Truck>("Volvo FH16", 100.0, 20.0));
    rs.addVehicle(make_shared<Car>("Honda Civic", 35.0, 4));

    // STEP 3 — Register 2 customers
    auto ali  = make_shared<Customer>("Ali Khan", "C001");
    auto sara = make_shared<Customer>("Sara Malik", "C002");
    rs.registerCustomer(ali);
    rs.registerCustomer(sara);

    // STEP 4 — Process 2 rentals
    rs.processRental("C001", "Volvo FH16", 5);
    rs.processRental("C002", "Yamaha R1", 10);

    // STEP 5 — Attempt to rent an already-rented vehicle (must show error)
    cout << "\n[TEST] Attempting to rent already-rented Volvo FH16..." << endl;
    rs.processRental("C001", "Volvo FH16", 3);

    // STEP 6 — Print summary (first time)
    cout << "\n[SUMMARY 1]" << endl;
    rs.printSummary();

    // STEP 7 — Return Ali's vehicle
    cout << "\n[RETURN]" << endl;
    rs.returnVehicle("C001");

    // STEP 8 — Print summary (second time, shows change)
    cout << "\n[SUMMARY 2]" << endl;
    rs.printSummary();

    // STEP 9 — Demonstrate function template
    cout << "\n[TEMPLATE DEMO] printDetails:" << endl;
    Car demoCar("Demo Car", 30.0, 4);
    printDetails(demoCar);

    // STEP 10 — Demonstrate runtime polymorphism (base pointer calls virtual method)
    cout << "\n[POLYMORPHISM DEMO] Base pointer calling virtual display():" << endl;
    shared_ptr<Vehicle> vPtr = make_shared<Truck>("Demo Truck", 80.0, 15.0);
    vPtr->display(); // runtime polymorphism: Vehicle* resolves to Truck::display()

    return 0;
}
