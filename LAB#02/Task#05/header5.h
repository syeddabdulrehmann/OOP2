#ifndef HEADER5_H
#define HEADER5_H
#include <iostream>
using namespace std;

class Calculator
{
	public:
		float n1,n2;
		float add();
		float subtract();
		float product();
		float divide();
		
		void inputData()
		{
			cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
			cout<<"Enter The First Number : ";
			cin>>n1;
			cout<<"Enter The Second Number : ";
			cin>>n2;
		}
		
};

	float Calculator::add()
	{
	return n1+n2;
	}
	float Calculator::subtract()
	{ 
	return n1-n2;
	}
	float Calculator::product()
	{ 
	return n1*n2;
	}
	float Calculator::divide()
	{
		if(n2!=0)
		{
			return n1/n2;
		}
		else
		{
			cout<<"Error! Division by Zero."<<endl;
		}
	}
#endif
