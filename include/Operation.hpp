#pragma once 
#include "Macros.hpp"

class Operation
{
public:
	Operation();
	void setOperations(const shared_ptr <Operation>&, const shared_ptr <Operation>&);
	void setSizeOfOperation(const int);
	int getSizeOfOPeration()const { return m_size; }
	bool returnSharedPtrLeftVal()const;
	bool returnSharedPtrRightVal()const;
	virtual ~Operation();
	
	virtual vector<int> calculate(const vector<int>&, const vector<int>&);
	
private:
	shared_ptr <Operation> m_leftOperation, m_rightOperation;
	int m_size;
};