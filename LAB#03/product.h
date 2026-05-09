#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product
{
	private:
		string name;
		double price;
		int quantity;
	public:
		void setname(string n)
		{
			if(!n.empty())
			{
				name = n;
			}
			else
			{
				cout<<"Warning! The name field is empty."<<endl;
			}
		}
		void setprice(double p)
		{
			if(p>0)
			{
				price = p;
			}
			else
			{
				cout<<"Warning! The price must be greater than zero."<<endl;
			}
		}
		void setquantity(int q)
		{
			if(q>=0)
			{
				quantity = q;
			}
			else
			{
				cout<<"Warning! The quantity cannot be negative."<<endl;
			}
		}
		
		string getname()
		{ 
		return name; 
		}
		double getprice()
		{ 
		return price; 
		}
		int getquantity()
		{ 
		return quantity; 
		}
};
#endif
