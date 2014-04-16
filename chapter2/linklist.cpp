// 线性表链式结构一般化算法的实现
//
#include <stdio.h>
#include <stdlib.h>
#include "header/basic.h"
#include "header/linklist.h"

// 基本操作函数定义
Status MakeNode(Link &p, ElemType e)
{
    // 分配由p指向的值为e的结点，并返回OK;若分配失败，则返回ERROR
    p = (Link) malloc (sizeof(LNode));
    if (!p)
        return (ERROR);    // 分配失败
    p->data = e;

    return OK;
} // MakeNode

void FreeNode(Link &p)
{
    // 释放p所指结点
    free(p);
    p = NULL;
} // FreeNode

Status InitList(LinkList &L)
{
    // 构造一个空的线性链表L
    L.head = L.tail = (Link) malloc (sizeof(LNode));
    if (!L.head) return ERROR;      // 分配失败
    L.head->next  = NULL;
    L.len = 0;

    return OK;
} // InitList

Status ClearList(LinkList &L)
{
    // 将线性链表L重置为空表，并释放原链表的结点空间
    Link p, q;
    p = L.head->next;       // p指向链表的第一个结点
    L.head->next = NULL;

    while (!p) {            // 遍历各结点并释放其空间
        q = p;
        free(p);            // 销毁当前结点
        p = q->next;        // p指向下一个结点
    }
    L.tail = L.head;        // 初始化尾结点

    L.len = 0;

    return OK;
} // ClearListtu
Status DestroyList(LinkList &L)
{
    // 销毁线性链表L, L不再存在
    ClearList(L);   // 重置L为空表
    free(L.head);   // 释放头结点空间
    L.head = L.tail = NULL;

    return OK;
} // DestroyList

Status InsFirst(Link h, Link s)
{
    // 已知h指向线性链表的头结点,将s所指结点插入在第一个结点之前
    s->next = h->next;
    h->next = s;
    return OK;
} // InsFirst

Status DelFirst(Link h, Link &q)
{
    // 已知h指向线性链表的头结点,删除链表中的第一个结点并以q返回
    q = h->next;
    h->next = q->next;
    q->next = NULL;
    return  OK;
} // DelFirst

Status Append(LinkList &L, Link s)
{
    // 将指针s所指的一串结点链接在线性链表L的最后一个结点
    // 之后，并改变链表L的尾指针指向新的尾结点
    L.tail->next = s;

    int i = 1;          // 新结点计数器
    while (!(s->next)) {
        s = s->next;    // 寻找新的尾结点
        i++;
    }
    L.tail = s;         // 指向新的尾结点
    L.len += i;         // 更新链表长度

    return OK;
} // Append

Status Remove(LinkList &L, Link &q)
{
    // 删除线性链表L的尾结点并以q返回，改变链表的尾指针指向新的尾结点
    q = L.tail;

    if (L.head == L.tail)
        return ERROR;       // 空表无法去除尾结点

    Link p = L.head;
    while (L.tail != p->next)   // 寻找新的尾结点
        p = p->next;
    L.tail = p;         // 删除尾结点，更新尾结点
    L.tail->next = NULL;
    L.len--;            // 表长减1

    return OK;
} // Remove

Status InsBefore(LinkList &L, Link &p, Link s)
{
    // 已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之前,
    // 并修改指针p指向新插入的结点
    if (!L.len)
        return ERROR;       // 空表插入失败

    Link q = L.head;        // q指向头结点
    while (p != q->next)    // 寻p所指结点的前趋
        q = q->next;
    q->next = s;            // 插入
    s->next = p;
    L.len++;
    p = s;                  // 修改p指向新插入结点

    return OK;
} // InsBefore

Status InsAfter(LinkList &L, Link &p, Link s)
{
    // 已知p指向线性链表L中的一个结点,将s所指结点插入在p所指结点之后，
    // 并修改指针p指向新插入的结点
    if (p == L.tail) {      // 若p指向尾结点
        L.tail = s;
    }

    s->next = p->next;      // 插入
    p->next = s;
    L.len++;
    p = s;                  // 修改p指向新插入结点

    return OK;
} // InsAfter

Status SetCurElem(Link &p, ElemType e)
{
    // 已知p指向线性链表中的一个结点,用e更新其数据值
    p->data = e;
    return OK;
} // SetCurElem

ElemType GetCurElem(Link p)
{
    // 已知p指向线性链表中的一个结点,返回p所指结点中数据元素的值
    return p->data;
} // GetCurElem

Status ListEmpty(LinkList L)
{
    // 若线性链表为空,则返回TRUE, 否则返回FALSE
    return ！L.len ? TRUE : FALSE;
} // ListEmpty

Position GetHead(LinkList L)
{
    // 返回线性链表L中头结点的位置
    return L.head;
}

Position GetLast(LinkList L)
{
    return L.tail;
}


Position PriorPos(LinkList L, Link p)
{
    // 已知p指向线性链表L中的一个结点,返回p所指结点的直接前趋的位置,
    // 若无前趋,则返回NULL
    if (p == L.head)       // p指向头结点则无前趋
        return NULL;

    Link q = L;
    while (q->next != p)
        q = q->next;

    return q;
} // PriorPos

Position NextPos(LinkList L, Link p)
{
    // 已知p指向线性链表L中的一个结点,返回p所指结点上网直接后继的位置,
    // 若无后继,则返回NULL
    return (p == L.tail) ? NULL : p->next;
} // NextPos

Status LocatePos(LinkList L, int i, Link &p)
{
    // 返回p指示线性链表L中第i个结点的位置并返回OK,
    // i指不合法则返回ERROR
    if (i < 1 || i > L.len)     // i值不合法
        return ERROR;

    p = L.head->next;           // p指向第1个结点
    int j = 1;
    while (j < i)
        p = p->next;

    return OK;
} // LocatePos

Position LocateElem(LinkList L, ElemType e,
                    Status( *compare)(ElemType, ElemType))
{
    // 返回线性链表L中第i个与compare()判定关系的元素的位置,
    // 若不存在这样的元素,则返回ERROR
    Link p = L.head->next;          // p指向第一个结点
    int i = 1;

    while (! compare(p->data, e) && i <= L.len)
        p = p->next;
    if (i > L.len)      // 元素不存在
        return ERROR;

    return p;
} // LocateElem



