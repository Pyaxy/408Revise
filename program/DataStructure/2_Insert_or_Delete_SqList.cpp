#include <stdio.h>
#include <stdlib.h>
#define InitSize 10
#define ElemType int

// 采用动态数组
typedef struct {
  ElemType *data;
  int MaxSize;
  int length;
} SqList;

// 初始化
void InitList(SqList &L) {
  L.data = (ElemType *)malloc(sizeof(ElemType) * InitSize);
  L.MaxSize = InitSize;
  L.length = 0;
}

bool InsertList(SqList &L, int i, int e) {
  // 超出当前顺序表范围判为非法，可用范围为已用空间的任一个地方以及表尾插一个，共length+1个
  if (i < 1 || i > L.length + 1)
    return false;
  // 表已满判为非法
  if (L.length == L.MaxSize)
    return false;

  // 从后往前移动元素，不能从前往后，会产生覆盖
  for (int j = L.length; j >= i; j--)
    L.data[j] = L.data[j - 1];
  // 第i个位置的索引为i-1
  L.data[i - 1] = e;
  // 长度加1
  L.length++;
  return true;
}

// 顺序表的删除
bool DeleteList(SqList &L, int i, int &e) {
  // 判断i的范围，范围为1-length
  if (i < 1 || i > L.length)
    return false;
  // 返回删除的值到e里
  e = L.data[i - 1];
  // 从前往后删除
  for (int j = i; j < L.length; j++)
    L.data[j - 1] = L.data[j];
  // 长度-1
  L.length--;
  return true;
}

void PrintList(SqList &L) {
  for (int i = 0; i < L.length; i++) {
    printf("%d ", L.data[i]);
  }
  printf("\n");
}

int main() {
  SqList L;
  InitList(L);
  int e = 0;
  if (InsertList(L, 1, 1))
    PrintList(L);
  else
    printf("error!\n");
  if (InsertList(L, 1, 2))
    PrintList(L);
  else
    printf("error!\n");
  if (InsertList(L, 3, 8))
    PrintList(L);
  else
    printf("error!\n");
  if (InsertList(L, 2, 4))
    PrintList(L);
  else
    printf("error!\n");
  if (DeleteList(L, 1, e))
    PrintList(L);
  else
    printf("error!");
  if (DeleteList(L, 3, e))
    PrintList(L);
  else
    printf("error!");

  if (DeleteList(L, 1, e))
    PrintList(L);
  else
    printf("error!");
  if (DeleteList(L, 1, e))
    PrintList(L);
  else
    printf("error!");
  if (DeleteList(L, 1, e))
    PrintList(L);
  else
    printf("error!");
}
