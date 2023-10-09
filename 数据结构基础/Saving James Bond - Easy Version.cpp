#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
constexpr auto MAXSIZE = 105;
const double diameter = 15.0;

struct Node {
	int hor, ver;//横纵坐标
	bool visit;//是否被访问过
	bool save;//是否能直接上岸
	bool jump;//第一步能不能跳上去
};
int N, D;
bool isSafe;
Node G[MAXSIZE];
//计算两点距离
double getLen(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
//计算并判断该鳄鱼能否到岸边
bool ashore(int x, int y) {
	if (abs(x - 50) <= D || abs(x + 50) <= D || abs(y - 50) <= D || abs(y + 50) <= D) {
		return 1;
	}
	else {
		return 0;
	}
}
void getSave() {
	for (int i = 0; i < N; i++) {
		if (ashore(G[i].hor, G[i].ver)) {
			G[i].save = 1;
		}
		else {
			G[i].save = 0;
		}
	}
}
//确认哪些鳄鱼第一步可以跳上去
void getFirstJump() {
	for (int i = 0; i < N; i++) {
		if (getLen(0, 0, G[i].hor, G[i].ver) <= D + diameter / 2) {
			G[i].jump = 1;
		}
		else {
			G[i].jump = 0;
		}
	}
}
//判断第一步
void init() {
	cin >> N >> D;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		G[i].hor = x;
		G[i].ver = y;
		G[i].visit = 0;
	}
	getSave();
	getFirstJump();
}
void BFS(int v) {
	queue<Node> q;
	//第一只鳄鱼入队
	q.push(G[v]);
	G[v].visit = 1;

	Node tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp.save == 1) {
			isSafe = 1;
			return;
		}
		for (int i = 0; i < N; i++) {
			if (getLen(tmp.hor, tmp.ver, G[i].hor, G[i].ver) <= D && !G[i].visit) {
				q.push(G[i]);
				G[i].visit = 1;

			}
		}
	}
}
// 遍历所有第一步能跳到的鳄鱼
void listC() {
	for (int i = 0; i < N; i++) {
		if (G[i].jump == 1) {
			BFS(i);
		}
	}
	if (isSafe) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
int main() {
	init();
	listC();
}
