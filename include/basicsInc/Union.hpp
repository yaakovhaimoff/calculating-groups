#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Union : public Operation
{
public:
	Union() {}
	void setOperation(const vector<int>&, const vector<int>&, string&)override;
	string setComplexOperation(string&)override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
