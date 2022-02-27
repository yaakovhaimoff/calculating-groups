#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Difference:public Operation
{
public:
	Difference();
	~Difference();

	vector<int> calculate(const vector<int>& a, const vector<int>& b)override;
};

