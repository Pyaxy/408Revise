#include <stdio.h>
#include <sys/types.h>
#define MAXSIZE 10
#define ElemType int

typedef struct {
  ElemType data[MAXSIZE];
  int length;
} SqList;

void InitList(SqList &L) {
  for (int i = 0; i < MAXSIZE; i++)
    L.data[i] = 0;
  L.length = 0;
}

// 在顺序表中查找第一个值为 e 的元素，返回其位序
int LocateElem(SqList &L, int i, ElemType e) {
  for (int i = 0; i < L.length; i++) {
    if (L.data[i] == e)
      return i + 1;
  }
  return 0;
}
// 顺序表中按位查找元素并返回
ElemType GetElem(SqList &L, int i, ElemType e) { return L.data[i - 1]; }
