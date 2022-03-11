#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Composite : public Operation
{
public:
	Composite() {}
	vector<int> eval(string&)override;
	vector<int> evalComp(const shared_ptr <Operation>& left, string&, bool&, const vector<int>&);
	void printEx(char&);
	string addOperation()override;
	void print(char&)override;
};
