#include "Operation.hpp"

Operation::Operation()
{
	m_leftOperation = nullptr;
	m_rightOperation = nullptr;
}
void Operation::setOperations(const shared_ptr <Operation>& left,
	const shared_ptr <Operation>& right)
{
	m_leftOperation = left;
	m_rightOperation = right;
}
shared_ptr <Operation> Operation::getLeftOperation()const
{
	return m_leftOperation;
}
shared_ptr <Operation> Operation::getRightOperation()const
{
	return m_rightOperation;
}
vector<int> Operation::eval(const shared_ptr <Operation>& left, const shared_ptr <Operation>& right, string& groups, bool& complex)
{
	if (left != nullptr && right != nullptr)
	{
		complex = true;
		vector<int> a = left->eval(left->getLeftOperation(), right->getRightOperation(), groups, complex);
		vector<int> b = right->eval(left->getLeftOperation(), right->getRightOperation(), groups, complex);
		return calculate(a, b);
	}
	else
	{
		Set a, b;
		setOperation(a.getArr(), b.getArr(), groups);
		return calculate(a.getArr(), b.getArr());
	}
}
string Operation::setPrint(const vector<int>& a, string& s)
{
	return m_print.setGroup(a, s);
}
string Operation::setComplexOperation(string& s)
{
	return s;
}
vector<int> Operation::calculate(const vector<int>& a, const vector<int>& b)
{ 
	return a;
}