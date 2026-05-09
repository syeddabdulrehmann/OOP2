#include <iostream>
using namespace std;

class BankAccount
{
	private:
		string accountNumber;
		string accountHolder;
		double balance;
	public:
		BankAccount(string accountNumber,string accountHolder,double balance)
		{
			this->accountNumber = accountNumber;
			this->accountHolder = accountHolder;
			this->balance = balance;
		}
	void showAccountDetails()
	{
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~Account Details~~~~~~~~~"<<endl;
		cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
		
		cout<<"Account Number  : "<<this->accountNumber<<endl;
		cout<<"Account Holder  : "<<this->accountHolder<<endl;
		cout<<"Account Balance : "<<this->balance<<endl;
	}
};

int main()
{
	BankAccount b1("PK0309800780100","Muhammad Awais",10000);
	b1.showAccountDetails();
	return 0;
}
