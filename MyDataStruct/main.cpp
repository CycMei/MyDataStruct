#include"HeapSort.h"

#include<vector>
#include<iostream>

void test1() {
	std::vector<unsigned int> m_vec{ 4,1,3,2,16,9,10,14,8,7 };
	HeapSort mheapSort(m_vec);
	//mheapSort.sortHeap();
	mheapSort.BuildMaxheap();
	mheapSort.coutHeapifyResult();
	std::cout << mheapSort.Maximum() << std::endl;
	mheapSort.HeapIncreaseKey(2, 30);
	mheapSort.coutHeapifyResult();
	mheapSort.MaxHeapInsert(0);
	mheapSort.coutHeapifyResult();
	//mheapSort.coutHeapifyResult();
}


void main() {
	test1();
	//std::cout << (5 / 2)-1 << std::endl;
}