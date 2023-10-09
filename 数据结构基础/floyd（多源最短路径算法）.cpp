#include<iostream>
#include<stack>
using namespace std;
#define Inf 1000000
int G[100][100];
int dist[100][100];//����
int path[100][100];//·��
int Nv, Ne;
/*����ͼ�����ߵ�Ȩ�����룬û�бߵ�Ȩ����ΪInf����ʼ������path��Ϊ-1
floyd�����⵽�ڽ���k,i,j����ѭ������� i-j�ľ����Ƿ����i-k-j�ľ��룬�������
�����ߵ�ֵ����ǰ��*/
/*�������ݣ�5  7
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
	cout << "����ڵ����� ";
	cin >> Nv;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = Inf;
		}
	}
	cout << "�������������ͼ���� ";
	cin >> Ne;
	for (int i = 1; i <= Ne; i++) {
		cout << "����ߵ������ڵ��Ȩ�أ� ";
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
			cout << i << "��" << j << "����̾����ǣ� " << dist[i][j] << "  ";
			cout << "���·���ǣ� ";
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
