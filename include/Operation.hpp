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
	virtual vector<int> eval(const shared_ptr <Operation>&, const shared_ptr <Operation>&, string&, bool);
	string setPrint(const vector<int>&, string&);
	virtual vector<int> calculate(const vector<int>&, const vector<int>&);
	virtual void setComplexOperation(string&, bool) {}
	virtual void setOperation(const vector<int>&, const vector<int>&, string&) {}
	virtual ~Operation() {}

private:
	shared_ptr <Operation> m_leftOperation, m_rightOperation;
	Print m_print;
};