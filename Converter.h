#pragma once
#include "Data.h"
typedef Data(*ConversionFunction)(Data d);
class Converter
{
public:
	virtual Data convert(const Data& d) = 0;
	virtual	Data convert(const Data&& d) = 0;
};

