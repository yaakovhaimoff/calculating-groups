#include "basicsInc/Union.hpp"


//Union::Union()
//{
//}

Union::~Union()
{
}
vector<int> Union::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_union(a, b, std::back_inserter(result));

	return result;
}