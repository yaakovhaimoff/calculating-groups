#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Product : public Operation
{
public:
	Product() {}
	string addOperation()override;
	void print(char&)override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};