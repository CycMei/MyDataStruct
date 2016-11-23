#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include<vector>

struct sNode {
	int left;
	int right;
	int freq;
};



class HuffmanTree {
public:
	explicit HuffmanTree(const std::vector<int>);
	~HuffmanTree() {

	}
	void MinHeapify(const int index);
	void BuildMinheap();
	void sortHeap();

	int ExtractMin();
	void heapIncreaseKey(int index,const int key);
	void heapInsert(const int key);

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
	std::vector<int> vArr;
	int vArrSize = 0;
	//261,99
};
#endif // !HUFFMANTREE_H
