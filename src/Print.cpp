#include "Print.hpp"

void Print::printHelp()
{
	cout <<
		"The available commands are :\n"
		"*eval(uate) num ... - compute the result of function #num on the following\n"
		"set(s); each set is prefixed with the count of numbers to read\n"
		"* uni(on) num1 num2 - Creates an operation that is the union of operation\n"
		"#num1 and operation #num2\n"
		"* inter(section) num1 num2 - Creates an operation that is the intersection\n"
		"of operation #num1 and operation #num2\n"
		"* diff(erence) num1 num2 - Creates an operation that is the difference of\n"
		"operation #num1 and operation #num2\n"
		"* prod(uct) num1 num2 - Creates an operation that returns the product of\n"
		"the items from the results of operation #num1 and operation #num2\n"
		"* comp(osite) num1 num2 - creates an operation that is the composition of\n"
		"operation #num1 and operation #num2\n"
		"* del(ete) num - delete operation #num from the operation list\n"
		"* help - print this command list\n"
		"* exit - exit the program\n\n";
}

void Print::printOperation()
{

}
string Print::setGroup(const vector<int>& arr, string& operation)
{
	for (int i = 0; i < arr.size(); i++)
	{
		if (i == 0)
			operation += "{ ";

		operation += std::to_string(arr[i]);
		if (i == arr.size() - 1)
			operation += " }";
		else
			operation += ", ";
	}
	return operation;
}
void Print::printArr(vector<int>& arr)
{
	if (arr.size() > 0)
		for (int i = 0; i < arr.size(); i++)
		{
			if (i == 0)
				cout << " = { ";
			if (i == arr.size() - 1)
				cout << arr[i] << " }";
			else
				cout << arr[i] << ", ";
		}
	else
		cout << " = {}";
	cout << endl << endl;
}