#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<list>
#include<string>
#include<numeric>
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
		vector<const char*> listChar{ "cyc" ,"abc","bbb" };
		if (listChar.size() >= vstr.size()) {
			bool res=equal(vstr.cbegin()+1, vstr.cend(), listChar.begin() + 1);
			cout << boolalpha<<res << endl;
		}
	}
}

void myAlogrithm() {
	Algorithm::test1();
}