#pragma once
#include "Data.h"
#include "Coder.h"
#include "Decoder.h"
#include <fstream>
#include <iostream>
typedef Data(*ConversionFunction)(Data d);
class Compressor
{
	Coder coder;
	Decoder decoder;

};

