// 带头结点的线性链表的一般化
//
#ifndef _LINKLIST_H
# define _LINKLIST_H

# include <stdio.h>
# include "header/basic.h"

typedef struct LNode {      // 结点类型
    ElemType data;
    struct LNode *next;
} *Link, *Position;

typedef struct {        // 链表类型
    Link head, tail;    // 分别指向线性链表的头结点和最后一个结点
    int len;            // 指示线性链表中数据元素的个数
} LinkList;

// -----------基本操作函数原型------------
Status MakeNode(Link &p, ElemType e);
void FreeNode(Link &p);
Status InitList(LinkList &L);
Status ClearList(LinkList &L);
Status DestroyList(LinkList &L);
Status InsFirst(Link h, Link s);
Status DelFirst(Link h, Link &q);
Status Append(LinkList &L, Link s);
Status Remove(LinkList &L, Link &q);
Status InsBefore(LinkList &L, Link &p, Link s);
Status InsAfter(LinkList &L, Link &p, Link s);
Status SetCurElem(Link &p, ElemType e);
ElemType GetCurElem(Link p);
Status ListEmpty(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position PriorPos(LinkList L, Link p);
Position NextPos(LinkList L, Link p);
Status LocatePos(LinkList L, int i, Link &p);
Position LocateElem(LinkList L, ElemType e,
                    Status (*compare)(ElemType, ElemType));

#endif
