#include "Operation.hpp"

//____________________
Operation::Operation()
{
	m_leftOperation = nullptr;
	m_rightOperation = nullptr;
}
//___________________________________________________________________________________________________
void Operation::setOperations(const shared_ptr <Operation>& left, const shared_ptr <Operation>& right)
{
	m_leftOperation = left;
	m_rightOperation = right;
}
//_______________________________________________________
shared_ptr <Operation> Operation::getLeftOperation()const
{
	return m_leftOperation;
}
//________________________________________________________
shared_ptr <Operation> Operation::getRightOperation()const
{
	return m_rightOperation;

}
// prints the expresion of the current operation
//____________________________________
void Operation::printEx(char& capital)
{
	if (this->m_leftOperation != nullptr && this->m_rightOperation != nullptr)
	{
		cout << "(";
		this->m_leftOperation->printEx(capital);
		cout << this->addOperation();
		this->m_rightOperation->printEx(capital);
		cout << ")";
	}
	else
		this->print(capital);
}
// evaluates the operation 
//_________________________________________
vector<int> Operation::eval(string& groups)
{
	if (this->m_leftOperation != nullptr && this->m_rightOperation != nullptr)
	{
		vector<int> a = this->m_leftOperation->eval(groups);
		setComplexOperation(groups, true);
		vector<int> b = this->m_rightOperation->eval(groups);
		setComplexOperation(groups, false);
		return calculate(a, b);
	}
	else
	{
		Set a, b;
		setOperation(a.getArr(), b.getArr(), groups);
		return calculate(a.getArr(), b.getArr());
	}
}
//_________________________________________________________________________________
void Operation::setOperation(const vector<int>& a, const vector<int>& b, string& s)
{
	string operation1, operation2;
	s += "(" + setPrint(a, operation1) + addOperation() + setPrint(b, operation2) + ")";
}
//_________________________________________________________
string Operation::setPrint(const vector<int>& a, string& s)
{
	return m_print.setGroup(a, s);
}
//________________________________________________________
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