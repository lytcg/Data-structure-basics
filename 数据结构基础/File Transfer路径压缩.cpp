#include<iostream>
using namespace std;

int findRoot(int SET[], int x) {//路径压缩
	if (SET[x] < 0) {
		return x;
	}
	else {
		SET[x] = findRoot(SET, SET[x]);
		return SET[x];
	}
}
void connect(int SET[]) {
	int x1, x2;
	cin >> x1 >> x2;
	int root1 = findRoot(SET, x1-1);
	int root2 = findRoot(SET, x2-1);
	//并
	if (SET[root1] < SET[root2]) {
		SET[root1] += SET[root2];
		SET[root2] = root1;
	}
	else {
		SET[root2] += SET[root1]; 
		SET[root1] = root2;
	}
}
void check(int SET[]) {
	int x1, x2;
	cin >> x1 >> x2;
	if (findRoot(SET,x1-1)==findRoot(SET,x2-1)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}
void finalCheck(int SET[],int N) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (SET[i] < 0) {
			cnt++;
		}
	}
	if (cnt == 1) {
		cout << "The network is connected.";
	}
	else {
		cout << "There are " << cnt << " components.";
	}
}
int main() {
	int SET[10005];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		SET[i] = -1;
	}
	char ch;
	while (1) {
		getchar();//接收每行最后的回车
		cin >> ch;
		if (ch == 'I') {
			connect(SET);
		}
		else if (ch == 'C') {
			check(SET);
		}
		else if (ch == 'S') {
			finalCheck(SET,N);
		}

		if (ch == 'S')
			break;
	}
	return 0;
}
