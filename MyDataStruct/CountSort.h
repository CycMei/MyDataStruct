#ifndef COUNTSORT_H
#define COUNTSORT_H
#include<vector>

class CountSort {
public:
	CountSort(const std::vector<int> &vec);
	~CountSort() {

	}
	void countSort();
	void printVec();
private:
	std::vector<int> m_Vec;

	int MaxNum=0;
};
#endif // !COUNTSORT_H
