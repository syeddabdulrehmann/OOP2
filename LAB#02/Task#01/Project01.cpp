#include <iostream>
#include "header1.h"
using namespace std;

int main()
{
	
	Student s1,s2;
	s1.getData();
	s2.getData();
	
	cout<<"*******************"<<endl;
	cout<<"**Student Records**"<<endl;
	cout<<"*******************"<<endl;
	
	s1.displayData();
	s2.displayData();
	
	return 0;
}
