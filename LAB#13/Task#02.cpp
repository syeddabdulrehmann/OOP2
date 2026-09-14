#include <iostream>
using namespace std;

// Function template to find minimum of two values....
template <typename T>
T findMin(T a, T b) 
{
    if (a < b) 
	{
        return a;
    }
	 else 
	{
        return b;
    }
}

int main() 
{
    // Testing with integers...
    cout << "Min int (15, 8): " << findMin(15, 8) << endl;

    // Testing with doubles...
    cout << "Min double (4.2, 9.1): " << findMin(4.2, 9.1) << endl;

    // Testing with characters...
    cout << "Min char ('x', 'c'): " << findMin('x', 'c') << endl;

    return 0;
}
