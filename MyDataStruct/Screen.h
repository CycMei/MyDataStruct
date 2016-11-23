#ifndef SCREEN_H
#define SCREEN_H

#include<string>
class Screen {
private:
	friend void myPointerToMember();
	typedef std::string::size_type pos;
	using Action = Screen &(Screen::*)();
	enum Directions {HOME,FORWARD,BACK,UP,DOWN};
public:
	Screen(const std::string str, pos index);
	~Screen();
	char get_cursor() const;
	char get() const;
	char get(pos ht, pos wd) const;


	Screen &action(Screen&, char (Screen::*)(pos, pos) const);
	Screen &home(){ return Screen("cyc", 0); }
	Screen &forward(){ return Screen("cyc", 0); }
	Screen &back(){ return Screen("cyc", 0); }
	Screen &up(){ return Screen("cyc", 0); }
	Screen &down(){ return Screen("cyc", 0); }
	Screen &move(Directions);


	static const std::string Screen::*pData();
	static const pos Screen::*pCursor();
private:
	std::string contents;
	pos cursor;
	pos height, width;
	static Action Menu[];
};
#endif // !SCREEN_H
