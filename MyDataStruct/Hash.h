#ifndef HASH_H
#define HASH_H
#include<unordered_set>
#include<iostream>
class CopyHash {
public:
	explicit CopyHash(const int key);
	CopyHash();
	~CopyHash();
	int keys;
};

class Hash {
public:
	using SD = std::unordered_multiset<CopyHash>;
	Hash();
	~Hash();
	void myHash();
};
#endif // !HASH_H
