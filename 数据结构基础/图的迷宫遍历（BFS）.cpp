#include<iostream>
#include<queue>
int cnt = 0;
using namespace std;
typedef struct Node* coordinate;
struct Node {
	int hor, ver;//横纵坐标
};
bool isVisit[10][12];
int graph[10][12]= {    {1,1,1,0,1,1,1,0,1,1,1,0},
						{1,0,1,1,0,0,1,0,1,0,0,0},
						{1,0,0,0,1,0,0,0,1,0,1,1},
						{1,0,1,1,1,1,1,1,1,0,0,1},
						{0,0,1,0,0,1,0,1,1,1,1,0},
						{1,1,1,0,1,1,0,0,0,1,1,1},
						{1,1,0,1,1,1,1,0,0,1,0,0},
						{0,0,0,1,0,0,1,0,1,0,1,1},
						{0,1,1,0,1,1,1,0,1,0,1,0},
						{0,0,0,0,0,1,1,0,1,0,1,1} };

int x[] = {-1,-1,-1,0,1,1,1,0};
int y[] = {-1,0,1,1,1,0,-1,-1};

coordinate create(int x,int y) {
	coordinate tmp = new struct Node();
	tmp->hor = x;
	tmp->ver = y;
	return tmp;
}
void BFS() {
	queue<coordinate> q;
	q.push(create(0,0));
	isVisit[0][0] = 1;
	while (!q.empty()) {
		coordinate nowNode = q.front();
		int nowX = nowNode->hor;
		int nowY = nowNode->ver;

		//test
		cout << "(" << nowX << ',' << nowY << ')' << " ";
		cout << graph[nowX][nowY]<<" ";
		cnt++;


		q.pop();
		for (int i = 0; i < 8; i++) {
			//cout << "for time" << endl;
			int newX = nowX + x[i];
			int newY = nowY + y[i];
			//cout << newX << " " << newY << endl;
			//如果在范围内
			if ((newX >=0 && newX < 10) && (newY >= 0 && newY < 12) && graph[newX][newY] != 0 && isVisit[newX][newY] ==false) {
				isVisit[newX][newY] = 1;
				q.push(create(newX, newY));
				//cout << "if time" << endl;
			}
		}
	}

}

int main() {
	int trueCnt = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			if (graph[i][j] == 1) {
				trueCnt++;
			}
		}
	}
	BFS();
	if (cnt == trueCnt) {
		cout <<endl<< "successful";
	}
	else {
		cout << endl << "false";
	}
	
}

