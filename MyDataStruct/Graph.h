#ifndef GRAPH_H
#define GRAPH_H

#include<memory>
#include<vector>
#include<list>
namespace GraphStruct {
	//颜色种类，WHITE:未访问，
	//GRAY:访问了，但相关的邻接点还没有访问完，
	//BLACK:访问过了
	enum class ColorType {WHRITE,GRAY,BLACK};

	struct SArcNode;
	using SPArcNode = std::shared_ptr<SArcNode>;
	//边表结点
	struct SArcNode {
		const int adjvex;						//该边指向的结点
		SPArcNode nextArc;	//指向下一条边
		explicit SArcNode(const int data) :adjvex(data), nextArc(nullptr) {

		}
	};

	//头结点
	struct SVNode;
	using SPSVNode = std::shared_ptr<SVNode>;
	struct SVNode {
		const int data;					//顶点信息
		SPArcNode firstArc;				//指向第一条与该顶点邻接的边
		ColorType color;				//顶点颜色
		SPSVNode parent;				//父顶点
		unsigned int distance;			//从源结点到该结点的距离
		unsigned int begTime;			//开始时间
		unsigned int endTime;			//结束时间
		explicit SVNode(const int data) :
			data(data), firstArc(nullptr), color(ColorType::WHRITE), parent(nullptr), distance(-1),
			begTime(-1), endTime(-1){

		}
	};

	// 图
	class Graph {
	public:
		Graph(int cuiVexNum, int cuiArcNum,const std::vector<std::vector<int>>);
		~Graph(){}
		void printGraph(const std::vector<SPSVNode> &);
		void BFS();
		void printBFS(const int index);
		void DFS(const std::vector<SPSVNode>&);
		void printTopList();
		void unions();
		const std::vector<SPSVNode> &getvNode() const { return vNode; }
		const std::vector<SPSVNode> &getcopyvNode() const { return copyvNode; };
	private:
		void restNode(const std::vector<SPSVNode> &);
		void DFSVisit(const std::vector<SPSVNode> &,SPSVNode);
		void restStaticTime() {time = 0;}
		void Graph_T();
	private:
		std::vector<SPSVNode> vNode;			//图的所有顶点
		int iVexNum;							//图的顶点数
		int iArcNum;							//图的边数
		static unsigned int time;				//全局时间
		std::list<int> topList;					//拓扑链表
		std::vector<std::vector<int>> vedge;	//边集合的拷贝
		std::vector<SPSVNode> copyvNode;		//图的转置
	};
}

#endif // !GRAPH_H
