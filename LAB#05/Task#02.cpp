#include <iostream>
using namespace std;

class Person
{
	private:
		string name;
		int age;
	public:
		Person(string n, int a)
		{
			name = n;
			age = a;
		}
		
		void set_data(string n,int a)
		{
			name = n;
			age = a;
		}
		
		void display_person()
		{
			cout<<"Name : "<<name<<endl;
			cout<<"Age  : "<<age<<endl;
		}
		
		string getname()
		{
		return name;
		}
		int getage()
		{
		return age;
		}
};

class Employee : public Person
{
	private:
		string employee_id;
	public:
		Employee(string n,int a, string id) : Person(n,a)
		{
			employee_id = id;
		}
		
		void set_id(string id)
		{
			employee_id = id;
		}
		
		void display_employee()
		{
			display_person();
			cout<<"ID   : "<<employee_id<<endl;
		}
		
		string getemployee_id()
		{
		return employee_id;
		}
};

class Manager : public Employee
{
	private:
		string department;
	public:
		Manager(string n, int a, string id, string d) : Employee(n, a, id)
		{
			department = d;
		}
		
		void set_department(string d)
		{
			department = d;
		}
		
		void display_manager()
		{
			display_employee();
			cout<<"Department : "<<department<<endl;
		}
		
		string getdepartment()
		{
		return department;
		}
};

int main()
{
	string n;
	int a;
	string id;
	string d;
	
	cout<<"Enter Name : ";
	getline(cin,n);
	cout<<"Enter Age : ";
	cin>>a;
	cout<<"Enter ID : ";
	cin>>id;
	cin.ignore();
	cout<<"Enter Department : ";
	getline(cin,d);
	
	//Object creation...
	Manager m("Ali",19,"572786","Software Engineering"); //constructor calling...
	
	m.set_data(n,a);
	m.set_id(id);
	m.set_department(d);
	cout<<"~~~Person Information~~~"<<endl;
	m.display_person();
	cout<<"~~~Employee Information~~~"<<endl;
	m.display_employee();
	cout<<"~~~Manager Information~~~"<<endl;
	m.display_manager();
	
	return 0;
}
