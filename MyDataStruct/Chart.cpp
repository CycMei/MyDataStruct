#include"Chart.h"
#include<deque>


void Chart::LinkLast(SP_Enode curNode, SP_Enode nextNode) {
	SP_Enode temp = curNode;
	SP_Enode temp1 = temp;
	SP_Enode preNode = nullptr;
	while (temp) {
		preNode = temp;
		temp = temp->nextEdge;
		if (temp&&temp->ivex == temp1->ivex)
			break;
	}
	preNode->nextEdge = nextNode;
}

SP_Enode Chart::isConstructorEnode(const int & index) {
	SP_Enode Enode;
	if (mENode.find(index) == mENode.end()) {
		Enode = std::make_shared<ENode>(index);
		std::pair<std::map<int, SP_Enode>::iterator, bool> result = mENode.insert(std::make_pair(index, Enode));
		if (!result.second) {
			std::string mesErro = "构造元素失败";
			std::cout << mesErro << std::endl;
		}
	}
	else
		Enode = mENode.find(index)->second;
	return Enode;
}

//构造 并 创建邻接链表
inline Chart::Chart(const int iVlen, const int iElen, vvInt edges)
try :iChartVecNum(iVlen), iChartEdgNum(iElen) {
	std::string mesErro("输入的边长度和边集合不一样或者不满足条件");
	std::logic_error lgc(mesErro);
	if (iVlen<0 || iElen<0 || iElen != edges.size() || edges[0].size() != 2)
		throw lgc;
	for (int i = 0; i != iVlen; ++i)
		vecVNode.push_back(VNode(i));

	for (int j = 0; j != iElen; ++j) {
		std::cout << j << std::endl;
		int edge1 = edges[j][0];
		int edge2 = edges[j][1];
		if (edge1 >= iVlen || edge2 >= iVlen)
			throw lgc;
		SP_Enode node1 = std::make_shared<ENode>(edge2);
		if (!vecVNode[edge1].firstEdge)
			vecVNode[edge1].firstEdge = node1;
		else
			LinkLast(vecVNode[edge1].firstEdge, node1);

		// 传进来的已经包含重复的，，对称 无向图
		//SP_Enode node2 = std::make_shared<ENode>(edge1);
		//if (!vecVNode[edge2].firstEdge)
		//	vecVNode[edge2].firstEdge = node2;
		//else
		//	LinkLast(vecVNode[edge2].firstEdge, node1);
	}
}
catch (const std::exception &ex) {
	std::cout << "constructor Chart...erro..." << ex.what() << std::endl;
}

void Chart::WidtchFirstSearch() {
	vecVNode[0].firstEdge->color = GRAY;
	vecVNode[0].firstEdge->distance = 0;
	vecVNode[0].firstEdge->parent = nullptr;
	std::deque<SP_Enode> dequeNode{ vecVNode[0].firstEdge };
	while (!dequeNode.empty()) {
		std::cout << "....   " << std::endl;
		SP_Enode temp = vecVNode[(*(dequeNode.begin()))->ivex].firstEdge;
		SP_Enode copyTemp = temp;
		dequeNode.pop_front();
		while (temp) {
			if (temp->color == WHITE) {
				temp->color = GRAY;
				temp->distance += 1;
				dequeNode.push_back(temp);
			}
			temp = temp->nextEdge;
		}
		copyTemp->color = BLACK;
	}
}




void myChart() {
	int vNum = 7;
	int eNum = 14;
	vvInt vec{
		{0,2},{0,3},{0,5},
		{1,2},
		{2,0},{2,1},{2,3},
		{3,0},{3,2},
		{4,6},
		{5,0},{5,6},
		{6,4},{6,5}
	};
	Chart chart(vNum, eNum, vec);
	chart.WidtchFirstSearch();
}