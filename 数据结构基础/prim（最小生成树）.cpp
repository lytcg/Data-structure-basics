#include<iostream>
#include<vector>
using namespace std;
#define Inf 100000
int G[105][105];
int parent[105];
int dist[105];
int Nv, Ne, sum=0;
vector<int>MST;
void build() {
	int v1, v2, weight;
	cout << "����ڵ����ͱ����� ";
	cin >> Nv >> Ne;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = 0;
		}
		dist[i] = Inf;
		parent[i] = -1;
	}
	for (int i = 0; i < Ne; i++) {
		cout << "����ڵ�������ߺ�Ȩ�أ� ";
		cin >> v1 >> v2 >> weight;
		G[v1][v2] = weight;
		G[v2][v1] = weight;
	}
}
void init(int v) {
	dist[v] = 0;
	MST.push_back(v);
	for (int i = 1; i <= Nv; i++) {
		if (G[i][v]) {
			dist[i] = G[i][v];
			parent[i] = v;
		}
	}
}
int findMin() {
	int min = Inf;
	int tmp = -1;
	for (int i = 1; i <= Nv; i++) {
		if (dist[i] != 0 && dist[i] < min) {
			min = dist[i];
			tmp = i;
		}
	}
	return tmp;
}
void prim(int s) {
	init(s);
	while (1) {
		int v = findMin();
		if (v == -1) {
			break;
		}
		sum += dist[v];
		dist[v] = 0;//�ŵ�MST�к���MST�ľ����Ϊ0
		MST.push_back(v);
		for (int i = 1; i <= Nv; i++) {
			if (G[i][v] && dist[i]) {//i��v�б�������δ��MST���� 
				if (G[i][v] < dist[i]) {
					dist[i] = G[i][v];
					parent[i] = v;
				}
			}
		}
	}
}
void output() {
	cout << "����¼˳��" << endl;
	for (int i = 0; i < Nv; i++)
		cout << MST[i] << " ";
	cout << "Ȩ�غ�Ϊ��" << sum << endl;
	cout << "��������" << endl;
	for (int i = 1; i <= Nv; i++)
		cout <<i<<"�ĸ��ڵ�Ϊ�� " << parent[i] <<endl;
}
int main() {
	build();
	prim(1);
	output();
	return 0;
}

