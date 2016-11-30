#include"HeapSort.h"

#include"Median.h"

#include"QSort.h"

#include"Gcd.h"

#include"TypeCompare.h"

#include"RandomEngine.h"

#include"Hash.h"

#include"CountSort.h"

#include"SetAndMap.h"

#include"RandomReSort.h"

#include"BinarySearchTree.h"

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
	//std::cout << me.MinMum() << std::endl;
	//std::cout << me.MaxMum() << std::endl;
	//std::cout << me.MinAndMaxMum()[0]<<"  ,  "<< me.MinAndMaxMum()[1] << std::endl;
	std::cout<<"  ..  " << me.RandomSelect(0, m_vec.size() - 1, 4) << std::endl;
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

void test7() {
	Hash ha;
	ha.myHash();
}

void test8() {
	std::vector<int> m_vec{ 4,1,3,2,16,9,10,14,8,7 };
	CountSort cs(m_vec);
	cs.countSort();
	cs.printVec();
}

void test9() {
	SetAndMap sam;
	//sam.process(std::vector<std::string>());
	sam.removeMap();
}

void test10() {
	RandomReSort res;
	res.myRandomSort();
}

void myPointerToMember();
void test11() {
	myPointerToMember();
}

void myInsert();
void test12() {
	myInsert();
}

void myHuffmanTree();
void test13() {
	myHuffmanTree();
}

void myCBSTree();
void test14() {
	myCBSTree();
}

void myChart();
void test15() {
	myChart();
}


void main() {
	test15();
}