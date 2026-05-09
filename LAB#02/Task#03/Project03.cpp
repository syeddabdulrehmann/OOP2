#include <iostream>
#include "header3.h"
using namespace std;

int main()
{
	
	Voter v1;
	v1.input();
	
	if(v1.isEligible())
	{
		//If person's age is above 18 means true, then it will be eligible.
		cout<<v1.name<<" is eligible to vote."<<endl;
	}
	else
	{
		//If false, then this statement will be printed.
		cout<<v1.name<<" is not eligible to vote."<<endl;
	}
	
	return 0;
}
