#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<list>
#include<string>
#include<numeric>
#include<functional>
namespace Algorithm {
	using namespace std;
	void test1() {
		const vector<int> vec{ 1,2,3,4,5,6,7,57,76,5 };
		const vector<int>::const_iterator result=find(vec.cbegin(), vec.cend() - 4, 8);
		cout << *result << endl;

		int ia[] = { 27,210,12,47,109,83 };
		int val = 83;
		int *mend = &ia[6];
		if (mend == end(ia))
			cout << boolalpha << true << endl;
		int *iaresult=find(begin(ia), end(ia) - 2, 83);
		cout << *iaresult << endl;

		int cresult=count(vec.cbegin(), vec.cend()-1, 5);
		cout << cresult << endl;

		list<string> ls{ "abc","cyc","abc","cyc" };
		int lsresult = count(ls.cbegin(), ls.cend(), "abc");
		cout << lsresult << endl;

		string sresult=accumulate(ls.cbegin(), ls.cend(), string(""));
		cout << sresult << endl;

		vector<string> vstr{ "cyc","abc" };
		vector<const char*> listChar{ "cyc" /*,"abc","bbb"*/ };
		bool res=equal(vstr.cbegin()+1, vstr.cend(), listChar.begin());
		cout << boolalpha<<res << endl;
	}

	void test2() {
		vector<int> vec{ 1,2,3,4,5,6,7,57,76,5 };
		fill(vec.begin(), vec.end(), 1);
		for (const auto &c : vec) {
			cout << c << "  ";
		}
		cout << endl;

		vector<int> cvec;
		fill_n(cvec.begin(), cvec.size(), 0);
		fill_n(vec.end() -2, 2, 10);
		for (const auto &c : vec) {
			cout << c << "  ";
		}
	}

	void test3() {
		int al[]{ 0,1,2,3,4,5,6,7,8,9 };
		int a2[2];
		auto result=copy(begin(al), begin(al) + 1, a2);
		if (result == &a2[1])
			cout << boolalpha << true << endl;

		replace(begin(al), begin(al) + 2, 0, 10);
		cout << *al << endl;
	}

	bool isShortter(const string &lhs, const string &rhs) {
		return lhs.size() < rhs.size();
	}
	bool isLength(const string &hs) {
		return hs.size() <= 3;
	}

	void test4() {
		vector<string> sVec{ "over","the","quick","red","fox","jumps","over","the","slow","red","turtle" };
		sort(sVec.begin(), sVec.end());
		auto res=unique(sVec.begin(), sVec.end());
		sVec.erase(res, sVec.end());
		//sort(sVec.begin(), sVec.end(), isShortter);
		//stable_sort(sVec.begin(), sVec.end(), isShortter);
		//vector<string>::const_iterator rses= partition(sVec.begin(), sVec.end(), isLength);
		auto rses=stable_partition(sVec.begin(), sVec.end(), isLength);
		cout << *rses << endl;
		for (const auto &c : sVec) {
			cout << c << ",";
		}
		cout << endl;
		
	}

	void test5() {
		vector<string> sVec{ "over","the","quick","red","fox","jumps","over","the","slow","red","turtle" };
		sort(sVec.begin(), sVec.end());
		auto res = unique(sVec.begin(), sVec.end());
		sVec.erase(res, sVec.end());
		stable_sort(sVec.begin(), sVec.end(), [](const string &lhs, const string &rhs)->bool {
			return lhs.size() < rhs.size();
		});
		int sz = 4;
		auto sssres=find_if(sVec.begin(), sVec.end(), [sz](const string &hs)->bool {
			return hs.size() >= sz;
		});
		if (sssres != sVec.end()) {
			cout << sssres-sVec.end()  << endl;
			for_each(sssres, sVec.end(), [](const string &hs) {
				cout << hs << "  ";
			});
		}
		cout << endl;

		for (const auto &c : sVec) {
			cout << c << ",";
		}
		cout << endl;

		auto intResult=[](const int lhs, const int rhs)->int {
			return lhs + rhs;
		};
		int iAnd = 3;
		auto iAndResult = [iAnd](const int hs)->int {
			return iAnd + hs;
		};
		cout << intResult(2, 1) << endl;
		cout << iAndResult(3) << endl;
	}

	namespace {
		int isAs0 = 5;
	}

	void test6() {
		rsize_t v1 = 42;
		auto f = [v1]()->int{
			return v1;
		};
		auto ff = [&v1]()->int {
			return ++v1;
		};
		auto fff = [v1]() mutable ->int {
			return ++v1;
		};
		v1 = 0;
		cout << f() << endl;
		cout << ff() << endl;
		cout << fff() << endl;

		vector<int> vec{ 1,-2,2,3,-4 };
		transform(vec.begin(), vec.end(), vec.begin(), [](int i)->int {
			if (i < 0)
				return -i;
			else
				return i;
		});
		int a=count_if(vec.cbegin(), vec.cend(), [](const int i)->bool {
			if (i >= 0)
				return true;
			else
				return false;
		});
		cout << a << endl;

		static bool (*isf)() =[]()->bool {
			if (isAs0 < 0)
				return true;
			--isAs0;
			isf();
		};
		cout << boolalpha << isf() << endl;
	}

	bool check_size(const string &s, string::size_type sz) {
		return s.size() >= sz;
	}

	ostream &print(ostream &os, const string &s, char c) {
		return os << s << c;
	}
	void test7() {
		using namespace std::placeholders;
		auto check6 = bind(check_size, _1, 6);
		bool res=check6(string("sssss"));
		cout << boolalpha << res << endl;

		vector<string> sVec{ "abc" };
		
	 	for_each(sVec.begin(), sVec.end(), bind(print, ref(cout), _1, ' '));
	}

	void test8() {
		list<int> lst{ 1,2,3,4 };
		list<int> lst2, lst3, lst4;
		copy(lst.cbegin(), lst.cend(), front_inserter(lst2));
		for (const auto &c : lst2) {
			cout << c << "  ";
		}
		cout << endl;
		copy(lst.cbegin(), lst.cend(), back_inserter(lst3));
		for (const auto &c : lst3) {
			cout << c << "  ";
		}
		cout << endl;
		copy(lst.cbegin(), lst.cend(), inserter(lst4, lst4.end()));
		for (const auto &c : lst4) {
			cout << c << "  ";
		}
		cout << endl;
		front_insert_iterator<list<int>> res= front_inserter(lst);

		vector<int> iiVec{ 3,2,2,34,43,2,2 };
		sort(iiVec.begin(), iiVec.end());
		list<int> iList;
		unique_copy(iiVec.cbegin(), iiVec.cend(), back_inserter(iList));
		for (const auto &c : iList) {
			cout << c << "  ";
		}
		cout << endl;

	}

	void test9() {
		//istream_iterator<int> in_iter(cin);
		//istream_iterator<int> eof;
		//vector<int> vec, vec2(in_iter, eof);
		//while (in_iter!=eof) {
		//	vec.push_back(*in_iter++);
		//}
		//for (const auto &c : vec2) {
		//	cout << c << "  ";
		//}
		//cout << endl;

		istream_iterator<int> in1(cin);
		istream_iterator<int> eof1;
		cout << accumulate(in1, eof1, 0) << endl;

	}

	void test10() {
		ostream_iterator<int> out_iter(cout, " ");
		vector<int> vec{ 32,32,34,32,32,3221,23 };
		copy(vec.cbegin(), vec.cend(), out_iter);
	}
}

void myAlogrithm() {
	Algorithm::test10();
}