#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Composite : public Operation
{
public:
	Composite() {}
	void printEx(char&);
	vector<int> eval(string&)override;
	string addOperation()override;
	void print(char&)override;
};
