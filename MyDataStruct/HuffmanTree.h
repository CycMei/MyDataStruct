#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<vector>
#include<iostream>

class CNode {
private:
	friend bool operator<(const CNode&, const CNode&);
	friend std::ostream &operator<<(std::ostream &os,const CNode &obj);
public:
	explicit CNode(const int key);
	CNode();
	~CNode();
public:
	int &getKey() {return key;}
	CNode *&getLeft() {return left;}
	CNode *&getRight() {return right;}
private:
	CNode *parent;
	CNode *left;
	CNode *right;
	int key;
};



class HuffmanTree {
public:
	explicit HuffmanTree(const std::vector<CNode>);
	~HuffmanTree() {

	}
	void MinHeapify(const int index);
	void BuildMinheap();
	void sortHeap();

	CNode ExtractMin();
	void heapIncreaseKey(int index, CNode );
	void heapInsert(CNode);

	void HuffMan();

	void coutHeapifyResult();
private:
	//小标从0开始
	const int Parent(const int index) const {
		return index == 0 ? 0 : (index - 1) / 2;
	}
	const int Left(const int index) const {
		return 2 * index + 1;
	}
	const int Right(const int index) const {
		return 2 * index + 2;
	}
	void mSwap(const int curIndex, const int nextIndex);
private:
	std::vector<CNode> vArr;
	int vArrSize = 0;
	//261,99
};
#endif // !HUFFMANTREE_H
