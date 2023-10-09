#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef struct AdjVnode* adjList;
struct AdjVnode {
	int weight;
	int	adjv;
	adjList next;
};
adjList graph[MAXSIZE];
int nv, ne;

void buildGraph() {
	cout << "输入节点个数： "<<endl;
	cin >> nv;//输入节点个数
	cout << endl << "节点：";
	for (int i = 0; i < nv; i++) {
		graph[i] = new struct AdjVnode();
		graph[i]->adjv = i;
		graph[i]->next = NULL;
		cout << i << " ";
	}
	cout <<endl<< "输入要插入的边的个数" << endl;
	cin >> ne;//输入边的个数
	int v1, v2, weight;
	adjList newNode;
	cout << "每组分别输入要连接的两个节点和权重，共" << ne << "组数据，注意两个节点数不能大于" << nv-1<<"(节点下标从0开始)" << endl;
	for (int i = 0; i < ne; i++) {
		//ne次输入要连接的节点和权重
		cin >> v1 >> v2 >> weight;
		newNode=new struct AdjVnode();
		//把v1插入到v2的链表中
		newNode->adjv = v1;
		newNode->weight = weight;
		newNode->next = graph[v2]->next;
		graph[v2]->next = newNode;
		//把v2插入到v1的链表中
		newNode=new struct AdjVnode();
		newNode->adjv = v2;
		newNode->weight = weight;
		newNode->next = graph[v1]->next;
		graph[v1]->next = newNode;
		cout << "insert finish" << endl;
	}
}
void printGraph() {
	adjList tmp;
	for (int i = 0; i < nv; i++) {
		tmp = graph[i];
		while (tmp != NULL) {
			cout << tmp->adjv <<"(" << tmp->weight <<")" << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

int main() {
	buildGraph();
	printGraph();
}
