#include "Hash.h"
#include<typeinfo>


//�Լ������͵�����������==�ȽϺ���
bool operator==(const CopyHash &lhs, const CopyHash &rhs) {
	return lhs.keys == rhs.keys;
}


// �����Լ���hash������==�ȽϺ���������Ҫ��ʾ���á���
// SD sd(50,decltype(hasher)*,decltype(isEquel)*);
bool isEquel(const CopyHash &lhs, const CopyHash &rhs) {
	return lhs.keys == rhs.keys;
}
std::size_t hasher(const CopyHash &hs) {
	std::cout << std::hash<int>()(hs.keys) << std::endl;
	return std::hash<int>()(hs.keys);
}


//���������������Լ���hashģ��ͱȽϺ���ģ�壬Ĭ�ϵ����������ĵڶ��������� ģ�� ������
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
	std::cout<<"�����Ĵ�С�� " << myHash.size() << std::endl;
	std::cout << "����ʹ�õ�Ͱ����Ŀ�� " << myHash.bucket_count() << std::endl;
	std::cout << "���������ɵ�����Ͱ�������� " << myHash.max_bucket_count() << std::endl;
	std::cout << "��n��Ͱ���ж���Ԫ�أ� " << myHash.bucket_size(15) << std::endl;
	std::cout << "�ؼ���Ϊk��Ԫ�����Ǹ�Ͱ�У� " << myHash.bucket(CopyHash(4)) << std::endl;

	SD::local_iterator blit = myHash.begin(3);
	SD::local_iterator elit = myHash.end(3);
	std::cout << "��n��Ͱ����Ԫ�ص����� �� " << (*blit).keys << std::endl;
	std::cout << "��n��Ͱ����Ԫ�ص����� �� " << (*elit).keys << std::endl;

	if (myHash.bucket_size(4)) {
		SD::const_local_iterator cblit = myHash.cbegin(4);
		SD::const_local_iterator celit = myHash.cend(4);
		std::cout << "conts  " << "��n��Ͱ����Ԫ�ص����� �� " << (*cblit).keys << std::endl;
		std::cout << "conts  " << "��n��Ͱ����Ԫ�ص����� �� " << (*cblit).keys << std::endl;
	}
	else {
		std::cout << "ͰΪ4��Ԫ��Ϊ0.��" << std::endl;
	}

	
}
