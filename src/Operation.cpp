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
vector<int> Operation::eval(const shared_ptr <Operation>& left, const shared_ptr <Operation>& right)
{
	if (left != nullptr && right != nullptr)
	{
		vector<int> a = left->eval(left->getLeftOperation(), right->getRightOperation());
		vector<int> b = right->eval(left->getLeftOperation(), right->getRightOperation());
		return calculate(a, b);
	}
	else
	{
		Set a, b;
		return calculate(a.getArr(), b.getArr());
	}
}
vector<int> Operation::calculate(const vector<int>& a, const vector<int>& b)
{ 
	return a;
}