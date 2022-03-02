#include "Set.hpp"

Set::Set()
{
	buildSet();
	setSort();
	setUnique();
}
void Set::buildSet()
{
	int sizeOfArrFromInput, inputToArr;
	cin >> sizeOfArrFromInput;
	for (int i = 0; i < sizeOfArrFromInput; i++)
	{
		cin >> inputToArr;
		m_arrInput.push_back(inputToArr);
	}
}
void Set::setSort()
{
	std::ranges::sort(m_arrInput);
}
void Set::setUnique()
{
	auto [newEnd, end] = std::ranges::unique(m_arrInput);
	m_arrInput.erase(newEnd, end);
}
vector<int> Set::getArr()const
{
	return m_arrInput;
}