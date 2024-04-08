#include <iostream>

// 首在队首元素，尾在队尾的下一个位置
using namespace std;
#define MAXSIZE 10
typedef int Elemtype;

// 队列结构定义
typedef struct{
	Elemtype data[MAXSIZE];
	int front, rear;
} SqQueue;

// 初始化队列
bool InitQueue(SqQueue &q){
	q.front = 0;
	q.rear = 0;
	return true;
}

// 队列判空
bool QueueEmpty(SqQueue &q){
	return q.front == q.rear;
}

// 入队
bool EnQueue(SqQueue &q, Elemtype x){
	// 判满
	if((q.rear + 1)%MAXSIZE == q.front)
		return false;
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MAXSIZE;
	return true;
}

// 出队
bool DeQueue(SqQueue &q, Elemtype &x){
	if(QueueEmpty(q))
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	return true;
}

void run(SqQueue &q){
	// 一直入队直到满
	for(int i = 0; true; i++){
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
	SqQueue q;
	InitQueue(q);
	run(q);
	return 0;
}