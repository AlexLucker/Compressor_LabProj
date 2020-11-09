#pragma once
#include "Converter.h"
class Decoder : public Converter
{
public:
	Data convert(const Data& Data) override;
	Data convert(const Data&& Data) override;
};

