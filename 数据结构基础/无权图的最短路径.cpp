#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int path[100];
int dist[100];
int G[100][100];
int Nv;//������
int Ne;//����

void build() {
	int v1, v2;
	//��ʼ���ڵ�
	cout << "����ڵ����� \n";
	cin >> Nv;
	memset(G, 0, sizeof(G));
	//��ʼ��·���;���
	for (int i = 0; i <= Nv; i++) {
		path[i] = -1;
		dist[i] = -1;
	}
	//��ʼ����
	cout << "\n�������\n";
	cin >> Ne;
	cout << "\n����ߵ������ڵ㣨����ǰһ�ڵ㵽��һ�ڵ㣩\n";
	for (int i = 0; i < Ne; i++) {
	cin >> v1 >> v2;
	G[v1][v2] = 1;//����ͼ
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
			//���iû�����ʹ���tmp��i��ͨ
			if (dist[i] == -1 && G[tmp][i] != 0) {
				path[i] = tmp;//��һ���ڵ���Ϊi��·��
				dist[i] = dist[tmp] + 1;//����һ�������+1
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
		cout << "��" << i << "����̾���Ϊ" << dist[i];
		int tmp = i;
		//������ʼ��ǰһֱѭ��
		stack<int> s;
		while (path[tmp] != -1) {
			s.push(tmp);
			tmp = path[tmp];
		}
		//���ջ�е�Ԫ�أ��õ�·��
		cout << "��·��Ϊ�� ";
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

