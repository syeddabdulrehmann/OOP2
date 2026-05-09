#include <iostream>
using namespace std;

class Product
{
	private:
		string name;
		float price;
	public:
		Product(string n, float p)
		{
			name = n;
			price = p;
		}
		
		void display_product()
		{
			cout<<"Product Name : "<<name<<endl;
			cout<<"Price        : $"<<price<<endl;
		}
		
		string getname()
		{
		return name;
		}
		float getprice()
		{
		return price;
		}
		
};

class Electronics : public Product
{
	private:
		int warrantyYears;
	public:
		Electronics(string n, float p, int years) : Product(n,p)
		{
			warrantyYears = years;
		}
		
		void display_electronics()
		{
			display_product();
			cout<<"Warranty Years : "<<warrantyYears<<endl;
		}
		
		int getyears()
		{
		return warrantyYears;
		}
		
};

int main()
{
	Electronics cable("C-Type Data Cable", 340.50, 1);
	cout<<"\t*********************"<<endl;
	cout<<"\t***Product Details***"<<endl;
	cout<<"\t*********************"<<endl;
	cable.display_electronics();
	return 0;
}
