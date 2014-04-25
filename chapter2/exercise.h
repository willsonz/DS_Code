# ifndef _EXERCISE_H
# define _EXERCISE_H

# include <stdio.h>
# include <stblib.h>
# include "basic.h"
# include "sqliist.h"

//-----------算法函数原型-----------------
Status InsertInOrder(SqList &L, ElemType x);
    // 将数据元素x插入到递增有序的顺序表L中,保持L的有序性

Status cmp2(ElemType e1, ElemType e2);
    // 当e1<=e2时返回TRUE，否则返回FALSE

Status compareList(SqList A, SqList B);
    // 比较顺序表A,B

Status DelInOrder(LinkList &L, ElemType mink, ElemType maxk);
    // 已知L为单链线性表且元素以值递增有序排列，
    // 删除表中所有大于mink且小于maxk的元素,并释放结点空间

Status reverseSq(Sqlist &L);
    // 利用原表的空间,实现顺序表的就地逆置

void swap_sq(ElemType *left, ElemType *right);
    // 交换left和right两个位置的数据值

Status reverLinkList(LinkList &L);
    // 实现对单链表的逆置
    //
Status reverMergeList( LinkList &La, LinkList &Lb, LinkList &Lc );
    // A和B均为按元素值递增有序排列线性表,
    // 利用A和B的空间把A和B归并为递减线性表Lc
