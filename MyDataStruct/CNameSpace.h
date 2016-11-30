#ifndef CNAMESPACE_H
#define CNAMESPACE_H
#include<iostream>
#include<string>
#include<vector>
namespace {
	int iStatic;
}
namespace NameSpace {
	class CNameSpace {
	public:
		CNameSpace();
		~CNameSpace();
		//namespace nspErro {

		//}
	};
	int nspErro;
	//namespace nspErro {

	//}
	double vbs;
	inline namespace vvs {
		int vbs;
	}

	void test() {
		//namespace nspErro {

		//}
		vvs::vbs = 3;
	}
	
}
namespace std {
	template<> struct hash<NameSpace::CNameSpace>;
}
template<> struct std::hash<NameSpace::CNameSpace> {
	void test() {
		::NameSpace::nspErro = 4;
	}
};
#endif // !NAMESPACE_H
