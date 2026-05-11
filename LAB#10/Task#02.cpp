#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ifstream fin("notes.txt");
	string line;
	int lineCount = 0;
	while (getline(fin, line))
	{
		lineCount++;
	}
	fin.close();
	cout<<"Total Lines : "<<lineCount<<endl;
}
