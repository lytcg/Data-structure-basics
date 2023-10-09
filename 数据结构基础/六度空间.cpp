#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
#define MAXSIZE 10005
typedef struct Node* AdjList;
struct Node {
	int adjv;
	AdjList next;
};
AdjList G[MAXSIZE];
bool visit[MAXSIZE];
int N;//�ڵ���
int M;//����
//��ʼ������״̬
void initVisit() {
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
}
//��ʼ��
void init() {
	int v1, v2;
	AdjList newnode;
	cin >> N >> M;
	//��ʼ���ڵ㣬��1��N
	for (int i = 1; i <= N; i++) {
		G[i] = new struct Node();
		G[i]->adjv = i;
		G[i]->next = NULL;
	}
	//��ʼ����
	for (int i = 0; i < M; i++) {//M��{
		cin >> v1 >> v2;
		newnode = new struct Node();
		newnode->adjv = v1;
		newnode->next = G[v2]->next;
		G[v2]->next = newnode;

		newnode = new struct Node();
		newnode->adjv = v2;
		newnode->next = G[v1]->next;
		G[v1]->next = newnode;
	}
}
int BFS(int v) {
	queue<int>q;
	int tmp;
	int level = 0;
	int last = v;//ÿ�����һ���ڵ�
	int tail = v;//ÿ����ӵĽڵ�
	AdjList node;
	visit[v] = 1;
	int cnt = 1;
	q.push(v);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		node = G[tmp]->next;
		while (node != NULL) {
			if (!visit[node->adjv]) {
				visit[node->adjv] = 1;
				q.push(node->adjv);
				cnt++; tail = node->adjv;
			}
			node = node->next;
		}
		//last��ÿ�����һ��Ԫ�أ���last����ʱ��tmp=last��
		//��������Ԫ�س��ӣ�level+1
		//��ʱtail����һ�����һ��Ԫ�أ�last�������һ���������Ľڵ�
		//last=tail����ʼͳ����һ��
		if (tmp == last) {
			level++;
			last = tail;
		}
		if (level == 6) {
			break;
		}
	}
	return cnt;
}
void SDS() {
	int cnt;
	double num;
	for (int i = 1; i <= N; i++) {
		initVisit();
		cnt = BFS(i);
		cout << i << ": ";
		num = 100.0 * cnt / N;
		printf("%.2f", num);
		cout << "%" << endl;
	}
}
int main() {
	init();
	SDS();
}

