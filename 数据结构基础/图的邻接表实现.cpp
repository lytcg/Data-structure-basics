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
	cout << "����ڵ������ "<<endl;
	cin >> nv;//����ڵ����
	cout << endl << "�ڵ㣺";
	for (int i = 0; i < nv; i++) {
		graph[i] = new struct AdjVnode();
		graph[i]->adjv = i;
		graph[i]->next = NULL;
		cout << i << " ";
	}
	cout <<endl<< "����Ҫ����ıߵĸ���" << endl;
	cin >> ne;//����ߵĸ���
	int v1, v2, weight;
	adjList newNode;
	cout << "ÿ��ֱ�����Ҫ���ӵ������ڵ��Ȩ�أ���" << ne << "�����ݣ�ע�������ڵ������ܴ���" << nv-1<<"(�ڵ��±��0��ʼ)" << endl;
	for (int i = 0; i < ne; i++) {
		//ne������Ҫ���ӵĽڵ��Ȩ��
		cin >> v1 >> v2 >> weight;
		newNode=new struct AdjVnode();
		//��v1���뵽v2��������
		newNode->adjv = v1;
		newNode->weight = weight;
		newNode->next = graph[v2]->next;
		graph[v2]->next = newNode;
		//��v2���뵽v1��������
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
