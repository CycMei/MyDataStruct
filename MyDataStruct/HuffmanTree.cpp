#include "HuffmanTree.h"
#include<functional>

CNode::CNode(const int key)
try :key(key), parent(nullptr), left(nullptr), right(nullptr){

}
catch (...) {
	std::cout << "cnode eroo..." << std::endl;
}

CNode::CNode() try :key(0), parent(nullptr), left(nullptr), right(nullptr){

}
catch (...) {
	std::cout << "cnode eroo...1111111" << std::endl;
}

CNode::~CNode() {

}

bool operator<(const CNode &lhs, const CNode &rhs) {
	return lhs.key < rhs.key;
}

std::ostream &operator<<(std::ostream &os, const CNode &obj) {
	os << obj.key;
	return os;
}



HuffmanTree::HuffmanTree(const std::vector<CNode> vec) try :vArr(vec) {

}
catch (...) {

}

void HuffmanTree::mSwap(const int curIndex, const int nextIndex) {
	CNode temp = vArr[curIndex];
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

void HuffmanTree::coutHeapifyResult() {
	for (const auto &c : vArr) {
		std::cout << c << "  ";
	}
	std::cout << std::endl;
}

void HuffmanTree::sortHeap() {
	BuildMinheap();
	for (int i = vArr.size() - 1; i >= 1; --i) {
		mSwap(0, i);
		vArrSize -= 1;
		MinHeapify(0);
	}
}

CNode HuffmanTree::ExtractMin() {
	if (vArrSize < 0) {
		std::cout << "erro....heap..." << std::endl;
	}
	CNode min = vArr[0];
	vArr[0] = vArr[vArrSize];
	vArrSize -= 1;
	MinHeapify(0);
	return min;
}

void HuffmanTree::heapIncreaseKey(int index, CNode node) {

	if (node < vArr[index])
		std::cout << index<<"   eroo...heapIncreakey..." << node.getKey()<< std::endl;
	vArr[index] = node;
	while (index > 0 && vArr[index]<vArr[Parent(index)] ) {
		mSwap(index, Parent(index));
		index = Parent(index);
	}
}

void HuffmanTree::heapInsert(CNode node) {
	vArrSize += 1;
	
	vArr.push_back(node);
	heapIncreaseKey(vArrSize, node);
}

void HuffmanTree::HuffMan() {
	int j = vArr.size();
	for (int i = 0; i !=  j- 1; ++i) {
		CNode cnode;
		cnode.getLeft() = &(ExtractMin());
		cnode.getRight() = &(ExtractMin());
		cnode.getKey() = cnode.getLeft()->getKey() + cnode.getRight()->getKey();
		heapInsert(cnode);
	}
}





void myHuffmanTree() {
	std::vector<int> vec{ 16,4,86,44,32,20,1,5,7,9,74,65,12 };
	std::vector<CNode> vCNode;
	for (const auto &c : vec) {
		vCNode.push_back(CNode(c));
	}
	HuffmanTree ht(vCNode);
	ht.coutHeapifyResult();
	ht.BuildMinheap();
	ht.coutHeapifyResult();
	ht.HuffMan();
	ht.coutHeapifyResult();
}


