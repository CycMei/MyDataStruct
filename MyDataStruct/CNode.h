#ifndef CNODE_H
#define CNODE_H
#include<memory>
#include<iostream>
namespace CNODE {
	template<typename T> class CNode {
	protected:
		using SP_CNode = std::shared_ptr<CNode<T>>;
	public:
		T key;
		SP_CNode parent;
		SP_CNode left;
		SP_CNode right;
	protected:
		explicit CNode(const T key);
		virtual ~CNode(){
			std::cout << "delete ..cnode...." << std::endl;
		}
	private:
		CNode(const T key, SP_CNode parent, SP_CNode left, SP_CNode right);
	};
}
#endif // !CNODE_H
template<typename T> inline CNODE::CNode<T>::CNode(const T key)
try :CNode(key, nullptr, nullptr, nullptr) {

}
catch (...) {
	std::cout << "constructor CNode erro...cnode 1" << std::endl;
}

template<typename T> inline CNODE::CNode<T>::CNode(const T key, SP_CNode p, SP_CNode l, SP_CNode r)
try :key(key), parent(p), left(l), right(r){

}
catch (...) {
	std::cout << "constructor CNode erro...cnode 2" << std::endl;
}