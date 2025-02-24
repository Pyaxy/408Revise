#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
#define ElemType int

typedef struct {
  ElemType *data; // 指针指向动态数组起点
  int MaxSize;    // 最大长度
  int length;     // 当前长度
} SqList;

void InitList(SqList &L) {
  L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize); // 申请内存
  L.MaxSize = InitSize; // 初始最大空间为分配空间大小
  L.length = 0;         // 初始长度为0
}

void IncreaseSize(SqList &L, int len) {
  ElemType *p = L.data; // 辅助指针指向原数组位置
  L.data = (ElemType *)malloc(
      sizeof(ElemType) *
      (L.MaxSize + len)); // 为数组申请新的空间，大小为old + len
  for (int i = 0; i < L.MaxSize; i++)
    L.data[i] = p[i];          // 将旧数据转移到新位置
  L.MaxSize = L.MaxSize + len; // 修改最大长度
  free(p);                     // 释放原来空间
}

int main() {
  SqList L;
  InitList(L);
  //....
  for (int i = 0; i < L.MaxSize; i++) {
    printf("%d ", L.data[i]);
  }
  IncreaseSize(L, 5);
  printf("\n");
  for (int i = 0; i < L.MaxSize; i++) {
    printf("%d ", L.data[i]);
  }
  free(L.data);
  return 0;
}
