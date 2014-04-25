// 习题算法设计程序文件

#include <stdio.h>
#include <stdlib.h>
#include "exercise.h"

// 算法2.11
Status InsertInOrder(Sqlist &L, ElemType x)
{
    // 将数据元素x插入到递增有序的顺序表L中,保持L的有序性
    int i;
    i = LocateElem_sq(L, x, (*cmp2)());  // 寻找合适的位置赋给i
    if (ListInsert_sq(L, i, x))         // 插入第i个位置之前
        return OK;       // 成功
    else
        return ERROR;
} // InsertInOrder

// cmp2
Status cmp2(ElemType e1, ElemType e2)
{
    // 当e1<=e2时返回TRUE，否则返回FALSE
    return (e1 <= e2) ? TRUE : FALSE;
} // cmp2

// 算法2.12
Status compareList(Sqlist A, Sqlist B)
{
    // 比较顺序表A和B,
    int i, min_len;
    ElemType a, b;
    min_len = (A.length < B.length) ? A.length : B.length;  // 将较小表长

    for (i = 1; i <= min_len ; i++) {        // 寻找A，B首元的位置
        if (*(A.elem+i-1) != *(B.elem+1-1))
            break;
    }

    if (i > min_len) {
        if (A.length == B.length)   // A = B
            return 0;
        else (A.length < B.length)  // A'为空表,B'不为空表,A < B
            return -1;
        else
            return 1;               // A > B
    }
    else {
        GetElem_sq(A, i, a);        // 得A’首元
        GetElem_sq(B, i, b);        // 得B'首元

        return (a < b) ? -1 : 1;
    }
} // compareList

// 算法2.19
Status DelInOrder(LinkList &L, ElemType mink, ElemType maxk)
{
    // 已知L为单链线性表且元素以值递增有序排列，
    // 删除表中所有大于mink且小于maxk的元素,并释放结点空间
    int i;
    Link h, q;
    ElemType e;
    h = GetHead(L);   // p指向第一个结点
    e = GetCurElem(h->next);
    while (!h->next && e < maxk) {
        if ( mink < h->next->data < maxk) {
            DelFirst(h, q);     // 删除结点
            FreeNode(q);        // 释放结点空间
        }

        h = h->next;
        e = GetCurElem(h->next);
    }

    return OK;
} // DelInOrder

// 算法2.21
Status reverseSq(Sqlist &L)
{
    // 利用原表的空间,实现顺序表的就地逆置
    ElemType *left, *right;
    int i;

    for (i = 1; i < L.length; i++) {
        left = L.elem + i;
        right = L.elem + L.length - i;
        swap(left, right);
    }

    return OK;
} // reverseSq

void swap_sq(ElemType *left, ElemType *right)
{
    // 交换left和right两个位置的数据值
    ElemType temp;
    temp = *left;
    *left = *right;
    *right = temp;
}

Status reverLinkList(LinkList &L)
{
    // 实现对单链表的逆置
    Link pre_node, cur_node, next_node;
    int i;

    pre_node = L.head->next;        // 指向第一个结点
    cur_node = NextPos(pre_node);   // 指向第二个结点
    next_node = NextPos(cur_node);  // 指向第三个结点

    pre->next = NULL;
    L.head = L.tail;
    L.tail = pre;

    for( i = 2; i <= L.len; i++ ) {
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = next_node;
        next_node = NextPos(next_node);
    }

    return OK;
} // reverLinkList

// 算法2.24
Status reverMergeList( LinkList &La, LinkList &Lb, LinkList &Lc )
{
    // A和B均为按元素值递增有序排列线性表,
    // 利用A和B的空间把A和B归并为递减线性表Lc
    Mergelist( La, Lb, Lc, *compare());      // 归并为递增线性表
    reverLinkList(Lc);          // 逆置线性表Lc

    return OK;
} // reverMergeList

// 算法2.27
Status Intersect_sq( Sqlist &La, Sqlist &Lb, Sqlist &Lc ,
                    Status (*compare_equl)(ELemType, ElemType) )
{
    // La和Lb均为依值递增有序的顺序线性表,构造Lc为A和B的交集,且Lc
    // 也为递增排列;
    // Lc使用La的空间,表内的值各不相同

}

// 算法2.28
Status Intersect_l( LinkList &La, LinkList &Lb, LinkList &Lc )
{
    // 算法2.27的单链表形式
    Link pa, pb, pc, ha, hb;

    ha = GetHead(La);
    hb = GetHead(Lb);
    pa = NextPos(ha);       // pa指向La的第一个结点
    pb = NextPos(hb);       // pb指向Lb的第一个结点

    while( pa.data <= pb.data);

}


