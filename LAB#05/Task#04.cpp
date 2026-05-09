#include <iostream>
using namespace std;

class Printer
{
	public:
		void print_document()
		{
			cout<<"Printing Your Document...."<<endl;
		}
};

class Scanner
{
	public:
		void scan_document()
		{
			cout<<"Scanning Your Document...."<<endl;
		}
};

class Photocopier : public Printer , public Scanner
{
	public:
		void photocopy()
		{
			cout<<"***Photocopier***"<<endl;
			scan_document();
			print_document();
		}
};

int main()
{
	Photocopier p;
	
	//calling individual functions...
	cout<<"***Printer***"<<endl;
	p.print_document();
	cout<<endl;
	cout<<"***Scanner***"<<endl;
	p.scan_document();
	cout<<endl;
	
	//calling a single function to call both of the above functions...
	p.photocopy();
	
	return 0;
}
