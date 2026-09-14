#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Pair 
{
private:
    T first;
    T second;

public:
    // Constructor...
    Pair(T f, T s) 
	{
        first = f;
        second = s;
    }

    T getFirst() 
	{
        return first;
    }

    T getSecond() 
	{
        return second;
    }

    void display() 
	{
        cout << "First: " << first << " | Second: " << second << endl;
    }
};

int main() 
{
    // Pair of integers...
    Pair<int> p1(20,30);
    p1.display();

    // Pair of doubles...
    Pair<double> p2(3.18, 1.90);
    p2.display();

    // Pair of strings...
    Pair<string> p3("Haris", "Ali");
    p3.display();

    return 0;
}
