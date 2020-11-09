#pragma once
#include "Converter.h"
class Coder : public Converter
{
public:
	Data convert(const Data& Data) override;
	Data convert(const Data&& Data) override;
};

