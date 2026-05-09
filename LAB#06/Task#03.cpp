#include <iostream>
using namespace std;

class File
{
	private:
		string name;
	public:
		File(string n)
		{
			name = n;
			cout<<"File \""<<name<<"\" is Opened (Base Class Constructor Called)."<<endl;
		}
		
		~File()
		{
			cout<<"File \""<<name<<"\" is Closed (Base Class Destructor Called)."<<endl;
		}
};

class TextFile : public File
{
	private:
		string info;
	public:
		TextFile(string n, string info) : File(n)
		{
			this->info = info;
			cout<<"Text is Loading...(Derived Class Constructor Called)"<<endl;
		}
		~TextFile()
		{
			cout<<"Text has Loaded...(Derived Class Destructor Called)"<<endl;
		}
		
		void display_TextFile()
		{
			cout<<"Content : \""<<info<<"\""<<endl;
		}
};

int main()
{
	{
	TextFile tf("Documents.docx", "It is my Data.");
	tf.display_TextFile();
	cout<<"Object Scope sy bahar janay wala ha..."<<endl;
	}
	cout<<"Object Scope sy bahar jaa chukka ha..."<<endl;
	return 0;
}
