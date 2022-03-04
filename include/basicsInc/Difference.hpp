#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Difference : public Operation
{
public:
	Difference() : Operation("-") {}
	string addOperation()override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};

