#include <iostream>
#include <string>
using namespace std;

// Function template to print value twice...
template <typename T>
void printTwice(T val) 
{
    cout << val << endl;
    cout << val << endl;
}

int main() 
{
    // Testing with int....
    cout << "--- Int Output ---" << endl;
    printTwice(10);

    // Testing with double...
    cout << "\n--- Double Output ---" << endl;
    printTwice(5.75);

    // Testing with string...
    cout << "\n--- String Output ---" << endl;
    printTwice("Hello World");

    return 0;
}
