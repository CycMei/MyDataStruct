#include"BinarySearchTree.h"
#include<vector>



template<typename T> bool operator<(const CBSTreeNode<T> &lhs, const CBSTreeNode<T> &rhs) {
	return lhs.key < rhs.key;
}



using temp = std::shared_ptr<CBSTreeNode<int>>;
temp vv = nullptr;
void ss(int i) {
	
	temp sss(std::make_shared<CBSTreeNode<int>>(i));
	if (!vv) {
		vv = sss;
		return;
	}
	temp abc = vv;
	
	abc->left = sss;
	abc->right = sss;
	abc->left->parent = abc;

}

void myCBSTree() {
	ss(2);
	ss(3);

}