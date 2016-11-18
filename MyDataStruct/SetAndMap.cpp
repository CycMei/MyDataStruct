#include "SetAndMap.h"

#include<iostream>
#include<set>

#include<list>



SetAndMap::SetAndMap() {

}

SetAndMap::~SetAndMap() {

}

void SetAndMap::MyMap() {
	std::map<std::string, std::size_t> word_count;
	std::set<std::string> exclude = { "the","but","and" };
	std::map<std::string, std::string> authors = { {"name1","cyc"},{"name2","cyc1"} };
	std::map<std::string, std::string> authors1(authors.begin(), authors.end());
	std::map<std::string, std::string> authors2(authors);
}

void SetAndMap::MyMap1() {
	std::vector<int> ivec;
	for (std::vector<int>::size_type i = 0; i != 10; ++i) {
		ivec.push_back(i);
		ivec.push_back(i);
	}
	std::set<int> iset(ivec.cbegin(), ivec.cend());
	std::multiset<int> mset(ivec.cbegin(), ivec.cend());
	std::cout << ivec.size() << std::endl;
	std::cout << iset.size() << std::endl;
	std::cout << mset.size() << std::endl;
}

void SetAndMap::MyMap2() {
	std::map<std::string, std::vector<std::string>> str_strVec_Map{
		{"chen",{"cyc","cyx"}},
		{"luo",{"lym","lzx"}}
	};
	std::map<std::string, std::list<int>> str_intList_Map;
	std::map<std::vector<int>::iterator, int> iiter_map;

	std::list<int> ilist;
	//std::map<std::list<int>::iterator, int> iiterListMap{ { ilist.begin(),3} };
}

void SetAndMap::compareIsbn() {
	std::multiset<Sales_data, decltype(mcompareIsbn)*> bookstore(mcompareIsbn);
	Sales_data sd(23);
	bookstore.insert(sd);
}



void SetAndMap::mpair() {
	std::pair<std::string, std::string> anon;
	std::pair<std::string, std::size_t> word_count;
	std::pair<std::string, std::vector<int>> line;
	std::pair<std::string, std::string> autors{ "cyc","lym" };
	auto autoPair = std::make_pair("cyc", "lym");
	std::cout << autoPair.first << std::endl;
	autoPair.first = "love";
	std::cout << autoPair.first << std::endl;
}

void SetAndMap::mpair1() {
	std::pair<Sales_data, int> pair1(Sales_data(10), 10);
	std::pair<Sales_data, int> pair2(Sales_data(100), 100);
	if (pair1 < pair2) {
		std::cout << std::boolalpha << true << std::endl;
	}
}

std::pair<std::string, int> SetAndMap::process(std::vector<std::string> &v) {
	if (!v.empty()) {
		return{ v.back(),v.back().size() };
		return std::pair<std::string, int>(v.back(), v.back().size());
		return std::make_pair(v.back(), v.back().size());
	}
	else
		return std::pair<std::string, int>();
}

void SetAndMap::readpair() {
	std::string str;
	int iNum;
	std::vector<std::pair<std::string,int>> pVec;
	
	while (std::cin >> str >> iNum) {
		std::pair<std::string, int> sipair(str,iNum);
		pVec.push_back(sipair);
		std::cout << std::endl;
	}

	for (const auto &c : pVec) {
		std::cout << "first..  " << c.first << "  senddec...   " << c.second<<std::endl;
	}
}

void SetAndMap::keyType() {
	std::set<std::string>::value_type v1 = "cyc";
	std::set<std::string>::key_type v2 = "cyc";
	std::map<std::string, int>::value_type v3("cyc", 32);
	std::map<std::string, int>::key_type v4 = "cyc";
	std::map<std::string, int>::mapped_type v5 = 4;


	std::map<std::string, std::vector<std::string>> str_strVec_Map{
		{ "chen",{ "cyc","cyx" } },
		{ "luo",{ "lym","lzx" } }
	};
	std::map<std::string, std::vector<std::string>>::iterator miter = str_strVec_Map.begin();
	std::map<std::string, std::vector<std::string>>::value_type value = *miter;
	//value.first = std::string("cyc");
	value.second = {};

	std::set<int> iset{ 0,1,2,3,4,5,6,7,8,9 };
	std::set<int>::iterator set_iter = iset.begin();
	if (set_iter != iset.end()) {
		//*set_iter = 42;
	}
	if (iset.find(1)!=iset.end()) {
		//(*iset.find(1)) = 32;
	}

}

void SetAndMap::insertMap() {
	std::vector<int> ivec = { 2,4,6,8,2,4,6,8 };
	std::set<int> set2;
	set2.insert(ivec.cbegin(), ivec.cend());
	set2.insert({ 1, 3, 5, 7, 1, 3, 5, 7 });
}

void SetAndMap::insertMap1() {
	std::map<std::string, std::size_t> word_count{ { "cyc",3 } };
	std::string word("cyc");
	std::pair<std::map<std::string, std::size_t>::iterator, bool> res = word_count.insert({word,3});
	if (!res.second) {
		++res.first->second;
	}

	std::pair<std::map<std::string, std::size_t>::iterator, bool> res1 = word_count.emplace(std::make_pair("lym",3));
	if (res1.second) {
		std::cout << "insert sucessed.....   " << std::endl;
	}
}


void SetAndMap::transform(std::string &str) {
	for (const auto &c : map_transfrom_text) {
		if (c.first == str) {
			str = c.second;
			break;
		}
	}
}

void SetAndMap::swapForMap() {
	for (auto &c : v_text)
		transform(c);
	for (const auto &c : v_text)
		std::cout << c << " ";
}