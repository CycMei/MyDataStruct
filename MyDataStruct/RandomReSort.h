#ifndef RANDOMRESORT_H
#define RANDOMRESORT_H
#include<vector>
class RandomReSort {
public:
	RandomReSort();
	~RandomReSort();
	void mSwap(int&, int&);
	void Random_Sort(std::vector<int>&,const int&);
	void myRandomSort();
};
#endif // !RANDOMRESORT_H
