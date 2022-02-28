#include "Operation.hpp"

Operation::Operation()
	: m_size(2)
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
void Operation::setSizeOfOperation(const int size)
{
	m_size = size;
}
bool Operation::returnSharedPtrLeftVal()const
{
	return m_leftOperation==nullptr;
}
bool Operation::returnSharedPtrRightVal()const
{
	return m_rightOperation==nullptr;
}
vector<int> Operation::calculate(const vector<int>& a, const vector<int>& b)
{
	return a;
}
Operation::~Operation()
{
}