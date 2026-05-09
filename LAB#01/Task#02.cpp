#include <iostream >
using namespace std;

struct Student
{
	string First_name;
	string Last_name;
	int Age;
	float Marks;
	
	void displayStudentInfo()
	{
		
		cout<<"Student Full Name : "<<First_name<<" "<<Last_name<<endl;
		cout<<"Age : "<<Age<<endl;
		cout<<"Marks : "<<Marks<<endl;
	}
}s1,s2;

int main()
{
	
	//Array of Structure
	Student s[2];
	
	//Data Entry
		for(int i=0;i<2;i++)
	{
		
		cout<<"Enter the Details of Student "<<i+1<<" : "<<endl;
		cout<<"Enter the First Name : ";
		cin>>s[i].First_name;
		cout<<"Enter the Last Name : ";
		cin>>s[i].Last_name;
		cout<<"Enter Your Age : ";
		cin>>s[i].Age;
		cout<<"Enter Your Marks (Out of 100) : ";
		cin>>s[i].Marks;
		cout<<"---------------------------------------"<<endl;
	}
		
	cout<<endl;
	cout<<"*******************************************"<<endl;
	cout<<"\t\tRESULTS"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;

	//Displaying the results
	for (int i=0; i<2; i++)
	{
		s[i].displayStudentInfo();

		cout<<"***********************************"<<endl;
	}
	
	return 0;
} 
