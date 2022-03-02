#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Union : public Operation
{
public:
	Union();
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
