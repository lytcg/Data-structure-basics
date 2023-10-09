#include<iostream>
#include<stack>
using namespace std;
#define Inf 1000000
int G[100][100];
int dist[100][100];//距离
int path[100][100];//路径
int Nv, Ne;
/*无向图，将边的权重输入，没有边的权重设为Inf，初始将所有path设为-1
floyd：从外到内进行k,i,j三重循环，检查 i-j的距离是否大于i-k-j的距离，如果大于
将后者的值赋给前者*/
/*测试数据：5  7
1 2 4
2 3 1
3 4 3
4 5 6
5 1 2
1 4 5
3 5 1*/
void build() {
	int v1, v2;
	int weight;
	cout << "输入节点数： ";
	cin >> Nv;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = Inf;
		}
	}
	cout << "输入边数（无向图）： ";
	cin >> Ne;
	for (int i = 1; i <= Ne; i++) {
		cout << "输入边的两个节点和权重： ";
		cin >> v1 >> v2 >> weight;
		cout << "finish" << endl;
		G[v1][v2] = weight;
		G[v2][v1] = weight;
	}
}

void floyd() {
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			if (i == j) {
				dist[i][j] = 0;
				path[i][j] = -1;
				continue;
			}
			dist[i][j]=G[i][j];
			path[i][j] = -1;
		}
	}
	for (int k = 1; k <= Nv; k++) {
		for (int i = 1; i <= Nv; i++) {
			for (int j = 1; j <= Nv; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}
void output() {
	stack<int>s;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			cout << i << "到" << j << "的最短距离是： " << dist[i][j] << "  ";
			cout << "最短路径是： ";
			int tmp = j;
			s.push(j);
			while (path[i][tmp]!=-1) {
				s.push(path[i][tmp]);
				tmp = path[i][tmp];
			}
			cout << i;
			while (!s.empty()) {
				cout << "->" << s.top();
				s.pop();
			}
			cout << endl;
		}
	}
}
int main() {
	build();
	floyd();
	output();
}
