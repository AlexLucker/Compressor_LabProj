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
	return Code;
}
byte_ GetBinary(string str);
void printTree(ostream& out, map<byte_, string>& t) {
	for (auto& it : t) {
		out << (char)it.first << " : " << it.second <<":"<<GetBinary(it.second) << endl;
	}
}

string reverse(string& str)
{
	string out;
	for (int i = str.length() - 1; i >= 0; i--)
		out += str[i];
	return out;
}

byte_ GetBinary(string str) {
	string r_str{ reverse(str) };
	int n{ 8 - (int)r_str.size() };
	for (int i = 1; i <= n; ++i)
		r_str += "0";
	int k{ 1 };
	int ans{ 0 };
	for (int i = 0; i < 8; ++i){
		ans += (r_str[i]=='1'?1:0) * k;
		k *= 2;
	}
	return ans;
}

string GetStringFromBinary(byte_ b) {
	string str;
	int k{ 7 };
	while (k >= 0)
		str += ((b & (1 << k--)) != 0) ? "1" : "0" ;
	int n{ 7 };
	while (n>0) {
		if (str[n] == '1')
			break;
		n--;
	}
	string ans{ str.substr(0,min(n + 1, 8)) };
	return reverse(ans);
}

map<byte_, byte_> DictionariStandart(map<byte_, string>& dict) {
	map<byte_, byte_> dic;
	for (auto& it : dict)
		dic[it.first] = GetBinary(it.second);
	return dic;
}

map<byte_, byte_> ReverseDictionary(map<byte_, byte_>& dict) {
	map<byte_, byte_> Dic_r;
	for (auto& it : dict)
		Dic_r[it.second] = it.first;
	return Dic_r;
}

Data CodeText(Data& data, map<byte_, byte_>& dict) {
	vector<byte_> ndata;
	int n{ 0 };
	string str;
	
	for (auto& it : data.getData())
		str += GetStringFromBinary(dict[it]);		
	str += "0000000";
	unsigned int sim{ str.size() / 8 };
	for (int i = 0; i <= sim; i++)
		ndata.push_back(GetBinary(str.substr(i * 8, 8)));
	return Data{ ndata };
}
Data CodeText(Data& data, map<byte_, string>& dict) {
	auto d{ DictionariStandart(dict) };
	return CodeText(data, d);
}


Data DecodeText(Data& data, map<byte_, byte_> dict) {
	string str;
	return Data{ str };
}

Data ShenonFano(Data& data)
{
	auto tree{ CreateTreeCode(data) };

	auto Dic{ DictionariStandart(tree) };
	
	auto res{ CodeText(data,Dic) };



	return res;
}

Data ShenonFano(Data&& data)
{
	auto d = data;
	return ShenonFano(d);
}

