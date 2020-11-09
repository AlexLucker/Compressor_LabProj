#include "Compressor.h"
#include <iostream>

Compressor::Compressor() : input {std::cin}, output {std::cout}
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
