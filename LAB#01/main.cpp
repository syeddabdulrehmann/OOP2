#include <iostream>
#include "aggregation.h"
#include "composition.h"
using namespace std;

int main() {
    cout << "===== Aggregation Task =====" << endl;
    SharedCalculator sharedCalc;
    Student s1("Ahmad", &sharedCalc);
    Student s2("Ayesha", &sharedCalc);

    s1.solveAddition(5, 3);
    s2.solveMultiplication(4, 2);

    cout << "\n===== Composition Task =====" << endl;
    Calculator calc;
    calc.add(10, 7);
    calc.multiply(6, 5);
    cout << "Last result stored in display: " << calc.getLastResult() << endl;

    return 0;
}

