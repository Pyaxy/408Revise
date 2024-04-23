#include<iostream>
using namespace std;
#define MAXSIZE 256

// 字符串的结构
typedef struct{
    char ch[MAXSIZE];
    int len;
}SString;

// TODO: 手动求的NEXT数组，目前真题只考过手动求NEXT数组，考虑二刷的时候补充上
int Next[5] = {0, 0, 1, 2, 3};
bool StrAssign(SString &T, string chars){
    for(int i = 1; i <= chars.length(); i++)
        T.ch[i] = chars[i-1];
    T.len = chars.length();
    return true;
}

void StrOutput(SString T){
    for(int i = 1; i <= T.len; i++) {
        cout << T.ch[i];
    }
    cout << endl;
}

// KMP算法
int Index_KMP(SString S, SString sub) {
    int i = 1, j = 1;
    while( i <= S.len && j <= sub.len){
        if(j == 0||S.ch[i] == sub.ch[j]){
            i++;// 继续比较后续字符
            j++;
        }
        else{
            j = Next[j];// 回溯子串
        }
    }
    if(j == sub.len + 1)
        return i - sub.len;
    else
        return 0;
}

int main(){
    SString sub, ma;
    StrAssign(sub, "aaab");
    StrAssign(ma, "ababaabaaabb");
    cout << Index_KMP(ma, sub);
    return 0;
    
}