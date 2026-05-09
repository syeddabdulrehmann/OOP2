#include <iostream>
#include "header4.h"
using namespace std;

int main()
{
	Temperature t1;
	cout<<"*********************************"<<endl;
	cout<<"******TEMPERATURE CONVERTER******"<<endl;
	cout<<"*********************************"<<endl;
	t1.inputData();
	t1.convertToFarenheit();
	t1.displayResult();
	
	return 0;
}
