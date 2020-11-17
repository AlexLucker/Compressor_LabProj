#pragma once
#include "Data.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <map>

Data ShenonFano(Data& data);
Data ShenonFano(Data&& data);


struct TwoVectors
{
public:
	std::vector<std::pair<byte_, int>> v1;
	std::vector<std::pair<byte_, int>> v2;
	std::vector<std::pair<byte_, int>>& operator[](int);
	friend std::ostream& operator<<(std::ostream& out, TwoVectors& t);
};

TwoVectors parseVector(std::vector<std::pair<byte_, int>> v);
std::vector<std::pair<byte_, int>> statisticInformation(Data& data);
std::map<byte_, std::string> CreateTreeCode(Data& data);
void printTree(std::ostream& out, std::map<byte_, std::string>& t);