#pragma once
#include "Data.h"
#include "Coder.h"
#include "Decoder.h"
#include <fstream>
#include <iostream>

class Compressor
{
	Coder coder;
	Decoder decoder;
	std::istream& input;
	std::ostream& output;
public:
	Compressor();
	friend std::istream& operator>>(std::istream& input, Compressor& compressor);
	friend std::istream& operator<<(std::istream& output, Compressor& compressor);
};

