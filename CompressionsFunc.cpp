#include "CompressionsFunc.h"
#include <map>
#include <string>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

template <typename T>
struct Tree;

template <typename T>
struct NodeTree
{
	Tree<T>* Tree;
	T value;
	NodeTree* parent;
	NodeTree* left;
	NodeTree* rigth;
};

template <typename T>
struct Tree
{
	list<NodeTree<T>> nodes;
	map<char, string> getDictionary() {

	}
};

int SumWeigth(vector<pair<byte_, int>>& v) {
	int sum{ 0 };
	for (auto& it : v)
		sum += it.second;
	return sum;
}


vector<pair<byte_, int>>& TwoVectors::operator[] (int index) {
	return index == 0 ? v1 : v2;
}

ostream& operator<<(ostream& out, vector<pair<byte_,int>> &t) {
	out << t.size() << endl;
	out << SumWeigth(t) << endl;
	for (auto& it : t)
		out << (char)it.first << ":" << it.second << endl;
	return out;
}

ostream& operator<<(std::ostream& out, TwoVectors& t){
	out << "v1: " << t.v1;
	out << "v2: " << t.v2;
	return out;
}

TwoVectors parseVector(vector<pair<byte_, int>> v) {
	if (v.size() < 2)
		return { v,vector<pair<byte_, int>>() };
	TwoVectors vec;
	int sum[2]{ 0 };
	for (int i = 0; i < v.size(); ++i) {
		int m = sum[0] < sum[1]? 0 : 1;
		vec[m].push_back(v[i]);
		sum[m] += v[i].second;		
	}
	return vec;
}

vector<pair<byte_, int>> statisticInformation(Data& data) {
	auto str{ data.getData() };
	map<byte_, int> dict;

	for (auto& it : str)
		dict[it]++;

	vector<pair<byte_, int>> listSimbolChange;

	for (auto& it : dict)
		listSimbolChange.push_back({ it.first,it.second });
	auto cmp = [](pair<byte_, int>& a, pair<byte_, int>& b) {return a.second > b.second; };

	sort(begin(listSimbolChange), end(listSimbolChange), cmp);

	return listSimbolChange;
}

map<byte_, string> CreateTreeCode(Data& data) {
	map<byte_, string> Code;
	queue<pair<vector<pair<byte_, int>>, string>> mainQ;
	auto stat{ statisticInformation(data) };
	mainQ.push({stat,"" });
	while (!mainQ.empty()) {
		auto& nNode{ mainQ.front() };
		
		if (nNode.first.size() == 1)
			Code[nNode.first[0].first] = nNode.second;
		else
		{
			auto tw{ parseVector(nNode.first) };
			for (int i = 0; i < 2; ++i)
				if (tw[i].size() >= 1)
					mainQ.push({ tw[i],nNode.second + to_string(i) });
		}
		mainQ.pop();
	}
	cout << stat << endl;
	return Code;
}

void printTree(ostream& out, map<byte_, string>& t) {
	for (auto& it : t) {
		out << (char)it.first << " : " << it.second << endl;
	}
}

Data ShenonFano(Data& data)
{
	string res;
	
	

	



	return Data(res);
}

Data ShenonFano(Data&& data)
{
	auto d = data;
	return ShenonFano(d);
}

