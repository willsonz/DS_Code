// 线性表顺序结构及算法的具体实现
//
//
#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

Status InitList_sq(Sqlist &L)
{
    // 构造一个空的顺序表L。
    L.elem = (ElemType * )malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);             // 存储分配失败
    L.length = 0;                   // 空表长度为0
    L.list_size = LIST_INIT_SIZE;   // 初始化存储容量
    return OK;
} // InitList_sq

Status DestroyList_sq(Sqlist &L)
{
    // 初始条件:线性表L已存在,在此不进行检验
    // 结果:销毁线性表L
    free(L.elem);
    return OK;
} // DestroyList_sq

Status ClearList_sq(Sqlist &L)
{
    // 条件:线性表L已存在，此不做检测
    // 结果:将L重置为空表
    free(L.elem);       // 释放L原有存储空间
    InitList_sq(L);     // 重置L为空表
    return OK;
} // ClearList_sq

Status ListEmpty_sq(Sqlist L)
{
    // 调价:线性表L已存在
    // 结果:若L为空表，则返回TRUE，否则返回FALSE
    return (!L.length) ? TRUE : FALSE;
} // ListEmpty_sq

int ListLength_sq(Sqlist L)
{
    // 条件:线性表L已存在
    // 结果:返回L中数据元素的个数
    return L.length;
} // ListLength_sq

Status GetElem_sq(Sqlist L, int i, ElemType &e)
{
    // 条件:线性表L已存在，1<= i <= ListLength(L)
    // 结果:用e返回L中第i个数据元素的值
    if (i < 1 || i > L.length+1)
        exit(ERROR);        // i值不合法
    e = *(L.elem + i - 1);  //将L中第i个数据元素的值赋给e
    return OK;
} // GetElem_sq

Status compare_equl(ElemType e1, ElemType e2)
{
    return (e1 == e2) ? TRUE : FALSE;
} // compare_equl

int LocateElem_sq(Sqlist L, ElemType e,
                  Status ( *compare)(ElemType, ElemType))
{
    // 条件:线性表L已存在,compare()是数据元素判定程序
    // 结果:返回L中第一个与e满足compare()的数据元素的位序，
    //      若这样的数据不存在，则返回值为0
    int i = 1;
    while ( (i <= L.length) && !(compare)(e, *(L.elem+i-1))) i++;
    return (i <= L.length) ? i : 0;
} // LocateElem_sq

Status PriorElem_sq(Sqlist L, ElemType cur_e, ElemType &pre_e)
{
    // 条件:线性表L已存在
    // 结果:若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    //  否则操作失败，pre_e无定义
    int cur_pos;
    cur_pos = LocateElem_sq(L, cur_e, compare_equl);

    if (!cur_pos || cur_pos == 1)
        return ERROR;           // 所寻元素不存在或是第一个
    else
        pre_e = *(L.elem + cur_pos - 2);

    return OK;
} // PriorElem_sq

Status NextElem_sq(Sqlist L, ElemType cur_e, ElemType &next_e)
{
    // 条件:线性表L已存在
    // 结果:若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    // 否则操作失败，next_e无定义。
    int cur_pos;
    cur_pos = LocateElem_sq(L, cur_e, compare_equl);

    if (!cur_pos || cur_pos == L.length)
        return ERROR;           // 所寻元素不存在或是第一个
    else
        next_e = *(L.elem + cur_pos);

    return OK;
} // NextElem_sq

Status ListInsert_sq(Sqlist &L, int i, ElemType e)
{
    // 在顺序线性表L中第i个位置之前插入新的元素e，
    // i 的合法值为 1<= i <= ListLength_sq(L) + 1
    //
    if (i < 1 || i > L.length+1) return ERROR;  // i值不合法

    if (L.length >= L.list_size) {  // 当前存储空间已满，增加分配
        ElemType * newbase;
        newbase = (ElemType * )realloc(L.elem,
                        (L.list_size + LISTINCREMENT) * sizeof(ElemType));

        if (!newbase) exit(OVERFLOW);   // 存储分配失败
        L.elem = newbase;               // 新基址
        L.list_size += LISTINCREMENT;   //增加存储变量
    }

    ElemType * q;   // q为插入位置指针
    ElemType * p;   // p为插入位置后元素的移动指针
    q = L.elem + i - 1;

    for (p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p+1) = *p;
    *q = e;         // 插入e
    ++L.length;     // 表长加1

    return OK;
} // ListInsert_sq

Status ListDelete_sq(Sqlist &L, int i, ElemType &e)
{
    // 初始条件:线性表L已存在，1<= i <= ListLength(L);
    // 操作结果:删除L的第i个数据元素，并用e返回其值，L长度减1;
    if (i < 1 || i > L.length) return ERROR;    // i值不合法

    ElemType *p, *q;
    q = L.elem + i - 1;   // q为被删除元素位置
    e = *q;                 // 将被删除位置的值赋给e
    p = L.elem + L.length - 1;  // 表尾元素位置

    for (++q; q <= p; ++q)      //被删除元素之后的元素左移
        *(q-1) = *q;
    --L.length;                 // 表长减1

    return OK;
} // ListDelete_sq

Status ListTraverse_sq(Sqlist L, Status (*visit_sq)(ElemType))
{
    // 依次对L的每个数据元素调用函数visit().
    // 一旦visit()失败,则操作失败。
    int i;

    for (i = 0; i < L.length; ++i) {
        if (! visit_sq(*(L.elem+i)))
            return ERROR;
    }

    return OK;
} // ListTraverse

Status visit_sq(ElemType e)
{
    printf("%d ", e);
    return TRUE;
} // visit_sq

// 算法2.7 - 归并算法
Status MergeList_sq(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
    // 条件:线性表La和Lb中的数据元素按值非递减排列。
    // 结果:归并La和Lb得到新的线性表Lc, Lc的数据元素也按值非递减排列。
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    pa = La.elem;               // pa,pb,pc分别为La,Lb,Lc当前元素的位置
    pb = Lb.elem;
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;
    Lc.list_size = Lc.length = La.length + Lb.length;    // 设置Lc的长度和容量
    pc = Lc.elem = (ElemType *)malloc(Lc.list_size * sizeof(ElemType));
    if(!Lc.elem) exit(ERROR);   // 分配存储空间失败

    while (pa <= pa_last && pb <= pb_last) {    // 归并
        * pc++ = (*pa < *pb) ? *pa++ : *pb++;
    }
    while (pa <= pa_last) * pc++ = * pa++;      // 插入La剩余元素
    while (pb <= pb_last) * pc++ = * pb++;      // 插入Lb剩余元素

    return OK;
} // MergeList_sq
