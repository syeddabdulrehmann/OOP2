#include <iostream>
#include "header2.h"
using namespace std;

int main()
{
	
	//for first rectanglular figure.
	Rectangle r1;
	cout<<"***********"<<endl;
	cout<<"***INPUT***"<<endl;
	cout<<"***********"<<endl;
	r1.input();
	cout<<"***********"<<endl;
	cout<<"***OUTPUT**"<<endl;
	cout<<"***********"<<endl;
	r1.displayArea();
	r1.displayPerimeter();
	return 0;
}
