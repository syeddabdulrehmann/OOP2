#ifndef HEADER4_H
#define HEADER4_H
#include <iostream>
using namespace std;

class Temperature
{
	public:
		float celsius;
		void inputData();
		float convertToFarenheit();
		void displayResult();
};

	void Temperature::inputData()
	{
		cout<<"Enter the Temperature in Celsius : ";
		cin>>celsius;
	}
	float Temperature::convertToFarenheit()
	{
		return (celsius * 9/5) + 32;
	}
	void Temperature::displayResult()
	{
		cout<<celsius<<" Celsius = "<<convertToFarenheit()<<" Farenheit."<<endl;
	}
#endif
