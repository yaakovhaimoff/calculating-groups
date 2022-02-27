#include "basicsInc/Difference.hpp"

Difference::Difference()
{

}

Difference::~Difference()
{
}
vector<int> Difference::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_difference(a, b, std::back_inserter(result));
	
	return result;
}