#include "HuffmanTree.h"
#include<iostream>

HuffmanTree::HuffmanTree(const std::vector<int> vec) try :vArr(vec) {

}
catch (...) {

}

void HuffmanTree::mSwap(const int curIndex, const int nextIndex) {
	int temp = vArr[curIndex];
	vArr[curIndex] = vArr[nextIndex];
	vArr[nextIndex] = temp;
}


void HuffmanTree::MinHeapify(const int index) {
	int leftIndex = Left(index);
	int nextIndex = 0;
	if (leftIndex <= vArrSize&&vArr[leftIndex] < vArr[index])
		nextIndex = leftIndex;
	else
		nextIndex = index;

	int rightIndex = Right(index);
	if (rightIndex <= vArrSize&&vArr[rightIndex] < vArr[nextIndex])
		nextIndex = rightIndex;

	if (nextIndex != index) {
		mSwap(index, nextIndex);
		MinHeapify(nextIndex);
	}
}

void HuffmanTree::BuildMinheap() {
	//当前的有效的堆数目，从0开始
	vArrSize = vArr.size() - 1;

	for (int i = (vArr.size()-2) / 2; i >= 0; --i) {
		MinHeapify(i);
	}
}

void HuffmanTree::sortHeap() {
	BuildMinheap();
	for (int i = vArr.size() - 1; i >= 1; --i) {
		mSwap(0, i);
		vArrSize -= 1;
		MinHeapify(0);
	}
}

int HuffmanTree::ExtractMin() {
	if (vArrSize < 0) {
		std::cout << "erro....heap..." << std::endl;
	}
	int min = vArr[0];
	vArr[0] = vArr[vArrSize];
	vArrSize -= 1;
	MinHeapify(0);
	return min;
}

void HuffmanTree::heapIncreaseKey(int index,const int key) {
	if (key < vArr[index])
		std::cout << "eroo...heapIncreakey..." << std::endl;
	vArr[index] = key;
	while (index > 0 && vArr[Parent(index)] > vArr[index]) {
		mSwap(index, Parent(index));
		index = Parent(index);
	}
}

void HuffmanTree::heapInsert(const int key) {
	vArrSize += 1;
	vArr.push_back(key);
	heapIncreaseKey(vArrSize, key);
}

void HuffmanTree::HuffMan() {
	for (int i = 0; i != vArr.size() - 1; ++i) {
		sNode node;
		node.left = ExtractMin();
		node.right = ExtractMin();
		node.freq = node.left + node.right;

	}
}

void HuffmanTree::coutHeapifyResult() {
	for (const auto &c : vArr) {
		std::cout << c << "  ";
	}
	std::cout << std::endl;
}



void myHuffmanTree() {
	std::vector<int> vec{ 16,4,86,44,32,20,1,5,7,9,74,65,12 };
	HuffmanTree ht(vec);
	ht.BuildMinheap();
	ht.coutHeapifyResult();
}