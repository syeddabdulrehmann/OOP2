#include <iostream>
using namespace std;

class Employee
{
	private:
		int id;
		string name;
		float salary;
	public:
		Employee()
		{
			id = 111;
			name = "AHMAD";
			salary = 100000; 
		}
		
		void displayDetails()
		{
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"~~~~~~~~Employee Details~~~~~~~~"<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			
			cout<<"ID : "<<id<<endl;
			cout<<"Name : "<<name<<endl;
			cout<<"Salary : "<<salary<<endl;
			cout<<endl;			
		}
};

int main()
{
	Employee e1;
	e1.displayDetails();
	return 0;
}
