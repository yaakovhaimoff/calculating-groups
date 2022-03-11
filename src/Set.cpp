#include "Set.hpp"

//________
Set::Set()
{
	buildSet();
	setSort();
	setUnique();
}
//build of new group
//__________________
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
//_________________
void Set::setSort()
{
	std::ranges::sort(m_arrInput);
}
//___________________
void Set::setUnique()
{
	auto [newEnd, end] = std::ranges::unique(m_arrInput);
	m_arrInput.erase(newEnd, end);
}
//____________________________
vector<int> Set::getArr()const
{
	return m_arrInput;
}