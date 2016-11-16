#include "Median.h"

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
