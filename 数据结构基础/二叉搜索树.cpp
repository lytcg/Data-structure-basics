#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct BinarySearchTree* BinTree;

struct BinarySearchTree {
	ElementType data;
	BinTree left;
	BinTree right;
};

BinTree Find(BinTree BT,ElementType E) {
	BinTree TBT = BT;
	while (TBT) {
		if (E < TBT->data)
			TBT = TBT->left;
		else if (E > TBT->data)
			TBT = TBT->right;
		else
			return TBT;
	}
	return NULL;
}

BinTree FindMax(BinTree BT) {
	BinTree TBT = BT;
	if (TBT == NULL)
		return NULL;
	while (TBT->right) {
		TBT = TBT->right;
	}
	return TBT;
}
BinTree FindMin(BinTree BT) {
	BinTree TBT = BT;
	if (TBT == NULL)
		return NULL;
	while (TBT->left) {
		TBT = TBT->left;
	}
	return TBT;
}

BinTree Insert(BinTree BT,ElementType E) {
	if (BT == NULL) {
		BT = new struct BinarySearchTree();
		BT->data = E;
		BT->left = BT->right = NULL;
	}
	else {
		if (E < BT->data)
			BT->left = Insert(BT->left, E);
		else if (E > BT->data)
			BT->right = Insert(BT->right, E);
	}
	return BT;
}

BinTree Delete(BinTree BT, ElementType E) {
	BinTree TBT;
	if (BT == NULL)
		cout << "NOT FOUND" << endl;
	else if (E < BT->data)
		Delete(BT->left, E);
	else if (E > BT->data)
		Delete(BT->right, E);
	else {
		if (BT->left != NULL && BT->right != NULL) {
			TBT = FindMin(BT->right);
			BT->data = TBT->data;
			BT->right = Delete(BT->right, TBT->data);
		}
		else {
			TBT = BT;
			if (BT->left != NULL) {
				BT = BT->left;
			}
			else if (BT->right != NULL) {
				BT = BT->right;
			}
			delete(TBT);
		}
	}
	return BT;
}
