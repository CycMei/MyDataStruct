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
	void BuildMaxheap();
	void sortHeap();

	//最大优先队列
	const_uint Maximum() const;
	const_uint ExtractMax();
	bool HeapIncreaseKey(int index, uint key);
	bool MaxHeapInsert(uint key);

	void coutHeapifyResult();

private:
	//index 代表下标
	const_uint Parent(const_uint index) const {
		auto res = (index / 2) - 1 <=0 ? 0 : (index / 2) - 1;
		return res;
	}
	const_uint Left(const_uint index) const {
		return (2 * index + 1);
	}
	const_uint Right(const_uint index) const {
		return (2 * index + 2);
	}
	vec_UInt m_Vec;
	uint m_vecSize;
};
#endif // !HEAPSORT_H
