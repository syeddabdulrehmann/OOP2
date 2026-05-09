#include <iostream>
using namespace std;

class Vehicle
{
	private:
		string brand;
	public:
		Vehicle(string b)
		{
			brand = b;
			cout<<"Constructor of Vehicle Class is Calling.."<<endl;
		}
		
		void display_Vehicle()
		{
			cout<<"Brand : "<<brand<<endl;
		}
				
};

class Car : public Vehicle
{
	private:
		int lights;
	public:
		Car(string b, int l) : Vehicle(b)
		{
			lights = l;
			cout<<"Constuctor of Car Class is Calling.."<<endl;
		}
		
		void display_Car()
		{
			display_Vehicle();
			cout<<"No. of Lights : "<<lights<<endl;
		}
		
};

class ElectricCar : public Car
{
	private:
		int battery;
	public:
		ElectricCar(string b, int l, int batt) : Car(b,l)
		{
			battery = batt;
			cout<<"Constructor of ElectricCar Class is Calling.."<<endl;
		}
		
		void display_ElectricCar()
		{
			display_Car();
			cout<<"Battery Power : "<<battery<<" KWH"<<endl;
		}
		
};

int main()
{
	ElectricCar ec1("TOYOTA", 6 , 2000);
	
	cout<<endl;
	
	cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"~~~Vehicle Details~~~"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
	ec1.display_ElectricCar();
	
	return 0;
}
