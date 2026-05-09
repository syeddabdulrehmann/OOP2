#ifndef HEADER2_H
#define HEADER2_H
#include <iostream>
using namespace std;

class Rectangle
{
	public:
		int length;
		int width;
		void input();
		void displayArea();
		void displayPerimeter();
		
};

	void Rectangle::input()
	{
		
		cout<<"Enter the length : ";
		cin>>length;
		cout<<"Enter the width : ";
		cin>>width;
		
	}
	
	void Rectangle::displayArea()
	{
		
		int area = length*width;
		cout<<"Area of the given Reactangle is : "<<area<<endl;
		
	}
	
	void Rectangle::displayPerimeter(){
		
		int perimeter = 2*(length+width);
		cout<<"Perimeter of the given Rectangle is : "<<perimeter<<endl;
		
	}
#endif
