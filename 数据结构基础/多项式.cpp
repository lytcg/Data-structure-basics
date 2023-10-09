#include<iostream>
using namespace std;
typedef struct PolyNode* PNode;
struct PolyNode {
	int coef;
	int expon;
	PNode next;
};

int Compare(PNode p1, PNode p2) {
	if (p1->expon > p2->expon)
		return 1;
	else if (p1->expon == p2->expon)
		return 0;
	else
		return -1;
}

void Attach(int coef, int expon, PNode* tail) {
	PNode p = new struct PolyNode();
	p->coef = coef;
	p->expon = expon;
	p->next = NULL;
	(*tail)->next = p;
	*tail = p;
}

PNode Read() {
	int cnt;
	cin >> cnt;
	PNode front = new struct PolyNode();
	PNode tail = front;
	for (int i = 0; i < cnt; i++) {
		int coef, expon;
		cin >> coef >> expon;
		if (coef == 0 && expon == 0)
			break;
		Attach(coef, expon, &tail);
	}
	PNode tmp = front->next;
	delete(front);
	return tmp;
}

PNode AddPNode(PNode p1, PNode p2) {
	PNode tp1 = p1, tp2 = p2;
	PNode front = new struct PolyNode();
	PNode tail = front;
	while (tp1 && tp2) {
		switch (Compare(tp1, tp2)) {
		case 1:
			Attach(tp1->coef, tp1->expon, &tail);
			tp1 = tp1->next;
			break;
		case -1:
			Attach(tp2->coef, tp2->expon, &tail);
			tp2 = tp2->next;
			break;
		case 0:
			if (tp1->coef + tp2->coef != 0)
				Attach(tp1->coef + tp2->coef, tp1->expon, &tail);
			tp1 = tp1->next;
			tp2 = tp2->next;
		}
	}
	for (; tp1; tp1 = tp1->next)
		Attach(tp1->coef, tp1->expon, &tail);
	for (; tp2; tp2 = tp2->next)
		Attach(tp2->coef, tp2->expon, &tail);
	PNode tmp = front;
	front = front->next;
	delete(tmp);
	return front;
}

PNode MulPNode(PNode p1, PNode p2) {
	if (!p1 || !p2)
		return NULL;
	PNode tp1 = p1, tp2 = p2, front = new struct PolyNode(), tmp = new struct PolyNode();
	tp1 = tp1->next;
	for (; tp1; tp1 = tp1->next)
		for (tp2 = p2; tp2; tp2 = tp2->next) {//tp2必须被初始化为p2 
			tmp->coef = tp1->coef * tp2->coef;
			tmp->expon = tp1->expon + tp2->expon;
			tmp->next = NULL;
			PNode tmp2 = front;
			front = AddPNode(front, tmp);
			delete(tmp2);
		}
	return front;
}

void PrintPNode(PNode p) {
	PNode tp = p;
	int flag = 1;
	for (; tp; tp = tp->next) {
		if (!flag && tp->coef)
			cout << " ";
		if (tp->coef)
			cout << tp->coef << " " << tp->expon;
		flag = 0;
	}
	if (flag) {
		cout << "0 0" << endl;
		return;
	}
	cout << endl;

}

int main() {
	PNode p1, p2, add, mul;
	p1 = Read();
	p2 = Read();
	add = AddPNode(p1, p2);
	mul = MulPNode(p1, p2);
	PrintPNode(mul);
	PrintPNode(add);
	return 0;
}
