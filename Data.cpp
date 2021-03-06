#include "Data.h"

Data::Data(std::string str): _data(str.size())
{
	memcpy(_data.data(), str.c_str(), str.size() * sizeof(char));
}

Data::Data(std::vector<byte_> v) : _data{ v } {

}

const std::vector<byte_>& Data::getData()
{
	return _data;
}
