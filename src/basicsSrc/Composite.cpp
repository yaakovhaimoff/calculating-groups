#include "basicsInc/Composite.hpp"

//vector<int> Composite::eval(const shared_ptr <Operation>& left, const shared_ptr <Operation>& right)
//{
//	if (left != nullptr && right != nullptr)
//	{
//		vector<int> a = left->eval(left->getLeftOperation(), left->getRightOperation());
//		vector<int> b = right->eval(right->getLeftOperation(), right->getRightOperation());
//		return calculate(a, b);
//	}
//	else
//	{
//		Set a, b;
//		return calculate(a.getArr(), b.getArr());
//	}
//}
string Composite::addOperation()
{
	return " -> ";
}
vector<int> Composite::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	
	return result;
}