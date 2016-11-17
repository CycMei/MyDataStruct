#include "Median.h"
#include<iostream>
#include<random>

Median::Median(std::vector<int> &vec):m_Vec(vec) {

}

Median::~Median() {

}

int Median::MinMum() {
	int min = m_Vec[0];
	for (int i = 1; i != m_Vec.size(); ++i) {
		if (min > m_Vec[i]) {
			min = m_Vec[i];
		}
	}
	return min;
}

int Median::MaxMum() {
	int max = m_Vec[0];
	for (int i = 1; i != m_Vec.size(); ++i) {
		if (max < m_Vec[i]) {
			max = m_Vec[i];
		}
	}
	return max;
}

std::vector<int> Median::MinAndMaxMum() {
	int min = 0;
	int max = 0;
	if (m_Vec.size() / 2) {
		//ÆæÊý
		min = max = m_Vec[0];
		for (int i = 1; i != m_Vec.size(); ++i) {
			if (min > m_Vec[i]) {
				min = m_Vec[i];
			}
			if (max < m_Vec[i]) {
				max = m_Vec[i];
			}
		}
	}
	else {
		min = m_Vec[0];
		max = m_Vec[1];
		if (min > max) {
			min = m_Vec[1];
			max = m_Vec[0];
		}
		for (int i = 2; i != m_Vec.size(); ++i) {
			if (min > m_Vec[i]) {
				min = m_Vec[i];
			}
			if (max < m_Vec[i]) {
				max = m_Vec[i];
			}
		}
	}
	return std::vector<int>{min, max};
}

int Median::RandomSelect(int begin, int end, const int index) {
	if (begin == end) {
		return m_Vec[begin];
	}
	int q = RandomPartion(begin, end);
	int k = q - begin + 1;
	if (index == k)
		return m_Vec[q];
	else if (index < k)
		return RandomSelect(begin, q - 1, index);
	else
		return RandomSelect(q + 1, end, index-k);
}

int Median::Partition(int begin, int end) {
	if (end >= m_Vec.size() || begin<0) {

	}
	int x = m_Vec[end];
	int i = begin - 1;
	for (int j = begin; j != end; ++j) {
		if (m_Vec[j] < x) {
			i += 1;
			int temp = m_Vec[i];
			m_Vec[i] = m_Vec[j];
			m_Vec[j] = temp;
		}
	}
	int temp = m_Vec[i + 1];
	m_Vec[i + 1] = x;
	m_Vec[end] = temp;
	return i + 1;
}

int Median::RandomPartion(int begins, int ends) {
	std::uniform_int_distribution<unsigned int> u(begins, ends);
	std::default_random_engine e;
	std::cout << e.max() << std::endl;
	int i = u(e);
	std::cout << i << "    ..    " << std::endl;
	int temp = m_Vec[i];
	m_Vec[i] = m_Vec[ends];
	m_Vec[ends] = temp;
	return Partition(begins, ends);
}
