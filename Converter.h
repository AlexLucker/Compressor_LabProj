#pragma once
#include "Data.h"
class Converter
{
public:
	virtual Data convert(const Data& d) = 0;
	virtual	Data convert(const Data&& d) = 0;
};

