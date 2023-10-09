#include<iostream>
using namespace std;
typedef struct AVLnode* AVLTree;
struct AVLnode {
	int data;
	AVLTree left, right;
	int height;
};

int getTreeHeight(AVLTree A) {
	if (A == NULL)
		return -1;
	else
		return A->height;
}

AVLTree RRrotation(AVLTree A) {
	AVLTree B = A->right;
	A->right = B->left;
	B->left = A;
	A->height = max(getTreeHeight(A->left), getTreeHeight(A->right))+1;
	B->height = max(getTreeHeight(B->right), A->height)+1;
	return B;
}

AVLTree LLrotation(AVLTree A) {
	AVLTree B = A->left;
	A->left = B->right;
	B->right = A;
	A->height = max(getTreeHeight(A->left), getTreeHeight(A->right))+1;
	B->height = max(getTreeHeight(B->left), A->height)+1;
	return B;
}

AVLTree LRrotation(AVLTree A) {
	A->left = RRrotation(A->left);
	A = LLrotation(A);
	return A;
}

AVLTree RLrotation(AVLTree A) {
	A->right = LLrotation(A->right);
	A = RRrotation(A);
	return A;
}

AVLTree insertTreeNode(AVLTree A,int tmpdata) {
	if (A == NULL) {
		A = new struct AVLnode();
		A->data = tmpdata;
		A->left = NULL;
		A->right = NULL;
		A->height = 0;
	}
	else {
		if (tmpdata < A->data) {//插入到左子树中
			A->left = insertTreeNode(A->left, tmpdata);
			if (getTreeHeight(A->left) - getTreeHeight(A->right) == 2) {//左子树过高，需要LL&&LR调平衡
				if (tmpdata < A->left->data) {//LL
					A = LLrotation(A);
				}
				else if (tmpdata > A->left->data) {//LR
					A = LRrotation(A);
				}
			}
		}
		else if (tmpdata > A->data) {//插入到右子树
			A->right = insertTreeNode(A->right, tmpdata);
			if (getTreeHeight(A->right) - getTreeHeight(A->left) == 2) {
				if (tmpdata > A->right->data) {//RR
					A = RRrotation(A);
				}
				else if (tmpdata < A->right->data) {//RL
					A = RLrotation(A);
				}
			}
		}
	}
	A->height = max(getTreeHeight(A->left), getTreeHeight(A->right)) + 1;
	return A;
}
int main() {
	AVLTree T = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		T = insertTreeNode(T, tmp);
	}
	cout << T->data;
	return 0;
}

