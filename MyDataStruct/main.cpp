#include"HeapSort.h"

#include<vector>
#include<iostream>

void test1() {
	std::vector<unsigned int> m_vec{ 23,24,14,6,13,10,1,5,7,12 };
	HeapSort mheapSort(m_vec);
	mheapSort.MaxHeapify(0);
	mheapSort.coutHeapifyResult();
}


void main() {
	test1();
	//std::cout << (5 / 2)-1 << std::endl;
}