#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct Node* NODE;
typedef struct Qnode* Queue;
struct Node {
	ElementType data;
	NODE next;
};

struct Qnode {
	NODE front;
	NODE tail;
};

Queue createQueue()
{
	Queue q;
	q = new struct Qnode();
	q->front = NULL;
	q->tail = NULL;
	return q;
}

int isEmpty(Queue q)
{
	if (q->front == NULL)
		return 1;
	return 0;
}

void addQ(Queue q,ElementType Ele)
{
	NODE node = new struct Node();
	node->data = Ele;
	node->next = NULL;
	if (q->front == NULL) {
		q->front = node;
		q->tail = node;
	}
	else {
		q->tail->next = node;
		q->tail = node;
	}
}

void deleteQ(Queue q)
{
	if (isEmpty(q)) {
		cout << "empty" << endl;
		return;
	}
	NODE tmp = q->front;
	if (q->front == q->tail) {
		q->front = NULL;
		q->tail = NULL;
	}
	else {
		q->front = q->front->next;
	}
	delete(tmp);
}

void showQueue(Queue q)
{
	if (isEmpty(q)) {
		cout << "empty" << endl;
		return;
	}
	NODE tmp = q->front;
	while (1) {
		cout << q->front->data << " ";
		q->front = q->front->next;
		if (q->front == NULL)
			break;
	}
	q->front = tmp;
	cout << endl;
}


int main()
{
	Queue q = createQueue();
	addQ(q, 0);
	addQ(q, 1);
	addQ(q, 2);
	addQ(q, 3);
	showQueue(q);
	deleteQ(q);
	showQueue(q);
	deleteQ(q);
	showQueue(q);
	deleteQ(q);
	showQueue(q);
	deleteQ(q);
	showQueue(q);
	system("pause");
	return 0;
}
