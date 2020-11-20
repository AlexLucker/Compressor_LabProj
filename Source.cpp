#include <iostream>
#include "Compressor.h"
#include <fstream>
#include "Utility.h"
#include <sstream>
#include "CompressionsFunc.h"
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
	string str{ "Самая обычная строка, ничего особенного\n" };
	auto res{ ShenonFano(Data(str))};

}
void foo_04();
void foo_05();
void noParam() {
	foo_04();
}

void foo_04() {
	//string str{ "Иногда я задумаюсь над тем как много мы на самом деле привносим информации в этот мир и чего она нам стоит" };
	string str{ "Повседневная практика показывает, что укрепление и развитие структуры требуют определения и уточнения дальнейших направлений развития. Повседневная практика показывает, что постоянное информационно-пропагандистское обеспечение нашей деятельности позволяет оценить значение направлений прогрессивного развития. Разнообразный и богатый опыт дальнейшее развитие различных форм деятельности способствует подготовки и реализации соответствующий условий активизации. Равным образом постоянное информационно-пропагандистское обеспечение нашей деятельности способствует подготовки и реализации новых предложений. Задача организации, в особенности же постоянный количественный рост и сфера нашей активности представляет собой интересный эксперимент проверки новых предложений." };
	
	Data d{ str };
	auto tree{ CreateTreeCode(d) };
	
	auto textCode{ CodeText(d,tree) };
	cout << string((char*)textCode.getData().data()) << endl;
}
void foo_05() {
	cout << GetStringFromBinary(154) << endl;
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