#include<iostream>
using namespace std;
#define MAXSIZE 100000
typedef struct HeapStruct* maxHeap;
struct HeapStruct {
	int* elements;
	int size;
	int capacity;
};

maxHeap createMaxHeap(int maxsize) {
	maxHeap H = new struct HeapStruct();
	H->elements = new int[maxsize];
	H->capacity = maxsize;
	H->size = 0;
	H->elements[0] = MAXSIZE;
	return H;
}
void insertMaxHeap(maxHeap H,int num) {
	if (H->size == H->capacity) {
		cout << "Heap is Full" << endl;
		return;
	}
	H->size++;
	int i = H->size;
	for (; H->elements[i / 2] < num; i /= 2) {
		H->elements[i] = H->elements[i / 2];
	 }
	H->elements[i] = num;
	cout << "insert successful:" << num << endl; 
}
void deleteMax(maxHeap H) {
	int parent, child, tmp;
	if (H->size == 0) {
		cout << "EMPTY" << endl;
		return;
	}
	tmp = H->elements[H->size];//��ȡ�������һ��ֵ
	H->size--;
	for (parent = 1; parent * 2 <= H->size; parent = child) {//�ж�parent�����ӽڵ�
		child = parent * 2;
		if ((child != H->size) && (H->elements[child] < H->elements[child + 1])) {
			child++;//�ж�parent�Ƿ������ӽڵ㣬�����ӽڵ�Ĵ�С
		}
		if (H->elements[child] <= tmp) {
			break;
		}
		else {
			H->elements[parent] = H->elements[child];
		}
	}
	H->elements[parent] = tmp;
	cout << "delete successful" << endl;
	return;
}
void LevelOrderTraversal(maxHeap H) {
	cout << "��������� " << endl;
	for (int i = 1; i <= H->size; i++) {
		cout << H->elements[i] << " ";
	}
	cout << endl;
}

int main() {
	maxHeap H;
	int MaxSize = 100;
	H = createMaxHeap(MaxSize);
	insertMaxHeap(H, 55);
	insertMaxHeap(H, 66);
	insertMaxHeap(H, 44);
	insertMaxHeap(H, 33);
	insertMaxHeap(H, 11);
	insertMaxHeap(H, 22);
	insertMaxHeap(H, 88);
	insertMaxHeap(H, 99);
	LevelOrderTraversal(H);
}
