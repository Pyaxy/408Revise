#include <iostream>
// 定长顺序存储表示字符串
using namespace std;
#define MAXSIZE 255
// 字符串下标从1开始，0废弃不用
typedef struct{
	char ch[MAXSIZE];
	int len;
}SString;

// 赋值操作，把串T赋值为chars
bool StrAssign(SString &T, string chars){
	for(int i = 1; i <= chars.length(); i++)
		T.ch[i] = chars[i-1];
	T.len = chars.length();
	return true;
}
// 打印串T
void StrOutput(SString &T){
	for(int i = 1; i <= T.len; i++)
		cout << T.ch[i];
	cout << endl;
}

// 判断是否为空
bool StrEmpty(SString &T){
	return T.len == 0;
}

// 求串T的在pos位置的长度为l的子串
bool SubString(SString &sub, SString T, int pos, int l){
	// 超出长度了
	if(pos + l - 1 > T.len)
		return false;
	int k = 1;
	for(int i = pos; i <= pos + l - 1; i++)
		sub.ch[k++] = T.ch[i];
	sub.len = k - 1;
	return true;
}

// 字符串比较, 若S>T, 则返回值大于0; 若S=T, 则返回值等于0; 若S<T, 则返回值小于零;
int StrCompare(SString S, SString T){
	for(int i = 1; i <= S.len && i <= T.len; i++)
		if(S.ch[i] != T.ch[i])
			return S.ch[i] - T.ch[i];
	return S.len - T.len;
}
// 定位操作。若主串S中存在与串T相同的子串，则返回他在主串中第一次出现的位置，否则返回0
int Index(SString S, SString T){
	if(T.len > S.len)
		return 0;
	int  i = 1;
	while(i <= S.len - T.len + 1){
		SString subs;
		SubString(subs, S, i, T.len);
		if(StrCompare(subs, T) == 0)
			return i;
		i++;
	}
	return 0;
}
int main(int argc, char *argv[]) {
	SString s;
	StrAssign(s, "12345");
	StrOutput(s);
	SString sub;
	if(SubString(sub, s, 2, 2))
		StrOutput(sub);
	SString t;
	StrAssign(t, "35");
	cout << Index(s, t);
	return 0;
}