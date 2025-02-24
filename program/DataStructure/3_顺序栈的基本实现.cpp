#include <iostream>

using namespace std;

// 栈的最大长度
#define MAXSIZE 10
typedef int Elemtype;
// 结构定义
typedef struct{
	Elemtype data[MAXSIZE];
	int top;
}sqStack;

// 初始化栈底为-1
void InitStack(sqStack &s) {
	s.top = -1;
}

// 判断栈空
bool stackEmpty(sqStack &s) {
	return s.top == -1;
}

// 进栈
bool push(sqStack &s, Elemtype x) {
	// 判断是否栈满
	if(s.top == MAXSIZE - 1)
		return false;
	// 注意先加后加，具体分析
	s.data[++s.top] = x;
	return true;
}

// 出栈
bool pop(sqStack &s, Elemtype &x) {
	// 判空
	if(stackEmpty(s))
		return false;
	// 注意先减后减
	x = s.data[s.top--];
	return true;
}

// 获取栈顶
bool getTop(sqStack &s, Elemtype &x) {
	if(stackEmpty(s))
		return false;
	x = s.data[s.top];
	return true;
}

// 一个例子，王道408，数据结构69页16题
void run(sqStack &s){
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
	sqStack S;
	InitStack(S);
	run(S);
	return 0;
}