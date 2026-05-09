#include <iostream>
using namespace std;

class Locker
{
	public:
		Locker()
		{
			cout<<"Locker allocated to customer.(Constructor Called)"<<endl;
		}
		~Locker()
		{
			cout<<"Locker returned by customer.(Destructor Called)"<<endl;
		}
};

int main()
{
	
	cout<<"~~~First Object (Without using the pointer)~~~"<<endl;
	cout<<"Starting..."<<endl;
	{
		Locker lock1;
	}
	cout<<"Ending..."<<endl;
	
	cout<<endl;
	
	cout<<"~~~Second Object (Using the pointer)~~~"<<endl;
	cout<<"Starting..."<<endl;
	Locker *lock2 = new Locker();
	delete lock2;
	cout<<"Ending..."<<endl;
	
	return 0;
}
