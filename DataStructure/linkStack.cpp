#include <stdio.h>
#include <stdlib.h>

typedef int ELementType;

typedef struct Node {
	ELementType data;
	struct Node* next;
}LNode, *PNode;

typedef struct Stack {
	PNode PTop;
	PNode PBottom;
}Stack, *PStack;

void init(PStack s) {
	s = new Stack();
	PNode pNew = new Node();
	if (s == NULL || pNew == NULL) {
		printf("新节点空间分配失败!");
		exit(-1);
	}
	s->PTop = pNew;
	s->PBottom = pNew;
	pNew->next = NULL;
	printf("栈创建成功!\n");
}

int push(PStack s, ELementType n) {
	PNode p = new Node();
	if (p == NULL) {
		printf("内存空间分配失败!\n");
		exit(-1);
	}
	p->data = n;
	p->next = s -> PTop;
	s->PTop = p;
	printf("插入成功!\n");
	return 0;
}

int pop(PStack s, ELementType &n) {
	if (s->PBottom == s->PTop) {
		printf("出栈失败，栈为空!\n");
		return 0;
	}
	PNode p = s->PTop;
	n = p->data;
	s->PTop = s->PTop->next;
	delete p;
	return 0;
}

int getTop(PStack s) {
	if (s->PBottom == s->PTop) {
		printf("出栈失败，栈为空!\n");
		return 0;
	}
	return s->PTop->data;
}

bool isEmpty(PStack s) {
	if (s->PBottom == s->PTop) {
		printf("栈为空\n");
		return true;
	}
	return false;
}

int main() {
	PStack stack;
	stack = new Stack();
	init(stack);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);

	int n = 0;
	pop(stack, n);
	printf("%d\n", n);
	n = getTop(stack);
	printf("%d\n", n);

	delete stack;
	return 0;
}

