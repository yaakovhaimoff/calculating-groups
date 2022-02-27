#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Intersection : public Operation
{
public:
	Intersection();
	~Intersection();

	vector<int> calculate(const vector<int>& a, const vector<int>& b)override;
};
