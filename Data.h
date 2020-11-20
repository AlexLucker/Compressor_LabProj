#pragma once
#include <vector>
#include <string>
using byte_ = unsigned char;

class Data
{
private:
	std::vector<byte_> _data;
public:
	Data(std::string str);
	Data(std::vector < byte_> v);
	const std::vector<byte_>& getData();
};

