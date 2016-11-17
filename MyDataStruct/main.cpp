#include"HeapSort.h"

#include"Median.h"

#include"QSort.h"

#include"Gcd.h"

#include"TypeCompare.h"

#include"RandomEngine.h"

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

void test2() {
	std::vector<int> m_vec{ 4,1,3,2,16,9,10,14,8,7 };
	Median me(m_vec);
	std::cout << me.MinMum() << std::endl;
	std::cout << me.MaxMum() << std::endl;
	std::cout << me.MinAndMaxMum()[0]<<"  ,  "<< me.MinAndMaxMum()[1] << std::endl;
}

void test3() {
	std::vector<int> m_vec{ 4,1,3,2,16,9,10,14,8,7 };
	QSort qsorts(m_vec);
	qsorts.RandomQSort(0, m_vec.size() - 1);
	qsorts.printsVec();
}

void test4() {
	int a = 18, b = 36,c=9;
	Gcd gcd;
	auto result=gcd.TemplateGcd(a, b,c);
	std::cout << result << std::endl;
}

void test5() {
	TypeCompare typecompare;
	typecompare.common_type();
}

void test6() {
	RandomEngine reg;
	reg.boolEngine();
}

void main() {
	test6();
	//std::cout << (5 / 2)-1 << std::endl;
}