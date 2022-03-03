#include "basicsInc/Union.hpp"

void Union::setOperation(const vector<int>& a, const vector<int>& b, string& s)
{
	string operation;
	s += "(" + setPrint(a, operation) + "U " + setPrint(b, operation) + ") ";
}
string Union::setComplexOperation(string& s)
{
	//	string operation;
	/*s += "(" + s + "U " + s + ") ";
	return s;*/
	return "(" + s + "U " + s + ") ";
}
vector<int> Union::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_union(a, b, std::back_inserter(result));
	
	return result;
}