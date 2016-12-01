#ifndef GRAPH_H
#define GRAPH_H

#include<memory>
#include<vector>
#include<list>
namespace GraphStruct {
	//��ɫ���࣬WHITE:δ���ʣ�
	//GRAY:�����ˣ�����ص��ڽӵ㻹û�з����꣬
	//BLACK:���ʹ���
	enum class ColorType {WHRITE,GRAY,BLACK};

	struct SArcNode;
	using SPArcNode = std::shared_ptr<SArcNode>;
	//�߱���
	struct SArcNode {
		const int adjvex;	//�ñ�ָ��Ľ��
		SPArcNode nextArc;	//ָ����һ����
		const int doc;		//Ȩֵ
		SArcNode(const int data, const int edge) :adjvex(data), nextArc(nullptr), doc(edge) {

		}
		explicit SArcNode(const int data) :adjvex(data), nextArc(nullptr),doc(0) {

		}
		~SArcNode(){}
	};

	//ͷ���
	struct SVNode;
	using SPSVNode = std::shared_ptr<SVNode>;
	struct SVNode {
		const int data;					//������Ϣ
		SPArcNode firstArc;				//ָ���һ����ö����ڽӵı�
		ColorType color;				//������ɫ
		SPSVNode parent;				//������
		unsigned int distance;			//��Դ��㵽�ý��ľ���
		unsigned int begTime;			//��ʼʱ��
		unsigned int endTime;			//����ʱ��
		explicit SVNode(const int data) :
			data(data), firstArc(nullptr), color(ColorType::WHRITE), parent(nullptr), distance(-1),
			begTime(-1), endTime(-1){}
		~SVNode(){}
	};

	// ͼ
	class Graph {
	public:
		Graph(int cuiVexNum, int cuiArcNum,const std::vector<std::vector<int>>);
		~Graph(){}
		void printGraph(const std::vector<SPSVNode>&);
		void BFS();
		void printBFS(const int index);
		void DFS(const std::vector<SPSVNode>&);
		void printTopList(const std::list<std::list<int>> &list);
		void unions();
		const std::vector<SPSVNode> &getvNode() const { return vNode; }
		const std::vector<SPSVNode> &getcopyvNode() const { return copyvNode; }
		const std::list<std::list<int>> getTopList() const{ return ctopList; }
	private:
		void restNode(const std::vector<SPSVNode> &);
		void DFSVisit(const std::vector<SPSVNode> &,SPSVNode);
		void restStaticTime() {time = 0;}
		void Graph_T();
		void copyDFS(const std::vector<SPSVNode> &node);
	private:
		std::vector<SPSVNode> vNode;			//ͼ�����ж���
		int iVexNum;							//ͼ�Ķ�����
		int iArcNum;							//ͼ�ı���
		static unsigned int time;				//ȫ��ʱ��
		std::list<std::list<int>> topList;		//��������
		std::list<std::list<int>> ctopList;		//��������
		std::list<int> curList;					//һ���ڵ������(����������������)
		std::vector<SPSVNode> copyvNode;		//ͼ��ת��
	};
}

#endif // !GRAPH_H
