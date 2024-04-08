#include <iostream>

using namespace std;
typedef int Elemtype;
// 带头节点的链栈基本实现
typedef struct Linknode {
	Elemtype data;
	Linknode* next;
}LiStackNode, *LiStack;

// 初始化
bool InitStack(LiStack &s) {
	s = (LiStackNode*)malloc(sizeof(LiStackNode));
	s->next = NULL;
	return true;
}

// 判空
bool StackEmpty(LiStack &s){
	if(s->next == NULL)
		return true;
	return false;
}

// 入栈
bool push(LiStack &s, Elemtype x){
	LiStackNode* node = (LiStackNode*)malloc(sizeof(LiStackNode));
	node->data = x;
	node->next = s->next;
	s->next = node;
	return true;
}

// 出栈
bool pop(LiStack &s, Elemtype &x){
	if(StackEmpty(s))
		return false;
	LiStackNode* node = (LiStackNode*)malloc(sizeof(LiStackNode));
	x = s->next->data;
	node = s->next;
	s->next = s->next->next;
	free(node);
	return true;
}

// 取栈顶
bool getTop(LiStack &s, Elemtype &x){
	if(StackEmpty(s))
		return false;
	x = s->next->data;
	return true;
}

// 一个例子，王道408，数据结构69页16题
void run(LiStack &s){
	Elemtype x;
	push(s, 1);
	pop(s, x);
	cout << x;
	push(s, 2);
	push(s, 3);
	pop(s, x);
	cout << x;
	push(s, 4);
	pop(s, x);
	cout << x;
	pop(s, x);
	cout << x;
}

int main(int argc, char *argv[]) {
	LiStack s;
	InitStack(s);
	run(s);
	return 0;
}