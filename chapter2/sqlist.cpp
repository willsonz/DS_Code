// 线性表顺序结构及算法的具体实现
//
//
#include <stdio.h>
#include <stdlib.h>
#include "basic.h"
#include "sqlist.h"

Status InitList_sq(Sqlist &L) {
    // 构造一个空的现行表L。
    L.elem = (ElemType * )malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L.elem)
        exit(OVERFLOW);             // 存储分配失败
    L.length = 0;                   // 空表长度为0
    L.list_size = LIST_INIT_SIZE;   // 初始化存储容量
    return OK;
} // InitList_sq

Status DestroyList_sq(Sqlist &L) {
    // 初始条件:线性表L已存在,在此不进行检验
    // 结果:销毁线性表L
    free(L.elem);
    return OK;
} // DestroyList_sq

Status ClearList_sq(Sqlist &L) {
    // 条件:线性表L已存在，此不做检测
    // 结果:将L重置为空表
    free(L.elem);       // 释放L原有存储空间
    InitList_sq(L);     // 重置L为空表
    return OK;
} // ClearList_sq

Status ListEmpty_sq(Sqlist L) {
    // 调价:线性表L已存在
    // 结果:若L为空表，则返回TRUE，否则返回FALSE
    (!L.length)? TRUE : FALSE;
    return OK
} // ListEmpty_sq

int ListLength_sq(Sqlist L) {
    // 条件:线性表L已存在
    // 结果:返回L中数据元素的个数
    return L.length
} // ListLength_sq

Status GetElem_sq(Sqlist L, int i, ElemType &e) {
    // 条件:线性表L已存在，1<= i <= ListLength(L)
    // 结果:用e返回L中第i个数据元素的值
    if (i < 1 || i > L.length+1) exit(ERROR);       // i值不合法
    e = L.elem[i - 1];      //将L中第i个数据元素的值赋给e
    return OK;
} // GetElem_sq

int LocateElem_sq(Sqlist L, ElemType e,
                  Status ( *compare)(ElemType, ElemType)) {
    // 条件:线性表L已存在,compare()是数据元素判定程序
    // 结果:返回L中第一个与e满足compare()的数据元素的位序，
    //      若这样的数据不存在，则返回值为0
    int i = 1;
    while ( (i <= L.length) && !( *compare(e, L.elem[i-1]) ) ++i;
    (i <= L.length) ? return i : return 0;
} // LocateElem_sq

Status PriorElem_sq(Sqlist L, ElemType cur_e, ElemType &pre_e) {
    // 条件:线性表L已存在
    // 结果:若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，
    //      否则操作失败，pre_e无定义
    int i;      // i表示L中数据元素的序号，从0开始
    ElemType *p = L.elem;   // p为L中数据元素的位置
    for(i = 0; i <= L.length-1; i++) {      // 检查在L中是否有与cur_e相等的数据
         if ( *p == cur_e) break;           // 元素
         ++p;
    }

    (0 < i < L.length) ? pre_e = *(--p) : exit(EROOR);

    return OK;
} // PriorElem_sq

Status NextElem_sq(Sqlist L, ElemType cur_e, ElemType &next_e) {
    // 条件:线性表L已存在
    // 结果:若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，
    // 否则操作失败，next_e无定义。
    int i;
    ElemType *p = L.elem;
    for (i = 0; i <= L.length-1; i++) {
        if ( *p == cur_e) break;
        ++p;
    }

    (i != L.length-1) ? next_e = *(++p) : exit(ERROR);

    return OK;
} // NextElem_sq

Status ListInsert_sq(Sqlist &L, int i, ElemType e) {
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
    q = &(L.elem[i - 1]);
    for (p = &(L.elem[L.length - 1]); p >= q; --p)
        *(p+1) = *p;
    *q = e;         // 插入e
    ++L.length;     // 表长加1
    return OK;
} // ListInsert_sq

Status ListDelete_sq(Sqlist &L, int i, ElemType &e) {
    // 初始条件:线性表L已存在，1<= i <= ListLength(L);
    // 操作结果:删除L的第i个数据元素，并用e返回其值，L长度减1;
    if (i < 1 || i > L.length) return ERROR;    // i值不合法

    ElemType *p, *q;
    q = &(L.elem[i - 1]);   // q为被删除元素位置
    e = *q;                 // 将被删除位置的值赋给e
    p = L.elem + L.length - 1;  // 表尾元素位置
    for (++q; q <= p; ++q)      //被删除元素之后的元素左移
        *(q-1) = *q;
    --L.length;                 // 表长减1
    return OK;
} // ListDelete_sq

