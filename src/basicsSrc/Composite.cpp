#include "basicsInc/Composite.hpp"

//____________________________________
void Composite::printEx(char& capital)
{
	if (this->getLeftOperation() != nullptr && this->getRightOperation() != nullptr)
	{
		this->getLeftOperation()->printEx(capital);
		cout << this->addOperation();
		this->getRightOperation()->printEx(capital);
	}
	else
		this->print(capital);
}
//_________________________________________
vector<int> Composite::eval(string& groups)
{
	vector<int> a = getLeftOperation()->eval(groups);
	groups += addOperation();
	Set b;
	getRightOperation()->setOperation(a, b.getArr(), groups);
	groups += ")";
	return getRightOperation()->calculate(a, b.getArr());
}
//______________________________
string Composite::addOperation()
{
	return " -> ";
}
//__________________________________
void Composite::print(char& capital)
{
	cout << "(" << ++capital << " -> " << ++capital << ")";
}