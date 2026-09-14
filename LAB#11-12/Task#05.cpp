#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class...
class HospitalStaff 
{
protected:
    string staffName;

public:
    HospitalStaff(string name) 
	{
        staffName = name;
    }

    // Pure virtual function...
    virtual void performDuty() = 0;
};

// Derived Class 1...
class Doctor : public HospitalStaff 
{
public:
    Doctor(string name) : HospitalStaff(name) {}

    void performDuty() override 
	{
        cout << "Doctor " << staffName << " is examining patients." << endl;
    }
};

// Derived Class 2....
class Nurse : public HospitalStaff 
{
public:
    Nurse(string name) : HospitalStaff(name) {}

    void performDuty() override 
	{
        cout << "Nurse " << staffName << " is taking care of patients." << endl;
    }
};

// Derived Class 3....
class Receptionist : public HospitalStaff 
{
public:
    Receptionist(string name) : HospitalStaff(name) {}

    void performDuty() override 
	{
        cout << "Receptionist " << staffName << " is managing patient appointments." << endl;
    }
};

int main() 
{
    Doctor doc("Saim");
    Nurse nurse("Nida");
    Receptionist recep("Hamid");

    doc.performDuty();
    nurse.performDuty();
    recep.performDuty();

    return 0;
}
