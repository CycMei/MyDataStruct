#ifndef MEDIAN_H
#define MEDIAN_H
#include<vector>
class Median {
public:
	Median(std::vector<int>&);
	~Median();
	int MinMum();
	int MaxMum();
	std::vector<int> MinAndMaxMum();

	int RandomSelect(int, int, const int);
private:
	int Partition(int begin, int end);
	int RandomPartion(int begins, int ends);
	std::vector<int> m_Vec;
};
#endif // !MEDIAN_H
