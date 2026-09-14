#include <iostream>
using namespace std;

template <typename T>
class Calculator 
{
private:
    T a;
    T b;

public:
    // Constructor...
    Calculator(T x, T y) 
	{
        a = x;
        b = y;
    }

    T add() 
	{
        return a + b;
    }

    T subtract() 
	{
        return a - b;
    }

    T multiply() 
	{
        return a * b;
    }
};

int main() 
{
    // Testing with integers...
    cout << "--- Integer Calculator (10, 5) ---" << endl;
    Calculator<int> calcInt(10, 5);
    cout << "Add: " << calcInt.add() << endl;
    cout << "Subtract: " << calcInt.subtract() << endl;
    cout << "Multiply: " << calcInt.multiply() << endl;

    // Testing with doubles...
    cout << "\n--- Double Calculator (5.5, 2.5) ---" << endl;
    Calculator<double> calcDouble(5.5, 2.5);
    cout << "Add: " << calcDouble.add() << endl;
    cout << "Subtract: " << calcDouble.subtract() << endl;
    cout << "Multiply: " << calcDouble.multiply() << endl;

    return 0;
}
