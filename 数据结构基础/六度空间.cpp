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
int N;//节点数
int M;//边数
//初始化访问状态
void initVisit() {
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}
}
//初始化
void init() {
	int v1, v2;
	AdjList newnode;
	cin >> N >> M;
	//初始化节点，从1到N
	for (int i = 1; i <= N; i++) {
		G[i] = new struct Node();
		G[i]->adjv = i;
		G[i]->next = NULL;
	}
	//初始化边
	for (int i = 0; i < M; i++) {//M次{
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
	int last = v;//每层最后一个节点
	int tail = v;//每次入队的节点
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
		//last是每层最后一个元素，当last出队时（tmp=last）
		//本层所有元素出队，level+1
		//此时tail是上一层最后一个元素（last）的最后一条边所连的节点
		//last=tail，开始统计下一层
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

