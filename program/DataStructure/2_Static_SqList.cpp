#include <cstdio>
#include <stdio.h>
#define MaxSize 10 // 最大长度
#define ElemType int
typedef struct {
  ElemType data[MaxSize]; // 静态数组来存储顺序表
  int length;             // 数组长度
} SqList;

void InitList(SqList &L) {
  for (int i = 1; i < MaxSize; i++) {
    L.data[i] = 0; // 避免脏数据
  }
  L.length = 0; // 初始长度为0
}

int main() {
  SqList L;
  InitList(L);
  // 。。。一些操作
  for (int i = 0; i < MaxSize; i++) {
    printf("%d ", L.data[i]);
  }
  return 0;
}
