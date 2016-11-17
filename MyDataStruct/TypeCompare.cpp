#include "TypeCompare.h"
#include<iostream>

TypeCompare::TypeCompare() {

}

TypeCompare::~TypeCompare() {

}

void TypeCompare::MyConditional() {
	//和三目运算符相似，第一个模板参数为true,类型为:第二个模板参数，否则类型为第二个模板参数
	typedef std::conditional<true, int, double>::type Type1;
	typedef std::conditional<false, int, double>::type Type2;
	typedef std::conditional<sizeof(int) >= sizeof(double), int, double>::type Type3;
	std::cout << typeid(Type1).name() << std::endl;
	std::cout << typeid(Type2).name() << std::endl;
	std::cout << typeid(Type3).name() << std::endl;
}

void TypeCompare::common_type() {
	struct Base {

	};
	struct Derived:Base {

	};
	std::cout << sizeof(Derived) << std::endl;						//1
	std::cout << sizeof(Base) << std::endl;							//1
	typedef std::common_type<char, short, int>::type A;
	std::cout << std::boolalpha;
	std::cout << std::is_same<int, A>::value << std::endl;			//true
	typedef std::common_type<float, double>::type B;
	std::cout << std::is_same<int, B>::value << std::endl;			//false

	typedef std::common_type<Derived, Base>::type C;             // Base
	typedef std::common_type<Derived*, Base*>::type D;           // Base*
	typedef std::common_type<const int, volatile int>::type E;   // int
}
