#include <iostream>
using namespace std;

class Rectangle
{
	private:
		float length;
		float width;
	public:
		Rectangle()
		{
			length = 1.0;
			width = 1.0;
		}
		
		Rectangle(float l,float w)
		{
			length = l;
			width = w;
		}
		
		Rectangle(float lw)
		{
			length = lw;
			width = lw;
		}
		
		float Area()
		{
			return length*width;
		}
		
		void displayArea()
		{	
			cout<<"Length : "<<length<<endl;
			cout<<"Width  : "<<width<<endl;
			cout<<"Area   : "<<Area()<<endl;
		}
};

int main()
{
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"Dimensions and Areas of  Rectangles"<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

	cout<<"~~~~~~~~~~~~Rectangle 1~~~~~~~~~~~~"<<endl;
	//default constructor....
	Rectangle r1;
	r1.Area();
	r1.displayArea();
	cout<<endl;
	
	cout<<"~~~~~~~~~~~~Rectangle 2~~~~~~~~~~~~"<<endl;
	//parameterized constructor....(with two parameters)
	Rectangle r2(2.5,3.6);
	r2.Area();
	r2.displayArea();
	cout<<endl;
	
	cout<<"~~~~~~~~~~~~Rectangle 3~~~~~~~~~~~~"<<endl;
	//parameterized constructor....(with one parameter)
	Rectangle r3(5.5);
	r3.Area();
	r3.displayArea();
	cout<<endl;
	
	return 0;
}
