#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Composite : public Operation
{
public:
	Composite() {}
	vector<int> eval(string&, bool)override;
	void printEx(char&, bool);
	string addOperation()override;
	void print(char&)override;
	//vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
