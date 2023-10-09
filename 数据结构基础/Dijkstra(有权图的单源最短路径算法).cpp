#include<iostream>
using namespace std;
#define Inf 10000000
int G[100][100];
int dist[100];//����
int path[100];//·��
int collect[100];//����¼����
int Nv;//����
int Ne;//��

void build() {
	int v1, v2;
	int	weight;
	cout << "���붥������ ";
	cin >> Nv;
	for (int i = 1; i <= Nv; i++) {
		//��ʼ��ͼ
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = 0;
		}
		//��ʼ��·�� 
		path[i] = -1;
		//��ʼ������
		dist[i] = Inf;
		//��ʼ����¼���
		collect[i] = 0;
	}
	dist[0] = Inf;
	//��ʼ����
	cout << "��������� ";
	cin >> Ne;
	for (int i = 0; i < Ne; i++) {
		cout << "����ߵ������ڵ��Ȩ��: ";
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
	//����δ��¼�ڵ���dist��С��
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
			//v=0,���нڵ�����¼
			break;
		}
		collect[v] = 1;
		for (int i = 1; i <= Nv; i++) {
			//���δ����¼
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
		cout <<" ���ڵ�"<<i<<"�ľ���" << dist[i] << endl;
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
