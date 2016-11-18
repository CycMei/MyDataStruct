#ifndef SETANDMAP_H
#define SETANDMAP_H
#include<utility>
#include<string>
#include<vector>
#include<map>
class Sales_data {
public:
	explicit Sales_data(int data) :_isbn(data) {

	}
	~Sales_data() {

	}
	int isbn() const {
		return this->_isbn;
	}
private:
	int _isbn;
};

inline bool operator<(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}

inline bool mcompareIsbn(const Sales_data &lhs, const Sales_data &rhs) {
	return lhs.isbn() < rhs.isbn();
}


class SetAndMap {
public:
	SetAndMap();
	~SetAndMap();
	void MyMap();
	void MyMap1();
	void MyMap2();
	void mpair();
	void mpair1();
	std::pair<std::string, int> process(std::vector<std::string> &v);
	void readpair();
	void keyType();
	void insertMap();
	void insertMap1();
	void compareIsbn();

	void removeMap();


	void swapForMap();
private:
	const std::map<std::string, std::string> map_transfrom_text{
		{ "k","okay?" },
		{ "y","why" },
		{ "r","are" },
		{ "u","you" },
		{ "pic","picture" },
		{ "thk","thanks" },
		{ "18r","later" }
	};
	std::vector<std::string> v_text{ "where","r","u","y","dont","u","send","me","a","pic","k","thk","18r" };
	void transform(std::string&);
};
#endif // !SETANDMAP_H
