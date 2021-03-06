#pragma once 
#include "Macros.hpp"
#include "Set.hpp"
#include "Print.hpp"

class Operation
{

public:
	Operation();
	void setOperations(const shared_ptr <Operation>&, const shared_ptr <Operation>&);
	shared_ptr <Operation> getLeftOperation()const;
	shared_ptr <Operation> getRightOperation()const;
	virtual vector<int> eval(string&);
	string setPrint(const vector<int>&, string&);
	virtual void setOperation(const vector<int>&, const vector<int>&, string&);
	virtual void printEx(char&);
	virtual vector<int> calculate(const vector<int>&, const vector<int>&);
	virtual string addOperation();
	virtual void print(char&) = 0;
	virtual ~Operation() {}

private:
	shared_ptr <Operation> m_leftOperation, m_rightOperation;
	Print m_print;
};