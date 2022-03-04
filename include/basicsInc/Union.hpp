#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"

class Union : public Operation
{
public:
	Union() : Operation("U") {}
	string addOperation()override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
