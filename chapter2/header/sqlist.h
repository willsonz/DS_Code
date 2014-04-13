#ifndef _SQLIST_H
# define _SQLIST_H

// 定义顺序表结构及相关算法函数原型

# define LIST_INIT_SIZE  100 // 线性表存储空间的初始分配量
# define LISTINCREMENT   10  // 线性表存储空间的分配增量
// 包含相关头文件
# include "basic.h"

// 定义线性表顺序结构类型
typedef struct {
    ElemType * elem;    // 存储空间基址
    int length;         // 当前长度
    int list_size;      // 当前分配的存储容量
}Sqlist;

Status InitList_sq(Sqlist &L);
Status DetroyList_sq(Sqlist &L);
Status ClearList_sq(Sqlist &L);
Status ListEmpty_sq(Sqlist L);
int ListLength_sq(Sqlist L);
Status GetElem_sq(Sqlist L, int i, ElemType &e);
int LocateElem_sq(Sqlist L, ElemType e, Status (*compare)(ElemType, ElemType));
Status PriorElem_sq(Sqlist L, ElemType cur_e, ElemType &pre_e);
Status NextElem_sq(Sqlist L, ElemType cur_e, ElemType &next_e);
Status ListInsert_sq(Sqlist &L, int i, ElemType e);
Status ListDelete_sq(Sqlist &L, int i, ElemType &e);

#endif
