#pragma once 
#include "Macros.hpp"

class Operation
{
public:
	Operation();
	~Operation();
	
	virtual vector<int> calculate(const vector<int>& a, const vector<int>& b) {}
	
private:
	char m_operation;

};