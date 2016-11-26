#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<vector>
#include<iostream>
#include<memory>
class CNode;
using SPNode = std::shared_ptr<CNode>;
class CNode {
private:
	friend bool operator<(const CNode&, const CNode&);
	friend std::ostream &operator<<(std::ostream &os,const CNode &obj);
public:
	explicit CNode(const int key);
	~CNode();
private:
	CNode(const int key,SPNode,SPNode,SPNode);
public:
	SPNode parent;
	SPNode left;
	SPNode right;
	int key;
};



class HuffmanTree {
public:
	explicit HuffmanTree(const std::vector<int>);
	~HuffmanTree() {}
	void MinHeapify(const int index);
	void BuildMinheap();
	void sortHeap();

	SPNode ExtractMin();
	void heapIncreaseKey(int index, SPNode);
	void heapInsert(CNode);

	void HuffMan();

	void coutHeapifyResult();
	void printEndResult() {
		coutEndResult(vArr[0]);
	}

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
	void coutEndResult(SPNode node) {
		if (!node)
			return;
		coutEndResult(node->left);
		std::cout << node->key << " ";
		coutEndResult(node->right);
	}
private:
	std::vector<SPNode> vArr;
	int vArrSize = 0;
	//261,99
};
#endif // !HUFFMANTREE_H
