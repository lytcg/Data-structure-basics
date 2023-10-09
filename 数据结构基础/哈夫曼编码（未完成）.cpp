#include<iostream>
#define MaxSize 1000
#define MinData -1000 
int A[] = { 13,1,45,7,20,4,19,13,40,33,38 };  // Ԥ�ȶ����һ��Ȩֵ 
int A_length = 11;  // �����䳤�� 
typedef struct TreeNode* HuffmanTree;
typedef struct HeapStruct* MinHeap;
using namespace std;
struct HeapStruct {
	int size;
	int capacity;
	HuffmanTree* data;
};
struct TreeNode {
	int weight;
	HuffmanTree Left;
	HuffmanTree Right;
};
MinHeap createMinheap() {
	MinHeap H;
	HuffmanTree Huff;
	H = new struct HeapStruct();
	H->data = new HuffmanTree[MaxSize+1];
	H->capacity = MaxSize;
	H->size = 0;
	Huff = createHuffmanTree();
	Huff->weight = MinData;//������С���ڱ�
	H->data[0] = Huff;
	return H;
}

HuffmanTree createHuffmanTree() {
	HuffmanTree Huff;
	Huff = new struct TreeNode();
	Huff->weight = 0;
	Huff->Left = NULL;
	Huff->Right = NULL;
	return Huff;
}

void adjustMinHeap(MinHeap H,int i) {
	if (H->size == 0) {
		cout << "EMPTY" << endl;
		return;
	}
	int tmp = H->data[i]->weight;
	int parent, child;
	for (parent = i; parent * 2 <= H->size; parent = child) {
		child = 2 * parent;
		if (child != H->size && (H->data[child]->weight > H->data[child + 1]->weight)) {
			child++;
		}
		if (H->data[child]->weight > tmp) {
			break;
		}
		else {
			H->data[parent]->weight = H->data[child]->weight;
		}
		H->data[parent]->weight = tmp;
	}
}
void BuildMinheap(MinHeap H) {
	HuffmanTree Huff;
	for (int i = 0; i < A_length; i++) {
		Huff = createHuffmanTree();
		Huff->weight = A[i];
		H->size++;
		H->data[H->size] = Huff;
	}
	for (int i = H->size / 2; i > 0; i--) {
		adjustMinHeap(H, i);
	}
}

HuffmanTree DeleteMinheap(MinHeap H) {
	int parent, child;
	HuffmanTree T = H->data[1];  // ȡ�������Ĺ������� 
	HuffmanTree tmp = H->data[H->size--]; // ȡ�����һ��������������Ȩֵ 
	for (parent = 1; parent * 2 <= H->size; parent = child) {
		child = 2 * parent;
		if ((child != H->size) && (H->data[child + 1]->weight < H->data[child]->weight))
			child++;
		if (H->data[child]->weight >= tmp->weight)
			break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = tmp;
	// ����һ�� HuffmanTree ��㣬���ϸղ�ȡ������Ȩֵ�����ظý�� 
	return T;
}
