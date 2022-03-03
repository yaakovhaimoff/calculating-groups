#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Product : public Operation
{
public:
	Product(){}
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};