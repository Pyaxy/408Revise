#include <iostream>
// 使用size属性来判满
using namespace std;
#define MAXSIZE 10

typedef int Elemtype;
// 结构定义
typedef struct{
	Elemtype data[MAXSIZE];
	int rear, front;
	int size;
} SqQueue;

// 初始化
bool InitQueue(SqQueue &q){
	q.rear = 0;
	q.front = 0;
	q.size = 0;
	return true;
}
// 判空
bool QueueEmpty(SqQueue &q){
	return q.size == 0;
}
// 入队
bool EnQueue(SqQueue &q, Elemtype x){
	// 判满
	if(q.size == MAXSIZE)
		return false;
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MAXSIZE;
	q.size++;
	return true;
}
// 出队
bool DeQueue(SqQueue &q, Elemtype &x){
	// 判空
	if(QueueEmpty(q))
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	q.size--;
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