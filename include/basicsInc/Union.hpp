#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Union : public Operation
{
public:
	Union() {}
	string addOperation()override;
	void print(char&)override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
