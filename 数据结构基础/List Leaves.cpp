#include<iostream>
#include<queue>
using namespace std;
//typedef struct Bintree BinTree;
struct BinTree {
	int data;
	int left;
	int right;
};
BinTree BT[11];

void Print(int root) {

	queue<BinTree> Q;
	Q.push(BT[root]);
	BinTree TBT;
	int pos;
	while (!Q.empty()) {
		TBT = Q.front();
		Q.pop();
		if (TBT.left == -1 && TBT.right == -1) {
			cout << TBT.data;
			if (!Q.empty()) {
				cout << " ";
			}
		}
		else {
			if (TBT.left != -1) {
				Q.push(BT[TBT.left]);
			}
			if (TBT.right != -1) {
				Q.push(BT[TBT.right]);
			}
		}
	}


}

int main() {

	int N;
	cin >> N;
	if (N == 0)
		return 0;
	char left, right,root=0;
	for (int i = 0; i < N; i++) {
		BT[i].data = i;
		cin >> left >> right;
		if (left != '-') {
			root -= left-'0';
			BT[i].left = left-'0';
		}
		else {
			BT[i].left = -1;
		}
		if (right != '-') {
			root -= right-'0';
			BT[i].right = right-'0';
		}
		else {
			BT[i].right = -1;
		}
		root += i;
	}

	Print(root);


	return 0;
}
