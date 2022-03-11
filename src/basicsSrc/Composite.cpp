#include "basicsInc/Composite.hpp"

vector<int> Composite::eval(string& groups, bool complex)
{
	if (this->getLeftOperation() != nullptr && this->getRightOperation() != nullptr)
	{
		vector<int> a = this->getLeftOperation()->eval(groups, complex);
		vector<int> b = this->getRightOperation()->eval(groups, complex);
		return calculate(a, b);
	}
	else
	{
		Set a, b;
		return calculate(a.getArr(), b.getArr());
	}
}
void Composite::printEx(char& capitle, bool first)
{
	if (this->getLeftOperation() != nullptr && this->getRightOperation() != nullptr)
	{
		this->getLeftOperation()->printEx(capitle, first);
		if (first)
			cout << this->addOperation();
		this->getRightOperation()->printEx(capitle, first);
	}
	else
	{
		first = false;
		this->print(capitle);
	}
}
string Composite::addOperation()
{
	return " -> ";
}
//vector<int> Composite::calculate(const vector<int>& a, const vector<int>& b)
//{
//	auto result = std::vector<int>();
//	
//	return result;
//}
void Composite::print(char& capitle)
{
	cout << "(" << ++capitle << " -> " << ++capitle << ")";
}