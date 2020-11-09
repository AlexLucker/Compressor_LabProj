#pragma once
#include "Converter.h"
class Coder : public Converter
{
	ConversionFunction function;
public:
	Data convert(const Data& Data) override;
	Data convert(const Data&& Data) override;
	void setFunction(ConversionFunction fun) override;
};

