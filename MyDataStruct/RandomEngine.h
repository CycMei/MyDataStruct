#ifndef RANDOMENGINE_H
#define RANDOMENGINE_H
#include<vector>
class RandomEngine {
private:
	std::vector<unsigned int> bad_randVec();
public:
	RandomEngine();
	~RandomEngine();
	void defaultEngine();
	void uniformDistruction();
	void nomalDistrtion();
	void boolEngine();

};
#endif // !RANDOMENGINE_H
