#include"BinarySearchTree.h"
#include<vector>


template<typename T> bool operator<(const CBSTreeNode<T> &lhs, const CBSTreeNode<T> &rhs) {
	return lhs.key < rhs.key;
}



void myCBSTree() {
	std::vector<int> vec{ 4,6,3,20,1,5,7,9,12 };
	CBSTree<int> cbs;
	for (const auto &c : vec) {
		cbs.CBSTreeInsert(c);
	}
}