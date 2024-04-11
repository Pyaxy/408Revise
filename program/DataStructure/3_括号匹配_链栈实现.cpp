#include <iostream>
// 使用栈实现括号匹配
using namespace std;
typedef char Elemtype;
// 使用链栈来维护括号
typedef struct node{
	Elemtype data;
	node *next;
} LiStackNode, *Listack;

// 初始化链栈
bool InitStack(Listack &s){
	s = NULL;
	return true;
}

// 栈空
bool StackEmpty(Listack &s){
	return s == NULL;
}

// 入栈
bool push(Listack &s, Elemtype x){
	LiStackNode *node = (LiStackNode*)malloc(sizeof(LiStackNode));
	node->data = x;
	node->next = s;
	s = node;
	return true;
}

// 出栈
bool pop(Listack &s){
	if(StackEmpty(s))
		return false;
	LiStackNode *node = (LiStackNode*)malloc(sizeof(LiStackNode));
	node = s;
	s = s->next;
	free(node);
	return true;
}

// 获得栈顶元素
Elemtype getTop(Listack &s){
	if(StackEmpty(s))
		return '0';
	return s->data;
}

// 括号匹配算法
bool BracketMatching(Listack &s, string str){
	// 如果传入的串为空，直接返回
	if(str == "")
		return false;
	Elemtype temp;
	// 遍历串
	for(auto c:str){
		// 如果为左括号，直接入栈
		if(c == '(' || c == '[' || c == '{')
			push(s, c);
		else{
			// 如果右括号与左括号不匹配，直接返回，匹配失败
			if(c == ')' &&  getTop(s) != '(')
				return false;
			if(c == ']' && getTop(s) != '[')
				return false;
			if(c == '}' && getTop(s) != '{')
				return false;
			// 右括号与左括号匹配，栈顶的左括号出栈
			pop(s);
		}
	}
	// 如果结束后栈为空则匹配成功
	return StackEmpty(s);
}

int main(int argc, char *argv[]) {
	string str;
	cin >> str;
	Listack s;
	InitStack(s);
	cout << BracketMatching(s, str);
	return 0;
}