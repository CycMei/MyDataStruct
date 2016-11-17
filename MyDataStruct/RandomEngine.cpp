#include "RandomEngine.h"
#include<random>
#include<iostream>
#include<cmath>
#include<string>


RandomEngine::RandomEngine() {

}

RandomEngine::~RandomEngine() {

}

void RandomEngine::defaultEngine() {
	std::default_random_engine e;
	std::cout << "最大值：" << e.max() << std::endl;
	std::cout << "最小值：" << e.min() << std::endl;
	for (std::size_t i = 0; i != 10; ++i) {
		std::cout << e() << std::endl;
	}

	std::default_random_engine esend(4);
	std::cout << "最大值：" << esend.max() << std::endl;
	std::cout << "最小值：" << esend.min() << std::endl;
	esend.seed(100);
	std::default_random_engine::result_type res = esend();
	std::cout << res << std::endl;
	unsigned long long ull = 254554;
	esend.discard(ull);
	std::default_random_engine::result_type rses = esend();
	std::cout << rses << std::endl;
}

void RandomEngine::uniformDistruction() {
	std::uniform_int_distribution<unsigned> u(0, 9);
	std::default_random_engine e(150);
	for (std::size_t i = 0; i != 10; ++i) {
		std::cout << u(e) << "   ";
	}
	std::cout << std::endl;
	std::cout <<"vvvv   "<< u.max() << std::endl;
	u.reset();

	std::uniform_real_distribution<> udouble(0, 1);

	if (bad_randVec() == bad_randVec()) {
		std::cout << std::boolalpha;
		std::cout << true << std::endl;
	}
}

void RandomEngine::nomalDistrtion() {
	std::default_random_engine e(5000);
	std::normal_distribution<> n(4, 1.5);
	std::vector<unsigned int> vals(9,0);
	for (std::size_t i = 0; i != 200; ++i) {
		unsigned int v = std::lround(n(e));
		if (v < vals.size())
			++vals[v];
	}
	for (std::size_t i = 0; i != vals.size(); ++i) {
		std::cout << i << " : " << std::string(vals[i], '*') << std::endl;
	}
}

void RandomEngine::boolEngine() {
	static std::default_random_engine e;
	static std::bernoulli_distribution u;
	int i = 10;
	while (i--) {
		std::cout << std::boolalpha << "vvss    :  " << u(e) << std::endl;
	}
}

std::vector<unsigned int> RandomEngine::bad_randVec() {
	static std::default_random_engine e(5000);
	static std::uniform_int_distribution<unsigned int> u(0, 20);
	std::vector<unsigned int> vec;
	for (std::size_t i = 0; i != 10; ++i) {
		vec.push_back(u(e));
	}
	return vec;
}


