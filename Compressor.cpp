#include "Compressor.h"
#include <iostream>



Compressor::Compressor(std::istream& in, std::ostream& out): input{in}, output{out}
{
}

std::istream& operator>>(std::istream& input, Compressor& compressor)
{
	return input;
}

std::istream& operator<<(std::istream& output, Compressor& compressor)
{
	return output;
}
