#include <iostream>
using namespace std;

// Calculator provided by teacher (shared by all students)
class SharedCalculator {
public:
    int add(int a, int b) { return a + b; }
    int multiply(int a, int b) { return a * b; }
};

// Student refers to the shared calculator but does not own it
class Student {
private:
    string name;
    SharedCalculator* calc; // Aggregation (reference, not ownership)
public:
    Student(string n, SharedCalculator* c) : name(n), calc(c) {}

    void solveAddition(int a, int b) {
        cout << name << " solved addition: " << a << " + " << b
             << " = " << calc->add(a, b) << endl;
    }

    void solveMultiplication(int a, int b) {
        cout << name << " solved multiplication: " << a << " * " << b
             << " = " << calc->multiply(a, b) << endl;
    }
};

