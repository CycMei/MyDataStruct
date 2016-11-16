#ifndef QSORT_H
#define QSORT_H
#include<vector>
class QSort {
public:
	explicit QSort(std::vector<int> m_vec);
	~QSort();
	int Partition(int begin,int end);
	void qsort(int begins, int ends);
	void copyqsort(int begins, int ends);


	int RandomPartion(int begins, int ends);
	void RandomQSort(int begins, int ends);

	void printsVec();
private:
	std::vector<int> m_vec;
};
#endif // !QSORT_H
