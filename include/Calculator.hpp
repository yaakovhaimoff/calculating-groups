#pragma once
#include "Operation.hpp"
#include "basicsInc/Difference.hpp"
#include "basicsInc/Intersection.hpp"
#include "basicsInc/Union.hpp"
#include "Print.hpp"

class Calculator
{
public:
	Calculator();
	~Calculator();
	void runCalc();
	void operationWithTwoParameters(const string);
	void operationWithOneParameters(const string);
	void calculateOperations(const int);
	void print();

private:
	vector<shared_ptr<Operation>> m_operation;
	Print m_print;
};