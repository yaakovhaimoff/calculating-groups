#include "basicsInc/Product.hpp"

//________________________________________________________________________
vector<int> Product::calculate(const vector<int>& a, const vector<int>& b)
{
	auto result = std::vector<int>();
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			result.push_back(a[i] * b[j]);
		}
	}
	std::ranges::sort(result);
	auto [newEnd, end] = std::ranges::unique(result);
	result.erase(newEnd, end);
	return result;
}
//________________________________
void Product::print(char& capital)
{
	cout << "(" << ++capital << " * " << ++capital << ")";
}
//____________________________
string Product::addOperation()
{
	return " * ";
}