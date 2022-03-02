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
		if (userInput == "uni" || userInput == "diff" || userInput == "intersection" ||
			userInput == "comp" || userInput == "product")
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
		cin >> userInput;
	}
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
	else if (userInput == "intersection")
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
}
void Calculator::operationWithOneParameters(const string userInput)
{
	int indexInArrToRunOperationOn;
	cin >> indexInArrToRunOperationOn;
	if (userInput == "eval")
	{
		calculateOperations(indexInArrToRunOperationOn);
	}
	else
	{

	}
}
void Calculator::calculateOperations(const int indexInArrToRunOperationOn)
{
	auto result = m_operation[indexInArrToRunOperationOn]->eval(
		m_operation[indexInArrToRunOperationOn]->getLeftOperation(),
		m_operation[indexInArrToRunOperationOn]->getRightOperation());
	m_print.printArr(result);
}
Calculator::~Calculator()
{
}