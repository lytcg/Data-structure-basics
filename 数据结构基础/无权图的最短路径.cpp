#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int path[100];
int dist[100];
int G[100][100];
int Nv;//顶点数
int Ne;//边数

void build() {
	int v1, v2;
	//初始化节点
	cout << "输入节点数： \n";
	cin >> Nv;
	memset(G, 0, sizeof(G));
	//初始化路径和距离
	for (int i = 0; i <= Nv; i++) {
		path[i] = -1;
		dist[i] = -1;
	}
	//初始化边
	cout << "\n输入边数\n";
	cin >> Ne;
	cout << "\n输入边的两个节点（仅从前一节点到后一节点）\n";
	for (int i = 0; i < Ne; i++) {
	cin >> v1 >> v2;
	G[v1][v2] = 1;//有向图
	cout << "\nfinish\n";
	}
}
void unweightBFS(int v) {
	queue<int> q;
	q.push(v);
	int tmp;
	dist[v] = 0;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		for (int i = 1; i <= Nv; i++) {
			//如果i没被访问过且tmp与i联通
			if (dist[i] == -1 && G[tmp][i] != 0) {
				path[i] = tmp;//上一个节点作为i的路径
				dist[i] = dist[tmp] + 1;//是上一步距离的+1
				q.push(i);
			}
		}
	}
}
void getPath(int v) {
	for (int i = 1; i <= Nv; i++) {
		if (i == v) {
			continue;
		}
		cout << "到" << i << "的最短距离为" << dist[i];
		int tmp = i;
		//到达起始点前一直循环
		stack<int> s;
		while (path[tmp] != -1) {
			s.push(tmp);
			tmp = path[tmp];
		}
		//输出栈中的元素，得到路径
		cout << "其路径为： ";
		while (!s.empty()) {
			cout << "->" << s.top();
			s.pop();
		}
		cout << endl;
	}
}
int main() {
	build();
	unweightBFS(3);
	getPath(3);
}

