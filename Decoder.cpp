#include "Decoder.h"

Data Decoder::convert(const Data& Data)
{
	return function(Data);
}

Data Decoder::convert(const Data&& Data)
{
	return function(Data);
}

void Decoder::setFunction(ConversionFunction fun)
{
	function = fun;
}
