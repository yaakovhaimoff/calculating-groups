#pragma once
#include "Macros.hpp"

class Set
{
public:
	Set();
	vector<int> getArr()const;

private:
	void buildSet();
	void setSort();
	void setUnique();
	vector<int> m_arrInput;
};

