#include "Gcd.h"
#include<iostream>

Gcd::Gcd() {
	//���Լ��
}

Gcd::~Gcd() {

}

unsigned int Gcd::InstanceGcd(int les, int res) {
	if (res < 0)
		std::cout << "res...   <0   " << std::endl;
	if (!res)
		return les;
	else
		return InstanceGcd(res, les%res);
}
