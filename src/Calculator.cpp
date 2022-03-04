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
	print();
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
		print();
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
	else
		m_operation.erase(m_operation.begin() + indexInArrToRunOperationOn);
}
void Calculator::calculateOperations(const int indexInArrToRunOperationOn)
{
	string s;
	bool complex = true;
	auto result = m_operation[indexInArrToRunOperationOn]->eval(
		m_operation[indexInArrToRunOperationOn]->getLeftOperation(),
		m_operation[indexInArrToRunOperationOn]->getRightOperation(), s, complex);
	cout << s;
	m_print.printArr(result);
}
void Calculator::print()
{
	char capitale = 65;
	cout << "List of available set operations : " << endl;
	for (size_t i = 0; i < m_operation.size(); i++)
	{
		cout << i << ".  ";
		for (size_t j = 0; (*m_operation[i]).getExprsion()[j] != '\0'; j++, capitale++)
		{
			if (j % 2 == 0)
				cout << '(' << capitale << (*m_operation[i]).getExprsion()[j] << (char(capitale + 1)) << ')';
			else
				cout << (*m_operation[i]).getExprsion()[j];
		}
		cout << endl;
		capitale = 65;
	}
	cout << endl << "Enter command('help' for the list of available commands) :";
}