//尾插法
#include <iostream>
using namespace std;

typedef int DataType;

typedef struct Node {
	DataType data;
	Node *next, *tail;
}Node, *PNode;

void init(PNode list) {
	list->data = 0;
	list->next = NULL;
	list->tail = list;
}

void insert(PNode list, DataType data) {
	PNode p = new Node();
	p->data = data;
	p->next = NULL;
	list->tail->next = p;
	list->tail = p;
}

void output(PNode list) {
	PNode p = list->next;
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int deleteData(PNode list, DataType data) {
	PNode p = list->next, q = list;
	while (p) {
		if (p->data == data) {
			q->next = p->next;
			delete p;
			return 0;
		}
		q = p;
		p = p->next;
	}
	return 0;
}
int main() {
	PNode list = new Node();
	init(list);
	insert(list, 1);
	insert(list, 2);
	insert(list, 3);
	insert(list, 4);
	output(list);

	deleteData(list, 4);
	output(list);

	return 0;
}
