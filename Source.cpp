#include <iostream>
#include "Compressor.h"
#include <fstream>
#include "Utility.h"
#include <sstream>
using namespace std;

void foo_01() {
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

}

void foo_02() {
	string str1{ "Sample text" };
	Data s1(str1);
	auto t = s1.getData();
	cout << str1 << endl;
	cout << "repeat:" << endl;
	for (auto& it : t) {
		cout << it;
	}
	cout << endl;
	
}

void foo_03(){
	stringstream s;
	s << "asd";
	s >> *(new string());

}

void noParam() {
	foo_02();
}




void Parse(int argc, char* argv[]) {

}



int main(int argc, char* argv[]) {
	Utility::PreInit();
	string inputFile;
	string outputFile;
	if (argc == 1)
		noParam();
	else
	{
		if (argc >= 3)
		{
			inputFile = argv[1];
			outputFile = argv[2];
		}
	}

	return 0;
}