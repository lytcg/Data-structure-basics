#include<iostream>
#include<stack>
using namespace std;
#define Inf 10000
int G[105][105];
int dist[105][105];
int path[105][105];
int Nv, Ne;
void build() {
	cin >> Nv >> Ne;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			G[i][j] = Inf;
		}
	}
	int v1, v2, weight;
	for (int i = 1; i <= Ne; i++) {
		cin >> v1 >> v2 >> weight;
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
			dist[i][j] = G[i][j];
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
int findMax(int v) {
	int max = 0;
	for (int i = 1; i <= Nv; i++) {
		if (i == v) {
			continue;
		}
		if (dist[v][i] > max) {
			max = dist[v][i];
		}
	}
	return max;
}
void findMinInMax() {
	int min = Inf;
	int animal;
	for (int i = 1; i <= Nv; i++) {
		int tmp = findMax(i);
		if (tmp == Inf) {
			cout << "0";
			return;
		}
		if (tmp < min) {
			min = tmp;
			animal = i;
		}
	}
	cout << animal << " " << min;
}
int main() {
	build();
	floyd();
	findMinInMax();
}
