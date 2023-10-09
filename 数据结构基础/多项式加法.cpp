#include<iostream>
using namespace std;
typedef struct PolyNode* PNode;
struct PolyNode {
	int coef;
	int expon;
	PNode next;
};

void Attach(int coef, int expon, PNode* tail)
{
	PNode p;
	p = new struct PolyNode();
	p->coef = coef;
	p->expon = expon;
	p->next = NULL;
	(*tail)->next = p;
	*tail = p;
}

int Compare(int a, int b)
{
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}

PNode addPoly(PNode p1, PNode p2) {
	PNode front, tail, tmp;
	front= new struct PolyNode();
	tail = front;
	while (p1 && p2) {
		switch (Compare(p1->expon, p2->expon)) {
		case 1:
			Attach(p1->coef, p1->expon, &tail);
			p1 = p1->next;
			break;
		case -1:
			Attach(p2->coef, p2->expon, &tail);
			p2 = p2->next;
			break;
		case 0:
			if (p1->coef + p2->coef != 0)
				Attach(p1->coef + p2->coef, p1->expon, &tail);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	for (; p1; p1 = p1->next)
		Attach(p1->coef, p1->expon, &tail);
	for (; p2; p2 = p2->next)
		Attach(p2->coef, p2->expon, &tail);
	tmp = front;
	front = front->next;
	delete(tmp);
	return front;
}
