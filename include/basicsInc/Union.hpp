#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Union : public Operation
{
public:
	Union();
	~Union();

	vector<int> calculate(const vector<int>& a, const vector<int>& b)override;
};
