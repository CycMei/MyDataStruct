#ifndef HEAPSORT_H
#define HEAPSORT_H
#include<vector>
class HeapSort {
public:
	using const_uint = const unsigned int;
	using vec_UInt = std::vector<unsigned int>;
	using uint = unsigned int;

	explicit HeapSort(const vec_UInt &vec);
	~HeapSort();
	void MaxHeapify(const_uint index);
	void coutHeapifyResult();

private:
	//index 代表下标
	const_uint Parent(const_uint index) const {
		return (index / 2)-1;
	}
	const_uint Left(const_uint index) const {
		return (2 * index + 1);
	}
	const_uint Right(const_uint index) const {
		return (2 * index + 2);
	}
	vec_UInt m_Vec;
};
#endif // !HEAPSORT_H
