#include <iostream>
// 使用栈实现括号匹配
using namespace std;
#define MAXSIZE 20
typedef char Elemtype;
// 数组实现栈
typedef struct{
	Elemtype data[MAXSIZE];
	int top;
} SeqStack;

// 以下为基本操作
// 初始化
bool InitStack(SeqStack &s){
	s.top = 0;
	return true;
}

// 是否为空
bool StackEmpty(SeqStack &s){
	return s.top == 0;
}

// 入栈
bool push(SeqStack &s, Elemtype x){
	if(s.top == MAXSIZE)
		return false;
	s.data[s.top++] = x;
	return true;
}

// 出栈
bool pop(SeqStack &s){
	if(StackEmpty(s))
		return false;
	s.top--;
	return true;
}

// 获得栈顶
Elemtype getTop(SeqStack &s){
	if(StackEmpty(s))
		return '0';
	return s.data[s.top - 1];
}

// 括号匹配
bool BracketMatching(SeqStack &s, string str){
	if(str == "")
		return false;
	// 遍历串
	for(auto c:str){
		// 左括号直接入栈
		if(c == '(' || c == '[' || c == '{')
			push(s, c);
		else{
			// 如果左括号不匹配右括号，不匹配
			if(c == ')' && getTop(s) != '(')
				return false;
			if(c == ']' && getTop(s) != '[')
				return false;
			if(c == '}' && getTop(s) != '{')
				return false;
			// 如果左括号匹配右括号，左括号出栈
			pop(s);
		}
	}
	// 如果结束栈为空，匹配成功
	return StackEmpty(s);
}

int main(int argc, char *argv[]) {
	SeqStack s;
	InitStack(s);
	string str;
	cin >> str;
	cout << BracketMatching(s, str);
	return 0;
}