#include<iostream>
using namespace std;
typedef struct Node* MinHeap;
struct Node {
	int* element;
	int size;
};
void insert(int N, MinHeap H) {
	H->size++;
	int i = H->size;
	for (; N < H->element[i/2]; i /= 2) {
		H->element[i] = H->element[i / 2];
	}
	H->element[i] = N;
}

void forEach(int mk, MinHeap H) {
	for (; mk > 1; mk /= 2) {
		cout << H->element[mk] <<" ";
	}
	cout << H->element[1] << endl;
}

//最小堆，插入，遍历
int main() {
	
	int M, N;
	cin >> N >> M;
	MinHeap H = new struct Node();
	H->element = new int[N + 1];
	//建堆
	H->element[0] = -10001;
	H->size = 0;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		insert(num, H);
	}
	for (int i = 1; i <= H->size; i++) {
		cout << H->element[i] << " ";
	}
	int mk;
	for (int i = 0; i < M; i++) {
		cin >> mk;
		forEach(mk, H);
	}
}
