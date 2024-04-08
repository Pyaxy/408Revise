#include <iostream>
// 不带头节点的链队实现
using namespace std;
typedef int ELemtype;
// 节点定义
typedef struct LiQueueNode{
	ELemtype data;
	struct LiQueueNode* next;
} LinkNode;

// 队列定义
typedef struct{
	LinkNode *front, *rear;
} LiQueue;

// 初始化 首尾节点都为空
bool Init(LiQueue &q){
	q.front = NULL;
	q.rear = NULL;
	return true;
}

// 判空
bool QueueEmpty(LiQueue &q){
	return q.front == NULL && q.rear == NULL;
}

// 入队
bool EnQueue(LiQueue &q, ELemtype x){
	// 新建节点
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	node->data = x;
	node->next = NULL;
	// 如果是第一次入队，首尾指针都指向第一个元素
	if(q.front == NULL)
		q.front = q.rear = node;
	else{
		// 否则在尾部插入
		q.rear->next = node;
		q.rear = node;
	};
	return true;
}

// 出队
bool DeQueue(LiQueue &q, ELemtype &x){
	// 判空
	if(QueueEmpty(q))
		return false;
	// 标记第一个节点
	LinkNode* node = q.front;
	x = node->data;
	// 如果是最后一个节点，则出队后为空
	if(node == q.rear){
		q.front = NULL;
		q.rear = NULL;
	}
	else
	//否则从头部删除
		q.front = node->next;
	// 释放空间
	free(node);
	return true;
}

void run(LiQueue &q){
	// 一直入队直到满
	for(int i = 0; i < 10; i++){
		if(!EnQueue(q, i))
			break;
	}
	int x;
	// 一直出队直到空
	while(DeQueue(q, x))
		cout << x << ' ';
	return;
}

int main(int argc, char *argv[]) {
	LiQueue q;
	Init(q);
	run(q);
	return 0;
}