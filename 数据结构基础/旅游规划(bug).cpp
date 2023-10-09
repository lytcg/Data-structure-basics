#include<iostream>
using namespace std;
#define Inf 10000
struct Node {
	int weight;
	int money;
};
Node G[505][505];
int dist[505];
int cost[505];
int collect[505];
int Nv, Ne;
int S, D;
void build() {
	int v1, v2, weight, money;
	cin >> Nv >> Ne >> S >> D;
	for (int i = 1; i <= Nv; i++) {
		for (int j = 1; j <= Nv; j++) {
			G[i][j].money = 0;
			G[i][j].weight = 0;
		}
		dist[i] = Inf;
		cost[i] = Inf;
	}
	dist[0] = Inf;
	for (int i = 1; i <= Ne; i++) {
		cin >> v1 >> v2 >> weight >> money;
		G[v1][v2].money = money;
		G[v2][v1].money = money;
		G[v1][v2].weight = weight;
		G[v2][v1].weight = weight;
	}
}
void create() {
	dist[S] = 0;
	cost[S] = 0;
	collect[S] = 1;
	for (int i = 1; i <= Nv; i++) {
		if (G[i][S].weight) {
			dist[i] = G[i][S].weight;
			cost[i] = G[i][S].money;
		}
	}
}
int findMin() {
	int min = 0;
	for (int i = 0; i <= Nv; i++) {
		if (i != S && !collect[i] && dist[i] < dist[min]) {
			min = i;
		}
	}
	return min;
}
void dijkstra() {
	create();
	while (1) {
		int v = findMin();
		if (v == 0) {
			break;
		}
		collect[v] = 1;
		for (int i = 1; i <= Nv; i++) {
			if (!collect[i] && G[v][i].weight) {
				if (dist[i] > dist[v] + G[v][i].weight) {
					dist[i] = dist[v] + G[v][i].weight;
					cost[i] = cost[v] + G[v][i].money;
				}
				else if (dist[i] == dist[v] + G[v][i].weight && cost[i] > cost[v] + G[v][i].money) {
					cost[i] = cost[v] + G[v][i].money;
				}
			}
		}
	}
}
int main() {
	build();
	dijkstra();
	cout << dist[D] << " " << cost[D];
}
