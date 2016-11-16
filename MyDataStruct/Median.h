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
private:
	std::vector<int> m_Vec;
};
#endif // !MEDIAN_H
