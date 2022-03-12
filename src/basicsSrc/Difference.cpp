#include "basicsInc/Difference.hpp"

//calculate of difference operation
//___________________________________________________________________________
vector<int> Difference::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_difference(a, b, std::back_inserter(result));
	return result;
}
//___________________________________
void Difference::print(char& capital)
{
	cout << "(" << ++capital << " - " << ++capital << ")";
}
//_______________________________
string Difference::addOperation()
{
	return " - ";
}