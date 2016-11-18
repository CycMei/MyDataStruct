#include "Hash.h"
#include<typeinfo>


//自己的类型的无序容器的==比较函数
bool operator==(const CopyHash &lhs, const CopyHash &rhs) {
	return lhs.keys == rhs.keys;
}


// 定义自己的hash函数和==比较函数。。需要显示调用。。
// SD sd(50,decltype(hasher)*,decltype(isEquel)*);
bool isEquel(const CopyHash &lhs, const CopyHash &rhs) {
	return lhs.keys == rhs.keys;
}
std::size_t hasher(const CopyHash &hs) {
	std::cout << std::hash<int>()(hs.keys) << std::endl;
	return std::hash<int>()(hs.keys);
}


//定义无序容器的自己的hash模板和比较函数模板，默认的无序容器的第二，第三的 模板 参数。
namespace std {
	template<> struct hash<CopyHash> {
		typedef size_t result_type;
		size_t operator()(const CopyHash &ch) const;
	};
	template<> struct equal_to<CopyHash> {
		bool operator()(const CopyHash &lhs, const CopyHash &rhs) const;
	};
}
std::size_t std::hash<CopyHash>::operator()(const CopyHash &ch) const {
	return hash<int>()(ch.keys);
}
bool std::equal_to<CopyHash>::operator()(const CopyHash &lhs, const CopyHash &rhs) const {
	return lhs.keys == rhs.keys;
}






CopyHash::CopyHash(const int key) :keys(key) {

}

CopyHash::CopyHash():keys(0) {

}

CopyHash::~CopyHash() {

}







Hash::Hash() {

}

Hash::~Hash() {

}

void Hash::myHash() {
	SD myHash;
	for (int i = 0; i != 100; i += 2)
		myHash.insert(CopyHash(i));
	std::cout<<"容器的大小： " << myHash.size() << std::endl;
	std::cout << "正在使用的桶的数目： " << myHash.bucket_count() << std::endl;
	std::cout << "容器能容纳的最多的桶的数量： " << myHash.max_bucket_count() << std::endl;
	std::cout << "第n个桶的有多少元素： " << myHash.bucket_size(15) << std::endl;
	std::cout << "关键字为k的元素在那个桶中： " << myHash.bucket(CopyHash(4)) << std::endl;

	SD::local_iterator blit = myHash.begin(3);
	SD::local_iterator elit = myHash.end(3);
	std::cout << "第n个桶的首元素迭代器 ： " << (*blit).keys << std::endl;
	std::cout << "第n个桶的首元素迭代器 ： " << (*elit).keys << std::endl;

	if (myHash.bucket_size(4)) {
		SD::const_local_iterator cblit = myHash.cbegin(4);
		SD::const_local_iterator celit = myHash.cend(4);
		std::cout << "conts  " << "第n个桶的首元素迭代器 ： " << (*cblit).keys << std::endl;
		std::cout << "conts  " << "第n个桶的首元素迭代器 ： " << (*cblit).keys << std::endl;
	}
	else {
		std::cout << "桶为4的元素为0.。" << std::endl;
	}

	
}
