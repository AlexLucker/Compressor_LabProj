#include "Coder.h"

Data Coder::convert(const Data& Data)
{
	return function(Data);
}

Data Coder::convert(const Data&& Data)
{
	return function(Data);
}
