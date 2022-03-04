#include "Operation.hpp"

Operation::Operation(const string x)
	: m_expresion(x)
{
	m_leftOperation = nullptr;
	m_rightOperation = nullptr;
}
void Operation::setOperations(const shared_ptr <Operation>& left,
	const shared_ptr <Operation>& right)
{
	m_leftOperation = left;
	m_rightOperation = right;

	m_expresion = (*left).m_expresion + m_expresion + (*right).m_expresion;
}
shared_ptr <Operation> Operation::getLeftOperation()const
{
	return m_leftOperation;
}
shared_ptr <Operation> Operation::getRightOperation()const
{
	return m_rightOperation;
}
vector<int> Operation::eval(const shared_ptr <Operation>& left, const shared_ptr <Operation>& right, string& groups, bool complex)
{
	if (left != nullptr && right != nullptr)
	{
		vector<int> a = left->eval(left->getLeftOperation(), right->getRightOperation(), groups, complex);
		if (complex)
			setComplexOperation(groups, true);
		vector<int> b = right->eval(left->getLeftOperation(), right->getRightOperation(), groups, complex);
		if (complex)
			setComplexOperation(groups, false);
		return calculate(a, b);
	}
	else
	{
		complex = false;
		Set a, b;
		setOperation(a.getArr(), b.getArr(), groups);
		return calculate(a.getArr(), b.getArr());
	}
}
string Operation::setPrint(const vector<int>& a, string& s)
{
	return m_print.setGroup(a, s);
}
void Operation::setOperation(const vector<int>& a, const vector<int>& b, string& s)
{
	string operation1, operation2;
	s += "(" + setPrint(a, operation1) + addOperation() + setPrint(b, operation2) + ")";
}
void Operation::setComplexOperation(string& s, bool start)
{
	string operation;
	if (start)
	{
		operation = "(" + s + addOperation();
		s = operation;
	}
	else
	{
		operation += s + ")";
		s = operation;
	}
}
vector<int> Operation::calculate(const vector<int>& a, const vector<int>& b)
{
	return a;
}
string Operation::addOperation()
{
	return "";
}