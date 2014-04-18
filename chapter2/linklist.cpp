// 线性表链式结构一般化算法的实现
//
#include <stdio.h>
#include <stdlib.h>
#include "header/linklist.h"

// 基本操作函数定义
Status MakeNode(Link &p, ElemType e)
{
    // 分配由p指向的值为e的结点，并返回OK;若分配失败，则返回ERROR
    p = (Link) malloc (sizeof(LNode));
    if (!p)
        return (ERROR);    // 分配失败
    else
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
    Link p = s;
    L.tail->next = s;   // 链接s所指的结点

    int i = 1;          // 新结点计数器
    while (!(p->next)) {
        p = p->next;    // 寻找新的尾结点
        i++;
    }
    L.tail = p;         // 指向新的尾结点
    L.len += i;         // 更新链表长度

    return OK;
} // Append

Status Remove(LinkList &L, Link &q)
{
    // 删除线性链表L的尾结点并以q返回，改变链表的尾指针指向新的尾结点
    q = L.tail;

    Link p;
    p = PriorPos(L, L.tail);    // p指向尾结点的前趋，若为空表，则p为NULL
    if (!p) return ERROR;       // 空表无法删除尾结点
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

    Link q;
    q = PriorPos(L, p);     // q指向p结点的前趋

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
    if (p == L.tail) {      // 若p指向尾结点,则更新尾结点为s
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
    return !L.len ? TRUE : FALSE;
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

    Link q = L.head;
    while (q->next != p)
        q = q->next;

    return q;
} // PriorPos

Position NextPos(LinkList L, Link p)
{
    // 已知p指向线性链表L中的一个结点,返回p所指结点上网直接后继的位置,
    // 若无后继,则返回NULL
    return p->next;
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

    while (! compare(p->data, e) && i <= L.len) {
        p = p->next;
        i++;
    }

    if (i > L.len)      // 元素不存在
        return ERROR;
    else
        return p;
} // LocateElem

Status ListTraverse(LinkList L, Status (*visit)(Link))
{
    // 依次对L的每个元素调用函数visit(),
    // 一旦visit失败，则操作失败
    Link p = L.head->next;  // p指向L的第一个结点
    int i = 1;      // 元素计数器

    for (i = 1; i <= L.len; i++) {
        if (! visit(p))
            return ERROR;
        else
            p = p->next;
    }

    return OK;
} // ListTraverse

Status visit(Link p)
{
    // 打印出结点的数据值
    printf("%f ", p->data);
    return OK;
} // visit

Status ListInsert(LinkList &L, int i, ElemType e)
{
    // 在带头结点的单链线性表L的第i个元素之前插入元素e
    Link h, s;

    if (!LocatePos(L, i-1, h)) return ERROR;    // i值不合法
    if (!MakeNode(s, e)) return ERROR;          // 结点存储失败
    InsFirst(h, s);      // 对从第i个结点开始的链表,第i-1个结点是它的头结点
    return OK;
} // ListInsert

Status MergeList(LinkList &La, LinkList &Lb, LinkList &Lc,
                 int (*compare)(ElemType, ElemType))
{
    // 已知单链线性表La和Lb的元素按值递增排列
    // 归并La和Lb得到新的单链线性表Lc, Lc的元素也按值递增排列
    Link ha, hb, pa, pb, q;
    ElemType a, b;
    if (!InitList(Lc)) return ERROR;    // 存储空间分配失败
    ha = GetHead(La);
    hb = GetHead(Lb);       // ha和hb分别指向La和Lb的头结点
    pa = NextPos(La, ha);
    pb = NextPos(Lb, hb);   // pa和pb分别指向La和Lb中当前结点

    while (pa && pb) {
        a = GetCurElem(pa);
        b = GetCurElem(pb);     // a和b为两表中当前比较元素

        if (compare(a, b) <= 0) {   // a < b
            DelFirst(ha, q);
            Append(Lc, q);
            pa = NextPos(La, ha);
        }
        else {      //  a > b
            DelFirst(hb, q);
            Append(Lc, q);
            pb = NextPos(Lb, hb);
        }
    }

    if (pa)
        Append(Lc, pa);     // 链接La中剩余结点
    else
        Append(Lc, pb);     // 链接Lb中剩余结点

    FreeNode(ha);
    FreeNode(hb);           // 释放La和Lb的头结点
    return OK;
} // MergeList

int compare(ElemType e1, ElemType e2)
{
    // 比较e1和e2数据元素值大小,如果e1<e2,则返回-1;
    // e1=e2,则返回0;
    // e1>e2,则返回+1;
    if (e1 < e2)
        return -1;
    else if (e1 == e2)
        return 0;
    else
        return 1;
} // compare
