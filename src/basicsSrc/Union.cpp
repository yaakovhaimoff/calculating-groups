#include "basicsInc/Union.hpp"

void Union::setOperation(const vector<int>& a, const vector<int>& b, string& s)
{
	string operation1, operation2;
	s += "(" + setPrint(a, operation1) + " U " + setPrint(b, operation2) + ")";
}
void Union::setComplexOperation(string& s, bool start)
{
	string operation;
	if (start)
	{
		operation = "(" + s + " U ";
		s = operation;
	}
	else 
	{
		operation += s + ")";
		s = operation;
	}
}
vector<int> Union::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_union(a, b, std::back_inserter(result));
	
	return result;
}