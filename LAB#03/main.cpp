#include <iostream>
#include "product.h"
using namespace std;

int main()
{
	Product p;
	p.setname("");
	p.setprice(-50);
	p.setquantity(-2);
	
	p.setname("Laptop");
	p.setprice(1200.50);
	p.setquantity(5);
	
	cout<<"Product : "<<p.getname()<<endl;
	cout<<"Price : $"<<p.getprice()<<endl;
	cout<<"Quantity : "<<p.getquantity()<<endl;
	
return 0;
}
