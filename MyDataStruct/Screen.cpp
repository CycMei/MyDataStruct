#include "Screen.h"
#include<iostream>
#include<functional>
#include<algorithm>
#include<vector>

Screen::Screen(const std::string str,pos index) 
try :contents(str), cursor(index){

}
catch (...) {
	std::cout << "erro...." << std::endl;
}

Screen::~Screen() {

}

char Screen::get_cursor() const {
	if (cursor >= contents.size())
		return '\0';
	return contents[cursor];
}

char Screen::get() const {
	return '\0';
}

char Screen::get(pos ht, pos wd) const {
	return '\0';
}


Screen & Screen::move(Directions cm) {
	return (this->*Menu[cm])();
}

const std::string Screen::* Screen::pData() {
	return &Screen::contents;
}

const Screen::pos Screen::* Screen::pCursor() {
	return &Screen::cursor;
}

Screen &Screen::action(Screen &sc, char (Screen::*psc)(pos, pos) const) {
	return Screen("cyc", 0);
}

Screen::Action Screen::Menu[] = {
	&Screen::home,
	&Screen::forward,
	&Screen::back,
	&Screen::up,
	&Screen::down
};


void myPointerToMember() {
	//const int *p;
	//int i = 3;
	//const int r = 4;
	//p = &i;
	//p = &r;
	const std::string Screen::*pdata = &Screen::contents;
	Screen myScreen("cyc", 1), *pScreen = &myScreen;
	std::cout << "...   " << myScreen.*pdata << std::endl;
	std::cout << "...   " << pScreen->*pdata << std::endl;
	std::cout << std::endl;
	const std::string Screen::*pdasta = Screen::pData();
	std::cout << "...   " << myScreen.*pdasta << std::endl;
	std::cout << std::endl;
	const Screen::pos Screen::*pCursor = Screen::pCursor();
	std::cout << "...   " << myScreen.*pCursor << std::endl;
	std::cout << std::endl;
	char (Screen::*getCursor)() const = &Screen::get_cursor;
	char (Screen::*gets)(Screen::pos, Screen::pos) const = &Screen::get;
	std::cout << "char:  " << (myScreen.*getCursor)() << std::endl;
	std::cout << "char:  " << (pScreen->*gets)(1,1) << std::endl;
	std::cout << std::endl;
	using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
	Action getsc = &Screen::get;
	std::cout << std::endl;
	myScreen.action(myScreen,getsc);
	std::cout << std::endl;
	std::cout << std::endl;
	std::vector<std::string*> pvec;
	std::function<bool(const std::string*)> fp = &std::string::empty;
	std::find_if(pvec.cbegin(), pvec.cend(), fp);
	std::find_if(pvec.cbegin(), pvec.cend(), std::mem_fn(&std::string::empty));
	//std::find_if(pvec.cbegin(), pvec.cend(), std::bind(&std::string::empty,_1));
}