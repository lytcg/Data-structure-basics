#include<iostream>
using namespace std;
typedef struct TreeNode Tree;
struct TreeNode {
	char data;
	int left;
	int right;
}T1[10],T2[10];

int createTree(Tree T[]) {
	int N;
	char left, right;
	cin >> N;
	if (N == 0)
		return -1;
	int root = 0;
	for (int i = 0; i < N; i++) {
		cin >> T[i].data >>left >> right;
		if (left == '-') {
			T[i].left = -1;
		}
		else {
			T[i].left = left - '0';
			root -= T[i].left;
		}
		if (right == '-') {
			T[i].right = -1;
		}
		else {
			T[i].right = right - '0';
			root -= T[i].right;
		}
		root += i;
	}
	return root;
}

bool Judge(int r1, int r2) {
	if (r1 == -1 && r2 == -1)
		return 1;
	if ((r1 == -1 && r2 != -1) || (r1 != -1 && r2 == -1))
		return 0;
	if (T1[r1].data != T2[r2].data)
		return 0;
	//else//不是||的关系
	//	return (Judge(T1[r1].left,T2[r2].left) && Judge(T1[r1].right,T2[r2].right)) || (Judge(T1[r1].left,T2[r2].right)&&Judge(T1[r1].right,T2[r2].left));
	if ((T1[r1].left != -1 && T2[r2].left!= -1) && (T1[T1[r1].left].data == T2[T2[r2].left].data))
		return Judge(T1[r1].left, T2[r2].left) && Judge(T1[r1].right, T2[r2].right);
	else
		return Judge(T1[r1].left, T2[r2].right) && Judge(T1[r1].right, T2[r2].left);
}

int main() {
	int r1, r2;
	r1 = createTree(T1);
	r2 = createTree(T2);
	if (Judge(r1, r2))
		cout << "Yes";
	else
		cout << "No";



	return 0;
}
