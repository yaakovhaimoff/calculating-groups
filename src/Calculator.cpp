#include "Calculator.hpp"

calculator::calculator()
{
	m_operation[0] = make_shared<Union>();
	m_operation[1] = make_shared<Intersection>();
	m_operation[2] = make_shared<Difference>();
}
void calculator::runCalc()
{
	string userInput;
	cin >> userInput;
	while (userInput != "exit")
	{
		if (userInput == "uni")
		{
		
		}
		else if (userInput == "eval")
		{

		}
		else if (userInput == "diff")
		{

		}
		else if (userInput == "comp")
		{

		}
		else if (userInput == "del")
		{

		}
		else if (userInput == "help")
		{

		}
		cin >> userInput;
	}
}
void calculator::printHelp()
{

}
calculator::~calculator()
{
}