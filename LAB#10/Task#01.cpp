#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//writing mode...
	ofstream fout("notes.txt");
	fout<<"Hello! How are You?"<<endl;
	fout<<"I'm a Software Engineering Student."<<endl;
	fout<<"Thank You!"<<endl;
	fout.close();
	
	//reading mode...
	ifstream fin("notes.txt");
	
	string line;
	cout<<"File Data : "<<endl;
	
	while (getline(fin,line))
	{
		cout<<line<<endl;
	}
	fin.close();
	
	//appending data...
	ofstream append("notes.txt" , ios::app);
	append<<"Name : Syed Muhammad Abdulrehman"<<endl;
	append<<"Roll NO : 2024-SE-18"<<endl;
	append.close();
	
	cout<<"Data Successfully Appended."<<endl;
		
	return 0;
}
