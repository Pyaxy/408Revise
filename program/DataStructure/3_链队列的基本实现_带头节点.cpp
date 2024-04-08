#include <iostream>
// 带头节点的链队实现
using namespace std;
typedef int Elemtype;
// 节点定义
typedef struct LiQueueNode{
	Elemtype data;
	struct LiQueueNode* next;
} LinkNode;
// 链队定义
typedef struct{
	LinkNode *front, * rear;
} LiQueue;

// 初始化，首尾指针都指向头节点
bool Init(LiQueue &q){
	LinkNode *node = (LinkNode*)malloc(sizeof(LinkNode));
	node->next = NULL;
	q.front = node;
	q.rear = node;
	return true;
}

// 判空
bool QueueEmpty(LiQueue &q){
	return q.front == q.rear;
}

bool EnQueue(LiQueue &q, Elemtype x){
	// 链队一般不会上溢
	// 新建节点
	LinkNode* node = (LinkNode*)malloc(sizeof(LinkNode));
	// 赋值
	node->data = x;
	// 新建节点为队尾，后面没有节点
	node->next = NULL;
	// 队尾的节点为新节点
	q.rear->next = node;
	// 修改队尾
	q.rear = node;
	return true;
}

bool DeQueue(LiQueue &q, Elemtype &x){
	// 判空
	if(QueueEmpty(q))
		return false;
	// 获得要删除的节点
	LinkNode *p = q.front->next;
	// 获得数据
	x = p->data;
	// 删除节点
	q.front->next = p->next;
	// 如果删除的节点是最后一个节点，则队列为空，尾节点指向头节点
	if(p == q.rear)
		q.rear = q.front;
	free(p);
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