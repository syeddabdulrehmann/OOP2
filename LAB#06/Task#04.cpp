#include <iostream>
using namespace std;

class Device
{
	private:
		string *device_name;
		string *device_id;
	public:
		Device(string name, string id)
		{
			device_name = new string(name);
			device_id = new string(id);
			cout<<"Parent Class Constructor, Memory Allocated On Heap..."<<endl;
		}
		
		virtual ~Device()
		{
			delete device_name;
			delete device_id;
			cout<<"Parent Class Ka Destructor Call Hogya Ha..."<<endl;
		}
		
		string getname()
		{ 
		return *device_name; 
		}
		string getid()
		{ 
		return *device_id; 
		}
		
};

class Sensor : public Device
{
	private:
		string *sensor_type;
		float *sensor_value;
	public:
		Sensor(string name, string id, string type, float value):Device(name, id)
		{
			sensor_type = new string(type);
			sensor_value = new float(value);
			cout<<"Child Class Constructor, Memory Allocated On Heap..."<<endl;
		}
		
		~Sensor()
		{
			delete sensor_type;
			delete sensor_value;
			cout<<"Child Class Ka Destructor Call Hogya Ha..."<<endl;
		}
		
		void show_data()
		{
			cout<<"~~~DEVICE DETAILS~~~"<<endl;
			cout<<"Device Name : "<<getname()<<endl;
			cout<<"Device ID   : "<<getid()<<endl;
			cout<<"Sensor Type : "<<*sensor_type<<endl;
			cout<<"Sensor Value: "<<*sensor_value<<endl;
			cout<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
		}
};

int main()
{
	Sensor *s1 = new Sensor("Thermometer", "TH-101", "Temperature(Celcius)", 36.9);
	s1->show_data();
	
	delete s1;
	return 0;
}
