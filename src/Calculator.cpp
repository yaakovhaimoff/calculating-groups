#include "Calculator.hpp"

//______________________
Calculator::Calculator()
{
	m_operation.resize(3);
	//defines 3 basics operations
	m_operation[0] = make_shared<Union>();
	m_operation[1] = make_shared<Intersection>();
	m_operation[2] = make_shared<Difference>();
}
//main loop function
//________________________
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

//manage actions for operations with 2 parameters from the user
//_________________________________________________________________
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

//manage actions for operations with one parameter from the user
//_________________________________________________________________
void Calculator::operationWithOneParameters(const string userInput)
{
	int indexInArrToRunOperationOn;
	cin >> indexInArrToRunOperationOn;
	if (userInput == "eval")
		calculateOperations(indexInArrToRunOperationOn);
	else
		m_operation.erase(m_operation.begin() + indexInArrToRunOperationOn);
}
//evaluates the choosen operation function from the user
//________________________________________________________________________
void Calculator::calculateOperations(const int indexInArrToRunOperationOn)
{
	string s;
	auto result = m_operation[indexInArrToRunOperationOn]->eval(s);
	cout << s;
	m_print.printArr(result);
}
//prints the operations menu
//______________________
void Calculator::print()
{
	char capital = 64;
	cout << "List of available set operations : " << endl;
	for (size_t i = 0; i < m_operation.size(); i++)
	{
		cout << i << ".  ";
		m_operation[i]->printEx(capital);
		cout << endl;
		capital = 64;
	}
	cout << endl << "Enter command('help' for the list of available commands) :";
}