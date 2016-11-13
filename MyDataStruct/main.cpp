#include"HeapSort.h"

#include<vector>
#include<iostream>

void test1() {
	std::vector<unsigned int> m_vec{ 4,1,3,2,16,9,10,14,8,7 };
	HeapSort mheapSort(m_vec);
	mheapSort.sortHeap();
	mheapSort.coutHeapifyResult();
}


void main() {
	test1();
	//std::cout << (5 / 2)-1 << std::endl;
}