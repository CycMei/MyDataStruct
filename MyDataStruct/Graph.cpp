#include "Graph.h"
#include<exception>
#include<iostream>
#include<deque>
#include<algorithm>
#include<iterator>

namespace GraphStruct {

	unsigned int Graph::time = 0;

	//构造图，传进来的是图的完全表示（无向图的所有边）
	Graph::Graph(int cuiVexNum, int cuiArcNum,const std::vector<std::vector<int>> edge)
		try :iVexNum(cuiVexNum), iArcNum(cuiArcNum) {
		std::logic_error le("arcNum or edge or vexNum erro");
		if (cuiVexNum <= 0 || cuiArcNum <= 0||cuiArcNum<cuiVexNum-1) {
			throw le;
		}
		for (const auto c : edge) {
			if (c.size() != 2)
				throw le;
			for (const auto cc : c) {
				if (cc > cuiVexNum)
					throw le;
			}
		}
			
		for (int i = 0; i != cuiVexNum; ++i) {
			vNode.push_back(std::make_shared<SVNode>(i));
			copyvNode.push_back(std::make_shared<SVNode>(i));
		}
		for (const auto c : edge) {
			int head = c[0];
			int end = c[1];
			SPArcNode endNode(std::make_shared<SArcNode>(end));
			if (!vNode[head]->firstArc)
				vNode[head]->firstArc = endNode;
			else {
				SPArcNode temp = vNode[head]->firstArc;
				SPArcNode temps = nullptr;
				while (temp) {
					temps = temp;
					temp = temp->nextArc;
				}
				temps->nextArc = endNode;
			}
		}
	}
	catch (const std::exception &erro) {
		std::cout << erro.what() << std::endl;
	}

	//打印图的邻接链表
	void Graph::printGraph(const std::vector<SPSVNode> &node) {
		std::cout << "邻接链表： >>>>>  " << std::endl;
		for (const auto c : node) {
			auto temp = c->firstArc;
			while (temp) {
				std::cout << c->data<<" -> "<< temp->adjvex << ", ";
				temp = temp->nextArc;
			}
			std::cout << std::endl;
		}
	}

	//重置每个顶点
	void Graph::restNode(const std::vector<SPSVNode> &node) {
		for (auto &c : node) {
			c->color = ColorType::WHRITE;
			c->parent = nullptr;
			c->distance = 0;
			c->begTime = 0;
			c->endTime = 0;
		}
	}

	//有向图的转置
	void Graph::Graph_T() {
		for (const auto c : vNode) {
			SPArcNode temp = c->firstArc;
			int head = c->data;
			while (temp) {
				SPArcNode endNode(std::make_shared<SArcNode>(head));
				int end = temp->adjvex;
				if (!copyvNode[end]->firstArc)
					copyvNode[end]->firstArc = endNode;
				else {
					SPArcNode ctemp = copyvNode[end]->firstArc;
					SPArcNode temps = nullptr;
					while (ctemp) {
						temps = ctemp;
						ctemp = ctemp->nextArc;
					}
					temps->nextArc = endNode;
				}
				temp = temp->nextArc;
			}
		}
	}

	//打印拓扑链表
	void Graph::printTopList(const std::list<std::list<int>> &list) {
		std::cout << "top list..." << std::endl;
		for (const auto c : list) {
			std::copy(c.cbegin(), c.cend(), std::ostream_iterator<int>(std::cout, " "));
			std::cout<<" , " << std::endl;
		}
	}

	//深度搜素
	void Graph::DFSVisit(const std::vector<SPSVNode> &Node,SPSVNode node) {
		++time;
		node->begTime = time;
		node->color = ColorType::GRAY;
		SPArcNode tempNode = node->firstArc;
		while (tempNode) {
			SPSVNode vnode = Node[tempNode->adjvex];
			if (vnode->color == ColorType::WHRITE) {
				vnode->parent = node;
				DFSVisit(Node,vnode);
			}
			tempNode = tempNode->nextArc;
		}
		node->color = ColorType::BLACK;
		++time;
		node->endTime = time;
		//std::cout << node->data << " < --- " << " ";
		curList.push_back(node->data);
	}

	void Graph::DFS(const std::vector<SPSVNode> &node) {
		restNode(node);
		restStaticTime();
		topList.clear();
		for (const auto &c : node) {
			if (c->color == ColorType::WHRITE) {
				//std::cout << "vvvv   " << std::endl;
				curList.clear();
				DFSVisit(node, c);
				topList.push_back(curList);
			}
		}
	}

	//广度搜索
	void Graph::BFS() {
		restNode(vNode);
		vNode[0]->color = ColorType::GRAY;
		vNode[0]->distance = 0;
		vNode[0]->parent = nullptr;
		std::deque<SPSVNode> qNode;
		qNode.push_back(vNode[0]);
		while (qNode.cbegin()!=qNode.cend()) {
			std::deque<SPSVNode>::const_iterator beg = qNode.cbegin();
			SPSVNode vnode = *beg;
			qNode.pop_front();
			SPArcNode temp = vnode->firstArc;
			while (temp) {
				SPSVNode arcNode = vNode[temp->adjvex];
				if (arcNode->color == ColorType::WHRITE) {
					arcNode->color = ColorType::GRAY;
					arcNode->distance = vnode->distance + 1;
					arcNode->parent = vnode;
					qNode.push_back(arcNode);
				}
				temp = temp->nextArc;
			}
			vnode->color = ColorType::BLACK;
		}
	}

	void Graph::printBFS(const int index) {
		if (index >= iVexNum||index<0)
			std::cout << "vex no exist。。。" << std::endl;
		auto temp = vNode[index];
		while (temp) {
			std::cout << temp->data << " <- ";
			temp = temp->parent;
		}
		std::cout << std::endl;
	}

	//连通分量
	void Graph::unions() {
		Graph_T();
		std::cout << "cccccss  转置  " << std::endl;
		printGraph(copyvNode);
		copyDFS(copyvNode);
		std::cout << "cccc  top list..." << std::endl;
		printTopList(ctopList);
	}

	void Graph::copyDFS(const std::vector<SPSVNode> &node) {
		restNode(node);
		restStaticTime();
		ctopList.clear();
		for (auto beg = topList.crbegin(); beg != topList.crend(); ++beg) {
			for (auto cbeg = beg->crbegin(); cbeg != beg->crend(); ++cbeg) {
				const int index = *cbeg;
				if (copyvNode[index]->color == ColorType::WHRITE) {
					std::cout << "vvvv   " << std::endl;
					curList.clear();
					DFSVisit(node, copyvNode[index]);
					ctopList.push_back(curList);
				}
			}
		}
	}	
}


void myChart() {
	std::vector <std::vector<int>> vec{
		{0,1},{0,2},
		{1,0},{1,4},{1,6},
		{2,0},{2,3},
		{3,2},
		{4,1},{4,5},{4,6},
		{5,4},{5,6},{5,7},
		{6,1},{6,4},{6,5},{6,7},
		{7,5},{7,6}
	};
	std::vector<std::vector<int>> vec1{
		//有向图
		{0,1},{0,4},
		{1,2},{1,3},
		{2,1},
		{3,3},
		{4,0},{4,3},
		{5,0},{ 5,6 } ,{5,2},
		{6,2},{6,7},
		{7,5}
	};

	GraphStruct::Graph cgraph(8, vec1.size(), vec1);
	cgraph.printGraph(cgraph.getvNode());
	cgraph.DFS(cgraph.getvNode());
	cgraph.printTopList(cgraph.getTopList());
	
	cgraph.unions();
	
}