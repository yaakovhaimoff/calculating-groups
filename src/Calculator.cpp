#include "Calculator.hpp"

Calculator::Calculator()
{
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
		m_operation[m_operation.size() - 1]->setSizeOfOperation(m_operation[firstIndexInArr]->getSizeOfOPeration() +
			m_operation[secondIndexInArr]->getSizeOfOPeration());
	}
}
void Calculator::operationWithOneParameters(const string userInput)
{
	int indexInArrToRunOperationOn;
	cin >> indexInArrToRunOperationOn;
	if (userInput == "eval")
	{
		evalFunc(indexInArrToRunOperationOn);
	}
	else
	{

	}
}
void Calculator::evalFunc(const int indexInArrToRunOperationOn)
{
	vector<vector<int>> arrInput;
	int sizeOfArrFromInput, inputToArr;
	for (int i = 0; i < m_operation[indexInArrToRunOperationOn]->getSizeOfOPeration(); i++)
	{
		cin >> sizeOfArrFromInput;
		for (int j = 0; j < sizeOfArrFromInput; j++)
		{
			cin >> inputToArr;
			arrInput[i].push_back(inputToArr);
		}
	}
	//m_operation[indexInArrToRunOperationOn]->calculate()
}
Calculator::~Calculator()
{
}