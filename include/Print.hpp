#pragma once
#include "Macros.hpp"

class Print
{
public:
	Print(){}
	void printHelp();
	string setGroup(const vector<int>&, string&);
	void printOperation();
	void printArr(const vector<int>&);

};
