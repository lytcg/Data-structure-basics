#include<iostream>
#include<queue>
using namespace std;
typedef int ElementType;
typedef struct TreeNode* BinTree;
struct TreeNode {
	ElementType data;
	BinTree left;
	BinTree right;
};

BinTree Insert(ElementType data) {
	BinTree BT = new struct TreeNode();
	BT->data = data;
	BT->left = NULL;
	BT->right = NULL;
	return BT;
}

BinTree createBT() {
	BinTree BT;
	BT = new struct TreeNode();
	BT->data = 1;
	BT->left = Insert(2);
	BT->right = Insert(3);
	BT->left->left = Insert(4);
	BT->left->right = Insert(6);
	BT->left->right->left = Insert(5);
	BT->right->left = Insert(7);
	BT->right->right = Insert(9);
	BT->right->left->right = Insert(8);
	return BT;
}

void PreOrderTraversal(BinTree BT) {
	if (BT) {
		cout << BT->data << " ";
		PreOrderTraversal(BT->left);
		PreOrderTraversal(BT->right);
	}
}

void InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->left);
		cout << BT->data << " ";
		InOrderTraversal(BT->right);
	}
}

void PostOrderTraversal(BinTree BT) {
	if (BT) {
		PostOrderTraversal(BT->left);
		PostOrderTraversal(BT->right);
		cout << BT->data << " ";
	}
}

void LevelOrderTraversal(BinTree BT) {
	queue<BinTree> q;
	BinTree TBT;
	q.push(BT);
	if (!BT)
		return;
	while (!q.empty()) {
		TBT = q.front();
		q.pop();
		cout << TBT->data << " ";
		if(TBT->left)
			q.push(TBT->left);
		if(TBT->right)
			q.push(TBT->right);
	}
}

void PrintLeaves(BinTree BT) {
	if (BT) {
		if (BT->left == NULL && BT->right == NULL)
			cout << BT->data << " ";
		if (BT->left)
			PrintLeaves(BT->left);
		if (BT->right)
			PrintLeaves(BT->right);
	}
}

int GetHeight(BinTree BT) {
	int lh, rh;
	if (BT) {
		lh = GetHeight(BT->left);
		rh = GetHeight(BT->right);
		return max(lh, rh) + 1;
	}
	else return 0;

}

int main() {
	BinTree BT = createBT();
	LevelOrderTraversal(BT);
	cout << endl;
	cout << "H: " << GetHeight(BT);
	return 0;
}

