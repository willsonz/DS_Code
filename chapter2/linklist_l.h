#ifndef _LINKLIST_L_H
# define _LINKLIST_L_H

# include <stdio.h>
# include "basic.h"

typedef int ElemType;   // 数据元素类型

typedef struct LNode {  // 结点类型
    ElemType data;
    struct LNode *next;
} LNode, *LinkList_l;

//-------------- 基本操作函数原型-----------------
Status InitList_L(LinkList_l &L);
Status DestroyList_L(LinkList_l &L);
Status ClearList_L(LinkList_l &L);
bool ListEmpty_L(LinkList_l L);
int ListLength_L(LinkList_l L);
Status GetElem_L(LinkList_l L, int i, ElemType &e);
Status PriorLink_L(LinkList_l L, int i, LNode * &p);
Status NextLink_L(LinkList_l L, int i, LNode * &p);
Status ListInsert_L(LinkList_l L, int i, ElemType e);
Status ListDelete_L(LinkList_l L, int i, ElemType &e);
Status ListTraverse_L(LinkList_l L, Status (*visit_L)(ElemType));
Status visit_L(ElemType e);
void MergeList_L(LinkList_l &La, LinkList_l &Lb, LinkList_l &Lc);

#endif
