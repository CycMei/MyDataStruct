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

void myAlogrithm();
void test16() {
	myAlogrithm();
}

void strtest(const std::string &str) {

	//const int iaa = 23;
	//int copyiaa = const_cast<int>(iaa);

	const int i = 3;
	const int *pi = &i;
	int *ppi = const_cast<int*>(pi);
	*ppi = 33;
	std::cout << i << std::endl;

	char c = 'a';
	const char * pc = &c;
	char *ppc = const_cast<char*>(pc);
	*ppc = 'c';

	const int ica = 100;
	int *ia = const_cast<int*>(&ica);
	*ia = 200;
	if (ica == *ia) {
		//些在编译期间完成，对于内置类型，如int，编译器可能使用常数直接替换掉对此变量的引用。而对于结构体不一定。
		//const型在压栈时，是使用的直接的数，
		std::cout << "chagned ...  " << std::endl;
	}
	std::cout << *ia << " , " << ica << std::endl;

	int refA = 32;
	const int &crefA = refA;
	int &ccre = const_cast<int&>(crefA);
	ccre = 50;
	std::cout << refA << " , " << crefA << " , " << ccre << std::endl;

}
void copystrtest(std::string &str) {

}
void test17() {
	char buffer[] = "buffer";
	strtest(buffer);
	//copystrtest(buffer);
}

void main() {
	test17();
}