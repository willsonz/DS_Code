#ifndef _SQLIST_H
# define _SQLIST_H
// 定义顺序表结构及相关算法函数原型

# define LIST_INIT_SIZE  100 // 线性表存储空间的初始分配量
# define LISTINCREMENT   10  // 线性表存储空间的分配增量
// 包含相关头文件
# include "basic.h"

// 定义该结构元素类型
typedef int ElemType;

// 定义线性表顺序结构类型
typedef struct {
    ElemType * elem;    // 存储空间基址
    int length;         // 当前长度
    int listsize;      // 当前分配的存储容量
}Sqlist;

//------------基本操作函数原型----------------
Status InitList_sq(Sqlist &L);
Status DestroyList_sq(Sqlist &L);
Status ClearList_sq(Sqlist &L);
Status ListEmpty_sq(Sqlist L);
int ListLength_sq(Sqlist L);
Status GetElem_sq(Sqlist L, int i, ElemType &e);
Status compare_equl(ElemType e1, ElemType e2);
int LocateElem_sq(Sqlist L, ElemType e, Status (*compare)(ElemType, ElemType));
Status PriorElem_sq(Sqlist L, ElemType cur_e, ElemType &pre_e);
Status NextElem_sq(Sqlist L, ElemType cur_e, ElemType &next_e);
Status ListInsert_sq(Sqlist &L, int i, ElemType e);
Status ListDelete_sq(Sqlist &L, int i, ElemType &e);
Status ListTraverse_sq(Sqlist L, Status (*visit_sq)(ElemType));
Status visit_sq(ElemType e);
Status MergeList_sq(Sqlist La, Sqlist Lb, Sqlist &Lc);

#endif
