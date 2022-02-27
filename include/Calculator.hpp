#pragma once
#include "Operation.hpp"
#include "basicsInc/Difference.hpp"
#include "basicsInc/Intersection.hpp"
#include "basicsInc/Union.hpp"

class calculator
{
public:
	calculator();
	~calculator();
	void runCalc();
	void printHelp();

private:
	vector<shared_ptr<Operation>> m_operation;
};