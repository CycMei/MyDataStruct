#include "HeapSort.h"
#include<iostream>

HeapSort::HeapSort(const vec_UInt &vec):m_Vec(vec) {

}

HeapSort::~HeapSort() {

}

void HeapSort::MaxHeapify(const_uint index) {
	uint leftIndex = this->Left(index);
	uint rightIndex = this->Right(index);
	uint curIndex = 0;
	const_uint m_vecSize = m_Vec.size();
	if (leftIndex <= m_vecSize&&m_Vec[leftIndex] > m_Vec[index]) {
		curIndex = leftIndex;
	}
	else {
		curIndex = index;
	}
	if (rightIndex <= m_vecSize&&m_Vec[rightIndex] > m_Vec[curIndex]) {
		curIndex = rightIndex;
	}
	if (curIndex != index) {
		uint temp = m_Vec[index];
		m_Vec[index] = m_Vec[curIndex];
		m_Vec[curIndex] = temp;
		MaxHeapify(curIndex);
	}
}

void HeapSort::coutHeapifyResult() {
	for (const auto &c : m_Vec) {
		std::cout << c << "  ";
	}
	std::cout<<std::endl;
}
