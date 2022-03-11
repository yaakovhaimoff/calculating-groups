#include "basicsInc/Union.hpp"

//______________________________________________________________________
vector<int> Union::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_union(a, b, std::back_inserter(result));

	return result;
}
//______________________________
void Union::print(char& capitle)
{
	cout << "(" << ++capitle << " U " << ++capitle << ")";
}
//__________________________
string Union::addOperation()
{
	return " U ";
}