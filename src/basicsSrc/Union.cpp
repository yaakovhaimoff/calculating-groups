#include "basicsInc/Union.hpp"

//______________________________________________________________________
vector<int> Union::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_union(a, b, std::back_inserter(result));

	return result;
}
//______________________________
void Union::print(char& capital)
{
	cout << "(" << ++capital << " U " << ++capital << ")";
}
//__________________________
string Union::addOperation()
{
	return " U ";
}