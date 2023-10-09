#include<iostream>
using namespace std;
typedef struct Bintree* BinTree;
struct Bintree {
	int data;
	BinTree left, right;
};

BinTree Insert(BinTree BT, int E) {
	if (BT == NULL) {
		BT = new struct Bintree();
		BT->data = E;
		BT->left = BT->right = NULL;
	}
	else {
		if (E > BT->data) {
			BT->right=Insert(BT->right, E);
		}
		else if (E < BT->data) {
			BT->left=Insert(BT->left, E);
		}
	}
	return BT;
}

void Preordertraversal(BinTree BT, string& str) {
	if (BT != NULL) {
		Preordertraversal(BT->left, str);
		str += BT->data;
		Preordertraversal(BT->right, str);
	}

}

void Inordertraversal(BinTree BT, string& str) {
	if (BT != NULL) {
		str += BT->data;
		Inordertraversal(BT->left, str);
		Inordertraversal(BT->right, str);
	}
}

int main() {
	int N, L;
	cin >> N;
	while (N) {
		cin >> L;
		BinTree INIBT = NULL;
		string inistr1,inistr2;
		for (int i = 0; i < N; i++) {
			int E;
			cin >> E;
			INIBT=Insert(INIBT, E);
		}
		Preordertraversal(INIBT,inistr1);
		Inordertraversal(INIBT, inistr2);

		for (int i = 0; i < L; i++) {
			string str1, str2;
			BinTree BT= NULL;
			for (int j = 0; j < N; j++) {
				int E;
				cin >> E;
				BT=Insert(BT, E);
			}
			Preordertraversal(BT, str1);
			Inordertraversal(BT, str2);
			if (inistr1 == str1 && inistr2 == str2) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}

		}
		cin >> N;
	}


	return 0;
}
