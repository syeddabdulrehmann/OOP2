#include <iostream >
using namespace std;

struct Student
{
	
	string First_name;
	string Last_name;
	int Age;
	float Marks;	
	
	void displayStudentInfo(Student student)
	{
		
		cout<<"Student Full Name : "<<student.First_name<<" "<<student.Last_name<<endl;
		cout<<"Age : "<<student.Age<<endl;
		cout<<"Marks : "<<student.Marks<<endl;
	}
}s1,s2;

int main()
{
	
	//First Student
	s1.First_name = "Abdul";
	s1.Last_name = "Rehman";
	s1.Age = 20;
	s1.Marks = 30.5;
	s1.displayStudentInfo(s1);
	
	cout<<endl;
	cout<<"***********************************"<<endl;
	cout<<endl;
	
	//Second Student
	s2.First_name = "Afzal";
	s2.Last_name = "Ahmad";
	s2.Age = 22;
	s2.Marks = 37;
	s2.displayStudentInfo(s2);
	
	return 0;
} 
