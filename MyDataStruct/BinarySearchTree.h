#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<iostream>
#include<memory>

//template<typename T> class CBSTreeNode;
//template<typename T> using S_CBSTN = std::shared_ptr<CBSTreeNode<T>>;

template<typename T> class CBSTreeNode {
private:
	using S_CBSTN = std::shared_ptr<CBSTreeNode<T>>;
public:
	explicit CBSTreeNode(const T key);
	~CBSTreeNode();
public:
	T key;
	S_CBSTN parent;
	S_CBSTN left;
	S_CBSTN right;
private:
	CBSTreeNode(const T key, S_CBSTN, S_CBSTN, S_CBSTN);
};

template<typename T> class CBSTree {
private:
	using S_CBSTN = std::shared_ptr<CBSTreeNode<T>>;
public:
	CBSTree();
	~CBSTree() {};
	void CBSTreeInsert(const T value);
	void printCBSTreeNodes() { coutTreeNodes(root); }
private:
	void coutTreeNodes(S_CBSTN node);
private:
	S_CBSTN root;

};

#endif


template<typename T> CBSTree<T>::CBSTree() try :root(nullptr) {

}
catch (...) {
	std::cout << "constructor CBSTree..erro....1" << std::endl;
}


template<typename T> void CBSTree<T>::CBSTreeInsert(const T value) {
	S_CBSTN keys = std::make_shared<CBSTreeNode<T>>(value);
	if (!root) {
		root = keys;
		return;
	}
	S_CBSTN preNode = nullptr;
	S_CBSTN nextNode = root;
		
	while (nextNode) {
		preNode = nextNode;
		if (keys->key < nextNode->key)
			nextNode = nextNode->left;
		else
			nextNode = nextNode->right;
	}

	//keys->parent =std::make_shared<CBSTreeNode<T>>(preNode->key);
	keys->parent = preNode;
	if (keys->key < preNode->key) {
		preNode->left = keys;
	}
	else {
		preNode->right = keys;
	}
}


template<typename T> void CBSTree<T>::coutTreeNodes(S_CBSTN node) {
	if (!node)
		return;
	coutTreeNodes(node->left);
	std::cout << node->key << "   ";
	coutTreeNodes(node->right);
}



//1111111
template<typename T> inline CBSTreeNode<T>::CBSTreeNode(const T key, S_CBSTN parent, S_CBSTN left, S_CBSTN right)
try :key(key), parent(parent), left(left), right(right){

}
catch (...) {
	std::cout << "constructor BSTreeNode..erro....1" << std::endl;
}

//2222222
template<typename T> inline CBSTreeNode<T>::CBSTreeNode(const T key)
try :CBSTreeNode(key, nullptr, nullptr, nullptr) {

}
catch (...) {
	std::cout << "constructor BSTreeNode..erro....2" << std::endl;
}


//33333333
template<typename T> CBSTreeNode<T>::~CBSTreeNode() {
	std::cout << "delete BSTreeNode.." << std::endl;
}
