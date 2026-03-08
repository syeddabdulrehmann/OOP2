#include <iostream>
using namespace std;

// Display class to show results
class Display {
private:
    int lastResult;
public:
    Display() : lastResult(0) {}

    void showResult(int result) {
        lastResult = result;
        cout << "Result: " << result << endl;
    }

    int getLastResult() { return lastResult; }
};

// Calculator *owns* the Display (composition)
class Calculator {
private:
    Display display;  // Composition
public:
    int add(int a, int b) {
        int result = a + b;
        display.showResult(result);
        return result;
    }

    int multiply(int a, int b) {
        int result = a * b;
        display.showResult(result);
        return result;
    }

    int getLastResult() { return display.getLastResult(); }
};



