#include "CountSort.h"
#include<iostream>

CountSort::CountSort(const std::vector<int> &vec) :m_Vec(vec) {
	int max = vec[0];
	for (const auto &c : vec) {
		if (max < c)
			max = c;
	}
	MaxNum = max;
	std::cout << " max max ...   " << MaxNum << std::endl;
}

void CountSort::countSort() {
	std::vector<int> cm_Vec(MaxNum+1, 0);
	for (const auto c : m_Vec)
		cm_Vec[c] += 1;
	for (int i = 1; i != cm_Vec.size(); ++i)
		cm_Vec[i] += cm_Vec[i - 1];
	std::vector<int> copyVec(m_Vec.size()+1, 0);
	for (int j = m_Vec.size() - 1; j >= 0; --j) {
		copyVec[cm_Vec[m_Vec[j]]] = m_Vec[j];
		cm_Vec[m_Vec[j]] -= 1;
	}
	m_Vec.swap(copyVec);
}

void CountSort::printVec() {
	for (const auto &c : m_Vec)
		std::cout << c << "   ";
}
