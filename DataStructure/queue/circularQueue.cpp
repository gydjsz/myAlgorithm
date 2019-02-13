#include <iostream>
using namespace std;

typedef int DataType;

typedef struct Node{
	DataType data;
	Node *next;
}Node, *Queue;

typedef struct Link{
	Queue front;
	Queue rear;
}*LinkQueue;

void init(LinkQueue queue){
	queue -> front = queue -> rear = new Node();
	if(queue -> front == NULL){
		cout << "内存空间分配失败" << endl;
		exit(-1);
	}
}

void pushQueue(LinkQueue queue, DataType data){
	Queue q = new Node();
	if(q == NULL)
		exit(-1);
	q -> data = data;
	queue -> rear -> next = q;
	q -> next = queue -> front;
	queue -> rear = q;
}

bool isEmpty(LinkQueue queue){
	return queue -> front == queue -> rear;
}

int popQueue(LinkQueue queue){
	if(isEmpty(queue)){
		cout << "队列为空，出队失败!" << endl;
		return 0;
	}
	Queue q = queue -> front -> next;
	queue -> front -> next = q -> next;
	if(queue -> rear == q)   //如果没有这个，那么当队列为空时，rear是空指针
		queue -> rear = queue -> front = NULL;
	delete q;
}

void travelQueue(LinkQueue queue){
	Queue q = queue -> front -> next;
	while(q != queue -> front){
		cout << q -> data << " ";
		q = q -> next;
	}
	cout << endl;
}

int main(){
	LinkQueue queue = new Link();
	init(queue);
	pushQueue(queue, 1);
	pushQueue(queue, 2);
	pushQueue(queue, 3);
	travelQueue(queue);

	popQueue(queue);
	popQueue(queue);
	popQueue(queue);

	travelQueue(queue);
	delete queue;
	return 0;
}
