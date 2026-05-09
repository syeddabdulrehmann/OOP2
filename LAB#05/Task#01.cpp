#include <iostream>
using namespace std;

class Person 
{
	private:
    	string name;
    	int age;
	public:
		//Constructor....
    	Person()
		{
    		name = "Unknown";
    		age = 0;
		}
		
    	void setPersonData(string n, int a) 
		{
        name = n;
        age = a;
    	}

	    string getName() 
		{ 
		return name; 
		}
	    int getAge() 
		{ 
		return age; 
		}

    	// Display function of Base Class...
	    void display_person_info() 
		{
    	    cout << "~~~~~ Person's Information ~~~~~" << endl;
        	cout << "Name : " << name << endl;
        	cout << "Age  : " << age << endl;
        	cout << endl;
    	}
};

class Student : public Person 
{
	private:
    	string student_id;

	public:
		
		Student() : Person()
		{
			student_id = "Unknown";
		}
		
    	void setStudentData(string id) 
		{
        student_id = id;
    	}

	    // Display function of derived class...
    	void display_student_info() 
		{
        	cout << "~~~~~ Student's Information ~~~~~" << endl;
        	cout << "Name : " << getName() << endl;   // getter use
        	cout << "Age  : " << getAge() << endl;   // getter use
        	cout << "ID   : " << student_id << endl;
        	cout << endl;
    	}
};

int main() 
{
    string name, id;
    int age;

    // Taking input from user...
    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Student ID: ";
    cin >> id;

    // Object creation...
    Student s1;

    // Setting data...
    s1.setPersonData(name, age);
    s1.setStudentData(id);

    // Displaying data...
    s1.display_person_info();
    s1.display_student_info();

    return 0;
}
