#include<iostream>
using namespace std;
#define MAX_NUM 100
int graph[MAX_NUM][MAX_NUM];
int nv, ne;

void printGraph() {
	for (int i = 0; i < MAX_NUM; i++) {
		for (int j = 0; j < MAX_NUM; j++) {
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}

void iniGraph() {
	memset(graph, 0, sizeof(graph));
	//²åÈëneÌõ±ß
	int ne;
	cin >> ne;
	int row, column, weight;
	for (int i = 0; i < ne; i++) {
		cin >> row >> column >> weight;
		graph[row][column] = weight;
		graph[column][row] = weight;
	}
}
int main() {
	iniGraph();
	printGraph();
	return 0;
}
