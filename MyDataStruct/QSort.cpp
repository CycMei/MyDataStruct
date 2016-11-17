#include "QSort.h"
#include<iostream>
#include<random>
#include<ctime>

QSort::QSort(std::vector<int> m_vec):m_vec(m_vec) {

}

QSort::~QSort() {

}

int QSort::Partition(int begin, int end) {
	if (end >= m_vec.size()||begin<0) {
		
	}
	int x = m_vec[end];
	int i = begin - 1;
	for (int j = begin; j != end; ++j) {
		if (m_vec[j] < x) {
			i += 1;
			int temp = m_vec[i];
			m_vec[i] = m_vec[j];
			m_vec[j] = temp;
		}
	}
	int temp = m_vec[i+1];
	m_vec[i+1] = x;
	m_vec[end] = temp;
	return i + 1;
}

void QSort::qsort(int begins, int ends) {
	if (begins < ends) {
		int q = Partition(begins, ends);
		qsort(begins, q - 1);
		qsort(q + 1, ends);
	}
}

void QSort::copyqsort(int begins, int ends) {
	while (begins<ends) {
 		int q = Partition(begins, ends);
		copyqsort(begins, q - 1);
		begins = q + 1;
	}
}

int QSort::RandomPartion(int begins, int ends) {
	std::uniform_int_distribution<unsigned int> u(begins, ends);
	std::default_random_engine e;
	std::cout << e.max() << std::endl;
	int i = u(e);
	std::cout << i<<"    ..    " << std::endl;
	int temp = m_vec[i];
	m_vec[i] = m_vec[ends];
	m_vec[ends] = temp;
	return Partition(begins, ends);
}

void QSort::RandomQSort(int begins, int ends) {
	if (begins < ends) {
		int q = RandomPartion(begins, ends);
		RandomQSort(begins, q - 1);
		RandomQSort(q + 1, ends);
	}
}

void QSort::printsVec() {
	for (const auto &c : m_vec) {
		std::cout << c << "  ";
	}
	std::cout << std::endl;
}
