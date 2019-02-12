//头插法
#include <iostream>
using namespace std;

typedef int DataType;

typedef struct Node {
	DataType data;
	Node *next;
}Node, *PNode;

void init(PNode list) {
	list->data = 0;
	list->next = NULL;
}

void insert(PNode list, DataType data) {
	PNode p = new Node();
	p->data = data;
	p->next = list->next;
	list->next = p;
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

void output(PNode list) {
	PNode p = list -> next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

int mainList() {
	PNode list;
	list = new Node();
	init(list);
	insert(list, 1);
	insert(list, 2);
	insert(list, 3);
	insert(list, 4);
	output(list);
	deleteData(list, 3);
	output(list);
	delete list;
	return 0;
}
