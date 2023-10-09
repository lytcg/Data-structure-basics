#include<iostream>
using namespace std;
typedef int ElementType;
typedef struct SNode* Stack;

struct SNode {
	ElementType data;
	Stack next;
};

Stack createStack()
{
	Stack s;
	s = new struct SNode();
	s->next = NULL;
	return s;
}

int isEmpty(Stack s)//0 is empty
{
	if (s->next == NULL)
	{
		return 1;
	}
	return 0;
}

void mypush(Stack s,ElementType ele)
{
	Stack tmp;
	tmp = new struct SNode();
	tmp->data = ele;
	tmp->next = s->next;
	s->next = tmp;
}

void mypop(Stack s)
{

	if (isEmpty(s))
	{
		cout << "empty" << endl;
		return;
	}
	Stack tmp = s->next;
	s->next = tmp->next;
	delete(tmp);
}

void showstack(Stack s)
{
	while (s->next != NULL)
	{
		cout << s->next->data << " ";
		s = s->next;
	}
	cout << endl;
}

int main()
{
	Stack s = createStack();

	mypush(s, 0);
	mypush(s, 1);
	mypush(s, 2);
	showstack(s);
	mypop(s);
	showstack(s);
	mypop(s);
	showstack(s);
	mypop(s);
	showstack(s);
	return 0;
}
