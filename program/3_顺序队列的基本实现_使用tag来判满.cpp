#include <iostream>

using namespace std;
#define MAXSIZE 10
typedef int Elemtype;
typedef struct{
	Elemtype data[MAXSIZE];
	int rear, front;
	// tag为0表示上一次操作是出队，tag为1表示上一次操作是入队
	int tag;
} SqQueue;

bool InitQueue(SqQueue &q){
	q.rear = 0;
	q.front = 0;
	q.tag = 0;
	return true;
}

bool QueueEmpty(SqQueue &q){
	return (q.rear == q.front) && !q.tag;
}

bool EnQueue(SqQueue &q, Elemtype x){
	if(q.rear == q.front && q.tag == 1)
		return false;
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MAXSIZE;
	q.tag = 1;
	return true;
}

bool DeQueue(SqQueue &q, Elemtype &x){
	if(QueueEmpty(q))
		return false;
	x = q.data[q.front];
	q.front = (q.front + 1) % MAXSIZE;
	q.tag = 0;
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