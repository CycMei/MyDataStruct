#ifndef CHART_H
#define CHART_H

#include"CNode.h"
#include<vector>
#include<map>

template<typename T> class ChartNode :public CNODE::CNode<T> {
public:
	ChartNode(const T key);
	~ChartNode(){
		std::cout << "delete charnode...." << std::endl;
	}
	SP_CNode pNext;
public:

};

template<typename T> class Chart {
private:
	using SP_ChartNode = std::shared_ptr<ChartNode<T>>;
public:
	Chart();
	~Chart(){}
	void createLinkTable();
private:
	std::vector<std::multimap<ChartNode<T>, ChartNode<T>>> LinkTable;
};

#endif // !CHART_H

template<typename T> inline ChartNode<T>::ChartNode(const T key)
try :CNODE::CNode<T>(key) {

}
catch (...) {
	std::cout << "constructor chartnode eroo..... " << std::endl;
}


template<typename T> inline Chart<T>::Chart()
try {

}
catch (...) {
	std::cout << "constructor Chart...erro..." << std::endl;
}

// 创建邻接链表
template<typename T> void Chart<T>::createLinkTable() {

}
