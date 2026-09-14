#include <iostream>
#include <string>
using namespace std;

class Employee 
{
private:
    int empID;
    string empName;

public:
    // Static variable for shared company name...
    static string companyName;

    Employee(int id, string name) 
	{
        empID = id;
        empName = name;
    }

    void displayEmployee() 
	{
        cout << "ID: " << empID << " | Name: " << empName << endl;
    }

    // Static member function...
    static void displayCompany() 
	{
        cout << "Company Name: " << companyName << endl;
    }
};

// Static variable initialization...
string Employee::companyName = "Tech Solutions Ltd.";

int main() 
{
    // Calling static function using class name...
    Employee::displayCompany();
    cout << "-----------------------------------" << endl;

    Employee emp1(101, "Haris");
    Employee emp2(102, "Zainab");

    emp1.displayEmployee();
    emp2.displayEmployee();

    return 0;
}
