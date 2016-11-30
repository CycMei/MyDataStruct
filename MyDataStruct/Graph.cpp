#include "Graph.h"
#include<exception>
#include<iostream>
#include<deque>
#include<algorithm>
#include<iterator>

namespace GraphStruct {

	unsigned int Graph::time = 0;

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
		vedge = edge;
			
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

	void Graph::printGraph(const std::vector<SPSVNode> &node) {
		for (const auto c : node) {
			auto temp = c->firstArc;
			while (temp) {
				std::cout << c->data<<" -> "<< temp->adjvex << ", ";
				temp = temp->nextArc;
			}
			std::cout << std::endl;
		}
	}
	
	void Graph::restNode(const std::vector<SPSVNode> &node) {
		for (auto &c : node) {
			c->color = ColorType::WHRITE;
			c->parent = nullptr;
			c->distance = 0;
			c->parent = nullptr;
			c->begTime = 0;
			c->endTime = 0;
		}
	}

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
			//if (vnode->color == ColorType::BLACK)
			//	tempNode = tempNode->nextArc;
			//else
			//	break;
		}
		node->color = ColorType::BLACK;
		++time;
		node->endTime = time;
		topList.push_back(node->data);
	}

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

	void Graph::DFS(const std::vector<SPSVNode> &node) {
		restNode(node);
		restStaticTime();
		for (const auto &c : node) {
			if (c->color == ColorType::WHRITE) {
				DFSVisit(node,c);
				topList.push_back(-1);
			}
		}
	}

	void Graph::printTopList() {
		std::cout << "top list..." << std::endl;
		std::copy(topList.cbegin(), topList.cend(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	void Graph::unions() {
		Graph_T();
		printGraph(copyvNode);
		DFS(copyvNode);
		printTopList();
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
		{0,1},
		{1,2},{1,4}, { 1,5 },
		{2,3},{2,6},
		{3,2},{3,7},
		{4,0},{4,5},
		{5,6},
		{6,5},{6,7},
		{7,7}
	};
	//////////
	//GraphStruct::Graph graph(8, 10, vec);
	//graph.printGraph();
	//graph.BFS();
	//graph.printBFS(3);
	//graph.DFS();
	//graph.printTopList();
	//std::cout<<"DFS reslutl...  " << std::endl;
	//graph.printBFS(7);
	//graph.printBFS(6);
	//////////
	GraphStruct::Graph cgraph(8, vec1.size(), vec1);
	cgraph.printGraph(cgraph.getvNode());
	cgraph.DFS(cgraph.getvNode());
	cgraph.printTopList();
	std::cout << "cccccss  转置  " << std::endl;
	cgraph.unions();
	
}