#include<iostream>
using namespace std;
#define Inf 10000000
int G[100][100];
int dist[100];//距离
int path[100];//路径
int collect[100];//被收录集合
int Nv;//顶点
int Ne;//边

void build() {
	int v1, v2;
	int	weight;
	cout << "输入顶点数： ";
	cin >> Nv;
	for (int i = 1; i <= Nv; i++) {
		//初始化图
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = 0;
		}
		//初始化路径 
		path[i] = -1;
		//初始化距离
		dist[i] = Inf;
		//初始化收录情况
		collect[i] = 0;
	}
	dist[0] = Inf;
	//初始化边
	cout << "输入边数： ";
	cin >> Ne;
	for (int i = 0; i < Ne; i++) {
		cout << "输入边的两个节点和权重: ";
		cin >> v1 >> v2 >> weight;
		G[v1][v2] = weight;
	}
}
void create(int s) {
	dist[s] = 0;
	collect[s] = 1;
	for (int i = 0; i <= Nv; i++) {
		if (G[s][i]) {
			dist[i] = G[s][i];
			path[i] = s;
		}
	}
}
int findMin(int s) {
	int min = 0;
	//查找未收录节点中dist最小者
	for (int i = 1; i <= Nv; i++) {
		if (i != s && !collect[i] && dist[i] < dist[min]) {
			min = i;
		}
	}
	return min;
}
void Dijkstra(int s) {
	create(s);
	while (1) {
		int v = findMin(s);
		if (!v) {
			//v=0,所有节点已收录
			break;
		}
		collect[v] = 1;
		for (int i = 1; i <= Nv; i++) {
			//如果未被收录
			if (!collect[i] && G[v][i]) {
				if (dist[i] > dist[v] + G[v][i]) {
					dist[i] = dist[v] + G[v][i];
					path[i] = v;
				}
			}
		}
	}
}
void output() {
	for (int i = 1; i <= Nv; i++)
		cout <<" 到节点"<<i<<"的距离" << dist[i] << endl;
	cout << endl;
	for (int i = 1; i <= Nv; i++)
		cout << path[i] << " ";
	cout << endl;
}
int main() {
	build();
	Dijkstra(1);
	output();
	return 0;
}
