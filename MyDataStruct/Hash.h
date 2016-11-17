#ifndef HASH_H
#define HASH_H
#include<unordered_set>
#include<iostream>
#include<typeinfo>
class CopyHash {
public:
	explicit CopyHash(const int key):keys(key) {

	}
	CopyHash():keys(0) {

	}
	~CopyHash() {

	}
	int keys;
};
bool isEquel(const CopyHash &lhs, const CopyHash &rhs) {
	return lhs.keys == rhs.keys;
}
std::size_t hasher(const CopyHash &hs) {
	std::cout << std::hash<int>()(hs.keys) << std::endl;
	return std::hash<int>()(hs.keys);
}
class Hash {
public:
	using SD = std::unordered_multiset<CopyHash, decltype(hasher)*, decltype(isEquel)*>;
	Hash() {

	}
	~Hash() {

	}
	void myHash() {
		CopyHash ch(60);
		CopyHash chs(70);
		SD myHash(23, hasher,isEquel);
		std::cout << "hash size " << myHash.bucket_count() << std::endl;
		myHash.insert(ch);
		myHash.insert(chs);
		std::cout<<(*myHash.find(ch)).keys;
		//std::cout << typeid(decltype(hasher)*).name() << std::endl;
	}
};
#endif // !HASH_H
