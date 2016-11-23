#ifndef INSERTSORT_H
#define INSERTSORT_H
#include<vector>


class InsertSort {
public:
	explicit InsertSort(const std::vector<int>&);
	~InsertSort();
	bool InserSort();
	void addToBin();
	void printvArr();
	bool isPowerToTwo(const int);
private:
	std::vector<int> vArr;
};
#endif // !INSERTSORT_H
