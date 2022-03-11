#include "basicsInc/Composite.hpp"

//____________________________________
void Composite::printEx(char& capitle)
{
	if (this->getLeftOperation() != nullptr && this->getRightOperation() != nullptr)
	{
		this->getLeftOperation()->printEx(capitle);
		cout << this->addOperation();
		this->getRightOperation()->printEx(capitle);
	}
	else
		this->print(capitle);
}
//_________________________________________
vector<int> Composite::eval(string& groups)
{
	bool composite = true;
	vector<int> a = evalComp(this->getLeftOperation(), groups, composite, a);
	setComplexOperation(groups, true);
	composite = false;
	vector<int> b = evalComp(this->getRightOperation(), groups, composite, a);
	setComplexOperation(groups, false);
	return this->getRightOperation()->calculate(a, b);
}
//evaluate of composite operation
//_____________________________________________________________________________________
vector<int> Composite::evalComp(const shared_ptr <Operation>& operation, string& groups,
	bool& composite, const vector<int>& leftCompArr)
{
	if (operation->getLeftOperation() != nullptr && operation->getRightOperation() != nullptr)
	{
		vector<int> a = evalComp(this->getLeftOperation(), groups, composite, leftCompArr);
		vector<int> b = evalComp(this->getRightOperation(), groups, composite, leftCompArr);
		return operation->calculate(a, b);
	}
	else
	{
		if (composite)
		{
			Set a, b;
			operation->setOperation(a.getArr(), b.getArr(), groups);
			return operation->calculate(a.getArr(), b.getArr());
		}
		else
		{
			composite = true;
			Set b;
			operation->setOperation(leftCompArr, b.getArr(), groups);
			return operation->calculate(leftCompArr, b.getArr());
		}
	}
}
//______________________________
string Composite::addOperation()
{
	return " -> ";
}
//__________________________________
void Composite::print(char& capitle)
{
	cout << "(" << ++capitle << " -> " << ++capitle << ")";
}