#include <iostream>
#include "header5.h"
using namespace std;

int main()
{
	
	Calculator calc;
	int operate;
	bool proceed;
	cout<<"~~~~~~~~~~CALCULATOR~~~~~~~~~~~~"<<endl;
do
{
	calc.inputData();
	cout<<"Choose the Operator to perform the Function : "<<endl;
	cout<<"1 : Addition\n2 : Subtraction\n3 : Product\n4 : Division\nEnter Your Option : ";
	cin>>operate;
	switch(operate)
	{
		case 1:
			cout<<"The Sum is : "<<calc.add()<<endl;
			break;
		case 2:
			cout<<"The Difference is : "<<calc.subtract();
			break;
		case 3:
			cout<<"The Product is : "<<calc.product();
			break;
		case 4:
			cout<<"The Division is : "<<calc.divide();
			break;
		default:
			cout<<"Invalid Operator!"<<endl;
			break;
	}
	cout<<endl;
	cout<<"Do you want to proceed ?(1 : Yes and 0 : No) : ";
	cin>>proceed;
}while(proceed==1);

cout<<"The Calculator is Shutting Down"<<endl;
	
return 0;
}
