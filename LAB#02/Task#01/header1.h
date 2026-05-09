#ifndef HEADER1_H
#define HEADER1_H
#include <iostream>
using namespace std;

class Student
{
	public:
		string name;
		int rollNumber;
		float marks;
		
		void getData()
		{
			
			cout<<"Enter your Name : ";
			cin>>name;
			cout<<"Enter your Roll Number : ";
			cin>>rollNumber;
			cout<<"Enter your Marks (Out of 100) : ";
			cin>>marks;
			
		}
		
		void displayData()
		{
			
			cout<<"Student Name : "<<name<<endl;
			cout<<"Student Roll Number : "<<rollNumber<<endl;
			cout<<"Student Marks : "<<marks<<endl;
			cout<<"--------------------"<<endl;
			
		}
};
#endif
