#include "Calculator.hpp"

Calculator::Calculator()
{
	m_operation.resize(3);
	m_operation[0] = make_shared<Union>();
	m_operation[1] = make_shared<Intersection>();
	m_operation[2] = make_shared<Difference>();
}
void Calculator::runCalc()
{
	string userInput;
	cin >> userInput;
	while (userInput != "exit")
	{
		if (userInput == "uni" || userInput == "diff" || userInput == "inter" ||
			userInput == "comp" || userInput == "prod")
		{
			operationWithTwoParameters(userInput);
		}
		else if (userInput == "eval" || userInput == "del")
		{
			operationWithOneParameters(userInput);
		}
		else if (userInput == "help")
		{
			m_print.printHelp();
		}
		else
			cout << "wrong input!\ntry again.\n";
		cin >> userInput;
	}
	cout << "Goodbye" << endl;
}
void Calculator::operationWithTwoParameters(const string userInput)
{
	int firstIndexInArr, secondIndexInArr;
	cin >> firstIndexInArr >> secondIndexInArr;
	if (userInput == "uni")
	{
		m_operation.push_back(make_shared<Union>());
		m_operation[m_operation.size() - 1]->setOperations(m_operation[firstIndexInArr],
			m_operation[secondIndexInArr]);
	}
	else if (userInput == "inter")
	{
		m_operation.push_back(make_shared<Intersection>());
		m_operation[m_operation.size() - 1]->setOperations(m_operation[firstIndexInArr],
			m_operation[secondIndexInArr]);
	}
	else if (userInput == "diff")
	{
		m_operation.push_back(make_shared<Difference>());
		m_operation[m_operation.size() - 1]->setOperations(m_operation[firstIndexInArr],
			m_operation[secondIndexInArr]);
	}
	else if (userInput == "comp")
	{
		m_operation.push_back(make_shared<Composite>());
		m_operation[m_operation.size() - 1]->setOperations(m_operation[firstIndexInArr],
			m_operation[secondIndexInArr]);
	}
	else if (userInput == "prod")
	{
		m_operation.push_back(make_shared<Product>());
		m_operation[m_operation.size() - 1]->setOperations(m_operation[firstIndexInArr],
			m_operation[secondIndexInArr]);
	}
}
void Calculator::operationWithOneParameters(const string userInput)
{
	int indexInArrToRunOperationOn;
	cin >> indexInArrToRunOperationOn;
	if (userInput == "eval")
		calculateOperations(indexInArrToRunOperationOn);
	/*else
		m_operation[indexInArrToRunOperationOn].erase*/
}
void Calculator::calculateOperations(const int indexInArrToRunOperationOn)
{
	string s;
	bool complex = true;
	auto result = m_operation[indexInArrToRunOperationOn]->eval(
		m_operation[indexInArrToRunOperationOn]->getLeftOperation(),
		m_operation[indexInArrToRunOperationOn]->getRightOperation(), s, complex);
	/*if (complex)
		cout << m_operation[indexInArrToRunOperationOn]->setComplexOperation(s);
	else*/
		cout << s;
	m_print.printArr(result);
}