#include "HuffmanTree.h"
#include<functional>
////////
CNode::CNode(const int key)
try :CNode(key,nullptr,nullptr,nullptr){

}
catch (...) {
	std::cout << "cnode eroo..." << std::endl;
}
///////
CNode::CNode(const int key, SPNode parent, SPNode left, SPNode right) 
try :key(key), parent(parent), left(parent), right(parent){

}
catch (...) {
	std::cout << "cnode eroo...1111111" << std::endl;
}
/////////
CNode::~CNode() {

}

bool operator<(const CNode &lhs, const CNode &rhs) {
	return lhs.key < rhs.key;
}

std::ostream &operator<<(std::ostream &os, const CNode &obj) {
	os << obj.key;
	return os;
}





HuffmanTree::HuffmanTree(const std::vector<int> vec){
	for (const auto &c : vec)
		vArr.push_back(std::make_shared<CNode>(c));
}


void HuffmanTree::mSwap(const int curIndex, const int nextIndex) {
	SPNode temp = vArr[curIndex];
	vArr[curIndex] = vArr[nextIndex];
	vArr[nextIndex] = temp;
}


void HuffmanTree::MinHeapify(const int index) {
	int leftIndex = Left(index);
	int nextIndex = 0;
	if (leftIndex <= vArrSize&&vArr[leftIndex]->key < vArr[index]->key)
		nextIndex = leftIndex;
	else
		nextIndex = index;

	int rightIndex = Right(index);
	if (rightIndex <= vArrSize&&vArr[rightIndex]->key < vArr[nextIndex]->key)
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
		std::cout << c->key << "  ";
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

SPNode HuffmanTree::ExtractMin() {
	if (vArrSize < 0) {
		std::cout << "erro....heap..." << std::endl;
	}
	SPNode min = vArr[0];
	vArr[0] = vArr[vArrSize];
	vArr.pop_back();
	vArrSize -= 1;
	//std::cout << vArr[0]->key << std::endl;
	MinHeapify(0);
	return min;
}

void HuffmanTree::heapIncreaseKey(int index, SPNode node) {


	vArr[index] = node;
	while (index > 0 && vArr[index]->key<vArr[Parent(index)]->key ) {
		mSwap(index, Parent(index));
		index = Parent(index);
	}
}

void HuffmanTree::heapInsert(CNode node) {
	vArrSize += 1;
	SPNode temp = std::make_shared<CNode>(node);
	vArr.push_back(temp);
	heapIncreaseKey(vArrSize, temp);
}

void HuffmanTree::HuffMan() {
	int j = vArr.size();
	for (int i = 0; i !=  j- 1; ++i) {
		CNode cnode(0);
		cnode.left = ExtractMin();
		cnode.right = ExtractMin();
		cnode.key = cnode.left->key + cnode.right->key;
		heapInsert(cnode);
		coutHeapifyResult();
	}
}





void myHuffmanTree() {
	std::vector<int> vec{ 4,6,3,1,5,7,9,12 };
	HuffmanTree ht(vec);
	ht.coutHeapifyResult();
	ht.BuildMinheap();
	ht.coutHeapifyResult();
	ht.HuffMan();
	ht.printEndResult();
}


