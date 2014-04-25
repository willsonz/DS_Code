// 线性链表结构及算法的实现
//
#include <stdio.h>
#include <stdlib.h>
#include "linklist_l.h"

Status InitList_L(LinkList_l &L)
{
    // 构造一个空的带表头结点线性链表L
    L = (LinkList_l) malloc(sizeof(LNode));
    L->next = NULL;

    return OK;
} // InitList

Status DestroyList_L(LinkList_l &L)
{
    // 销毁线性链表L
    LNode *p;     //
    while (L) {  // 顺时针销毁，直到为空
        p = L;
        L = L->next;
        free(p);
    }
} // DetroyList

Status ClearList_L(LinkList_l &L)
{
    // 将线性链表重置为空表,并释放原链表的结点空间
    LNode *p;
    p = L->next;

    DestroyList_L(p);      // 释放头结点后的结点空间
    L->next = NULL;         // 重置为空表

    return OK;
} // ClearList

bool ListEmpty_L(LinkList_l L)
{
    // 检查线性链表L是否为空表
    // 若为空表，返回TRUE, 否则返回FALSE
    return L->next ? FALSE : TRUE;
} // ListEmpty

int ListLength_L(LinkList_l L)
{
    // 返回线性链表数据元素的个数
    int i = 0;      // 计数器
    LNode *p = L->next;   // p指向L的第一个结点

    while (!p) {
        p = p->next;
        ++i;
    }

    return i;
} // ListLength

Status GetElem_L(LinkList_l L, int i, ElemType &e)
{
    // L为带头结点的单链表的头指针
    // 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
    LNode *p = L->next;   // p指向第一个结点
    int j = 1;          // j为计数器

    while (p && j<i) {  // 顺时针查找，知道p指向第i个元素或p为空
        p = p->next;
        ++j;
    }

    if (!p || j>i) return ERROR;    // 第i个元素不存在
    e = p->data;
    return OK;
} // GetElem

Status PriorLink_L(LinkList_l L, int i, LNode * &p)
{
    // 条件:L为带头结点的单链表,i不为1且小于表长
    // 返回L第i个结点的前驱，
    LNode *q = L;   // p指向头结点
    int j;

    for (j = 0; j < i-1; j++) { // 顺时针查找，直到p指向i位置的前驱
        q = q->next;
    }

    if (!q || j > i-1) {
        printf("The pre elem is not exist!\n");
        exit(ERROR);
    }
    p = q;

    return OK;
} // PriorList

Status NextLink_L(LinkList_l L, int i, LNode * &p)
{
    // 条件:L为带头结点的链表L,i小于表长且不为最后一个位置
    // 由p返回L第i个位置的后继
    LNode *q = L->next->next;
    int j = 1;

    while (q && j < i) {
        q = q->next;
        ++j;
    }

    if (!q || j>i) {
        printf("the elem not exsit\n");
        exit(ERROR);
    }
    p = q;

    return OK;
} // NextList

Status ListInsert_L(LinkList_l &L, int i, ElemType e)
{
    // 在带头结点的链表L中第i个位置之前插入元素e
    LNode *p;
    LNode *s;
    PriorLink_L(L, i, p);
    s = (LNode *) malloc (sizeof(LNode));  // 生成新结点

    // 插入
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
} // ListInsert

Status ListDelete_L(LinkList_l &L, int i, ElemType &e)
{
    //在带头结点的链表L中，删除第i个元素，并由e返回其值
    LNode *p, *q;
    PriorLink_L(L, i, q);    // p指向第i个元素的前趋

    // 删除并释放元素
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q);

    return OK;
} // ListDelete

Status visit_L(ElemType e)
{
    //
    printf("%d ", e);
    return TRUE;
}

Status ListTraverse_L(LinkList_l L, Status (*visit_L)(ElemType))
{
    //
    LNode *p;
    p = L->next;    // p指向第一个结点
    while (p) {
        if (! visit_L(p->data))
            return ERROR;

        p = p->next;    // 指向下一个结点
    }

    return OK;
} // ListTraverse_L

void MergeList_L(LinkList_l &La, LinkList_l &Lb, LinkList_l &Lc)
{
    // 已知单链线性表La和Lb的元素按值非递减排列
    // 归并La和Lb得到新的单链线性表Lc,Lc的元素也按值非递减排列
    LNode *pa, *pb, *pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;       // 用La的头结点作为Lc的头结点

    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
} // MergeList
