#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;
#define Inf 100000
int G[105][105];
int Nv, Ne, sum;
int parent[105];
struct Node {
	int v1, v2;
	int weight;
	bool operator<(const Node& b)const {
		return this->weight > b.weight;
	}
};
vector<Node>MST;//
priority_queue<Node> q;
void build() {
	cin >> Nv >> Ne;
	int v1, v2, weight;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = 0;
		}
		parent[i] = -1;
	}
	for (int i = 1; i <= Ne; i++) {
		cout << "输入边的两个节点和权重： ";
		cin >> v1 >> v2 >> weight;
		Node tmpE;
		tmpE.v1 = v1;
		tmpE.v2 = v2;
		tmpE.weight = weight;
		q.push(tmpE);
	}
}
//路径压缩查找
int find(int x) {
	if (parent[x]<0) {
		return x;
	}
	else {
		return parent[x] = find(parent[x]);//此处应返回parent[x]
	}
}
//按秩归并
void Union(int x1, int x2) {
	if (parent[x1] < parent[x2]) {
		parent[x1] += parent[x2];
		parent[x2] = x1;
	}
	else {
		parent[x2] += parent[x1];
		parent[x1] = x2;
	}
}
void kruskal() {
	//最小生成树的边不到Nv-1条且还有边
	while (MST.size() < Nv - 1 && !q.empty()) {
		Node E = q.top();//从最小堆里取出权重最小的一条边
		q.pop();
		//检查是否在同一个集合
		if (find(E.v1) != find(E.v2)) {
			sum += E.weight;
			Union(E.v1, E.v2);
			MST.push_back(E);
		}
	}
}
void output() {
	cout << "被收录顺序：" << endl;
	for (int i = 0; i < Nv-1; i++)
		cout <<"("<<MST[i].v1<<","<<MST[i].v2<<")" << MST[i].weight << " ";
	cout << "权重和为：" << sum << endl;
	cout << "生成树：" << endl;
	for (int i = 1; i <= Nv; i++)
		cout << i << "的父节点为： " << parent[i] << endl;
}
int main() {
	build();
	kruskal();
	output();

	return 0;
}
