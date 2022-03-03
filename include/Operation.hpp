#pragma once 
#include "Macros.hpp"
#include "Set.hpp"

class Operation
{

public:
	Operation();
	void setOperations(const shared_ptr <Operation>&, const shared_ptr <Operation>&);
	shared_ptr <Operation> getLeftOperation()const;
	shared_ptr <Operation> getRightOperation()const;
	virtual vector<int> eval(const shared_ptr <Operation>&, const shared_ptr <Operation>&);
	virtual vector<int> calculate(const vector<int>&, const vector<int>&);
	virtual ~Operation() {}
	
private:
	shared_ptr <Operation> m_leftOperation, m_rightOperation;
};