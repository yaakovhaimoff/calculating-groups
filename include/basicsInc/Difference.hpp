#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Difference : public Operation
{
public:
	Difference() {}
	string addOperation()override;
	void print(char&)override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};

