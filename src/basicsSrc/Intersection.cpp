#include "basicsInc/Intersection.hpp"

Intersection::Intersection()
{
}
vector<int> Intersection::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	std::ranges::set_intersection(a, b, std::back_inserter(result));

	return result;
}