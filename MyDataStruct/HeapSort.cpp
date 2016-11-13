#include "HeapSort.h"
#include<iostream>

HeapSort::HeapSort(const vec_UInt &vec):m_Vec(vec),m_vecSize(m_Vec.size() - 1) {

}

HeapSort::~HeapSort() {

}

void HeapSort::MaxHeapify(const_uint index) {
	uint leftIndex = this->Left(index);
	uint rightIndex = this->Right(index);
	uint curIndex = 0;
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

void HeapSort::BuildMaxheap() {
	const_uint m_vecSize = m_Vec.size();
	for (int i = m_vecSize / 2 - 1; i >= 0; --i) {
		MaxHeapify(i);
	}
}

void HeapSort::sortHeap() {
	this->BuildMaxheap();
	int cm_vecSize = m_Vec.size();
	for (int i = cm_vecSize - 1; i >= 1; --i) {
		auto temp = m_Vec[i];
		m_Vec[i] = m_Vec[0];
		m_Vec[0] = temp;
		m_vecSize -= 1;
		MaxHeapify(0);
	}
}

HeapSort::const_uint HeapSort::Maximum() const {
	return m_Vec[0];
}

HeapSort::const_uint HeapSort::ExtractMax() {
	if (m_vecSize < 1) {
		std::cout << "erro...........  " << std::endl;
		return 0;
	}
	const_uint max = m_Vec[0];
	m_Vec[0] = m_Vec[m_vecSize - 1];
	m_vecSize -= 1;
	this->MaxHeapify(0);
	return max;
}

bool HeapSort::HeapIncreaseKey(int index, uint key) {
	if (index >= m_vecSize) {
		std::cout << "erro....insert....." << std::endl;
		return false;
	}
	if (key < m_Vec[index]) {
		std::cout << "erro....insert...for key.." << std::endl;
		return false;
	}
	m_Vec[index] = key;
	while (index>=0&&m_Vec[Parent(index)]<m_Vec[index]) {
		auto tmep = m_Vec[Parent(index)];
		m_Vec[Parent(index)] = m_Vec[index];
		m_Vec[index] = tmep;
		index = Parent(index);
	}
	return true;
}

bool HeapSort::MaxHeapInsert(uint key) {
	m_Vec.push_back(key);
	m_vecSize += 1;
	return HeapIncreaseKey(m_vecSize, key);
}



