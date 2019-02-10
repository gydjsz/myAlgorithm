#include <stdio.h>
#include <cstring>
#define MAXSIZE 100
#define success 1
#define fail 0

typedef int ElementType;

struct Stack {
	int top;
	ElementType a[MAXSIZE];
};

void init(Stack &s) {
	s.top = -1;
	memset(s.a, 0, sizeof(s.a));
}

int push(Stack &s, ElementType n) {
	if (s.top == MAXSIZE - 1) {
		printf("栈已满，插入失败");
		return fail;
	}
	s.a[++s.top] = n;
	return success;
}

int pop(Stack &s, ElementType &n) {
	if (s.top == -1) {
		printf("栈为空，删除失败");
		return fail;
	}
	n = s.a[s.top--];
	return success;
}

bool isEmpty(Stack s) {
	if (s.top == -1)
		return true;
	return false;
}

ElementType getTop(Stack s) {
	if (s.top == -1) {
		printf("栈为");
		return fail;
	}
	return s.a[s.top];

}

int main() {
	Stack stack;
	init(stack);
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);

	int n;
	pop(stack, n);
	printf("%d\n", n);
	n = getTop(stack);
	printf("%d\n", n);
	return 0;
}
