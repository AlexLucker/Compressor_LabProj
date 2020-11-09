#include "Utility.h"
#include <locale>
#include <cstdlib>
void Utility::PreInit()
{
	setlocale(0, "");
	system("chcp 1251");
	system("cls");
}
