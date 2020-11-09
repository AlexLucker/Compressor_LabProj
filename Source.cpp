#include <iostream>
#include "Compressor.h"
#include <fstream>
using namespace std;

int main() {
	Compressor c;
	fstream file1(L"FileTests/Test1.b", ios::binary | ios::in);
	if (file1.is_open())
	{
		{
			char c;
			while (file1 >> c)
				cout << c;
		}
	}
	else
		cerr << "No file" << endl;
	
	return 0;
}