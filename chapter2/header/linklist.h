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


