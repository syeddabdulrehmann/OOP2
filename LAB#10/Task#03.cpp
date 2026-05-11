#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//reading mode...
	ifstream fin("notes.txt");
	ofstream fout("copy.txt");
	
	string line;
	while (getline(fin, line))
	{
		fout<<line<<endl;
	}
	fin.close();
	fout.close();
	cout<<"File Copied Successfully!"<<endl;
	return 0;
}

