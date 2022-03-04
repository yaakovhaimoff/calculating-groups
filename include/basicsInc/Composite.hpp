#pragma once 
#include "Macros.hpp"
#include "Operation.hpp"
#include "Set.hpp"

class Composite : public Operation
{
public:
	Composite() : Operation("->") {}
	//vector<int> eval(const shared_ptr <Operation>&, const shared_ptr <Operation>&)override;
	string addOperation()override;
	vector<int> calculate(const vector<int>&, const vector<int>&)override;
};
