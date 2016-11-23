#include "RandomReSort.h"

#include<random>
#include<iostream>

RandomReSort::RandomReSort() {

}

RandomReSort::~RandomReSort() {

}

inline void RandomReSort::mSwap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void RandomReSort::Random_Sort(std::vector<int> &vec, const int &n) {
	std::default_random_engine e(5000);
	std::uniform_int_distribution<unsigned int> u;
	for (int i = 0; i != n; ++i) {
		std::cout<<"u(e):  " << u(e) % (i + 1) << std::endl;
		mSwap(vec[i], vec[u(e) % (i + 1)]);
		e.seed(i*200);
	}
}

void RandomReSort::myRandomSort() {
	std::vector<int> m_vec{ 1,2,3,4,5,6,7,8,9 };
	Random_Sort(m_vec, m_vec.size());
	for (const auto &c : m_vec) {
		std::cout << c << "   ";
	}
	std::cout << std::endl;
}

double Rand(double dMin, double dMax) {
	double dVal = (double)rand() / RAND_MAX;
	return dMin + dVal*(dMax - dMin);
}