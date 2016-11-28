#ifndef CHART_H
#define CHART_H
#include<vector>
#include<memory>
#include<iostream>
#include<map>
#include<string>
#include<exception>

enum Color { BLACK, WHITE, GRAY };
using vvInt = const std::vector<std::vector<int>>;
struct ENode;
using SP_Enode = std::shared_ptr<ENode>;
struct ENode {
	int ivex;
	SP_Enode nextEdge;
	SP_Enode parent;
	Color color;
	int distance;
	ENode(const int i):ivex(i),distance(-1),color(WHITE),parent(nullptr),nextEdge(nullptr){}
};
struct VNode {
	int data;
	SP_Enode firstEdge;
	VNode(const int i) :data(i), firstEdge(nullptr) {}
};




class Chart {
private:
	int iChartVecNum;
	int iChartEdgNum;
	std::vector<VNode> vecVNode;
	std::map<int, SP_Enode> mENode;
private:
	void LinkLast(SP_Enode curNode, SP_Enode nextNode);
	SP_Enode isConstructorEnode(const int &index);
public:
	Chart(const int, const int, vvInt);
	void WidtchFirstSearch();
	~Chart(){}
};

#endif // !CHART_H

//构造 并 创建邻接链表

