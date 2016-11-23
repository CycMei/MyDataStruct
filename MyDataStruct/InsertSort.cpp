#include "InsertSort.h"
#include<iostream>
#include<exception>

InsertSort::InsertSort(const std::vector<int> &vec) try:vArr(vec){

}
catch (...) {
	std::cout << "constructor erro.... " << std::endl;
}

InsertSort::~InsertSort() {

}

bool InsertSort::InserSort() {
	try {
		if (vArr.size() < 2) {
			std::logic_error leErro(std::string("数组长度小于2.。"));
			throw leErro;
		}
		for (int i = 1; i != vArr.size(); ++i) {
			const int key = vArr[i];
			int preI = i - 1;
			while (preI >= 0 && vArr[preI] > key) {
				vArr[preI + 1] = vArr[preI];
				preI -= 1;
			}
			vArr[preI + 1] = key;
		}
		return true;
	}
	catch (const std::logic_error &erro) {
		std::cout << erro.what() << std::endl;
		return false;
	}
}

void InsertSort::addToBin() {
	std::vector<unsigned short> vec1{ 1,0,1,1,1,0,0,1 };
	std::vector<unsigned short> vec2{ 1,1,0,1,1,0,0,1 };
	std::vector<unsigned short> resultVec(vec1.size()+1, 0);
	try {
		if (vec1.size() != vec2.size()) {
			std::logic_error lero("2个数组不一样大。。");
			throw lero;
		}
		unsigned short index = vec1.size();
		while (index > 0) {
			--index;
			unsigned short tmp = vec1[index] + vec2[index] + resultVec[index+1];
			switch (tmp) {
			case 2:
				resultVec[index + 1] = 0;
				resultVec[index] = 1;
				break;
			case 3:
				resultVec[index + 1] = 1;
				resultVec[index] = 1;
				break;
			default:
				resultVec[index + 1] = tmp;
				break;
			}
		}
		for (const auto &c : resultVec)
			std::cout << c << "   ";
		std::cout << std::endl;
	}
	catch (const std::logic_error &erro) {
		std::cout << erro.what() << std::endl;
	}
}

void InsertSort::printvArr() {
	for (const auto &c : vArr) {
		std::cout << c << "  ";
	}
	std::cout << std::endl;
}

bool InsertSort::isPowerToTwo(const int num) {
	//		2		4		8
	//		0010	0100	1000
	//		0001	0011	0111
	//		0		0		0
	try {
		if (num < 0) {
			std::logic_error le("需要正整数。。。");
			throw le;
		}
		bool bl = (num&(num - 1)) == 0;
		if (bl)
			std::cout << "num..: " << num << " is a power to 2" << std::endl;
		else
			std::cout << "num..: " << num << " is not a power to 2" << std::endl;
		return bl;
	}
	catch (const std::logic_error &er) {
		std::cout << er.what() << std::endl;
	}
}

void myInsert() {
	std::vector<int> vec{ 31,41,59,26,41,58 };
	InsertSort is(vec);
	if(is.InserSort())
		is.printvArr();
	is.addToBin();
	is.isPowerToTwo(9);
}
