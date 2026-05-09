#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
	private:
		string name;
		double salary;
	public:
		Employee(string n, double s)
		{
			name = n;
			salary = s;
		}
		
		void display_employee()
		{
			cout<<"Name : "<<name<<endl;
			cout<<"Salary : $"<<fixed<<setprecision(0)<<salary<<endl;
		}
		
		string getname()
		{
		return name; 
		}
		double getsalary()
		{
		return salary; 
		}
};

class Developer : public Employee
{
	private :
		string programming_language;
	public:
		Developer(string n, double s, string pl) : Employee(n,s)
		{
			programming_language = pl;
		}
		
		void display_developer()
		{
			display_employee();
			cout<<"Programming Language : "<<programming_language<<endl;
		}
		
		string get_prolang()
		{
		return programming_language;
		}
};

class Designer : public Employee
{
	private:
		string design_tool;
	public:
		Designer(string n, double s, string dt) : Employee(n,s)
		{
			design_tool = dt;
		}
		
		void display_designer()
		{
			display_employee();
			cout<<"Design Tool : "<<design_tool<<endl;
		}
		
		string get_designtool()
		{
		return design_tool;
		}
};

int main()
{
	Developer d("Ahmad", 5000000,"C++");
	cout<<"~~~Developer's Information~~~"<<endl;
	d.display_developer();
	
	Designer des("Ali", 7000000, "Canva");
	cout<<"~~~Designer's Information~~~"<<endl;
	des.display_designer();
	
	return 0;
}
