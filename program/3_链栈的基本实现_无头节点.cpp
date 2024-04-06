#include <iostream>

using namespace std;


// 不带头节点的链栈的实现方式
typedef int Elemtype;

typedef struct Linknode{
	Elemtype data;
	struct Linknode* next;
}ListackNode, *LiStack;	// 不带头节点的链栈的表头指针

// 初始化
bool InitLink(LiStack &s){
	s = NULL;
	return true;
}

// 判空
bool StackEmpty(LiStack &s){
	if(s==NULL)
		return true;
	return false;
}

bool push(LiStack &s, Elemtype x){
	// 一般链栈不需要判满，很难上溢
	ListackNode *node = (ListackNode*)malloc(sizeof(ListackNode));
	node->data = x;
	node->next = s;
	s = node;
	return true;
}

bool pop(LiStack &s, Elemtype &x){
	if(StackEmpty(s))
		return false;
	x = s->data;
	ListackNode *node = s;
	s = s->next;
	free(node);
	return true;
}

bool getTop(LiStack &s, Elemtype &x){
	if(StackEmpty(s))
		return false;
	x = s->data;
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
	InitLink(s);
	run(s);
	return 0;
}