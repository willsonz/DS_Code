//-----------广义表结构头文件-------------
#ifndef _GLIST_H
# define _GLIST_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"

//广义表扩展线性链表存储表示
typedef enum {ATOM, LIST} ElemType; //ATOM=0为原子，LIST=1为子表

typedef struct GLNode {
    ElemTag tag;        // 公共部分,用于区分原子结点和表结点
    union {
        AtomType atom;  // atom是原子值域,AtomType由用户定义
        struct GLNode *hp;  // 表结点的表头指针
    };
    struct GLNode *tp;      // 相当于线性链表的next,指向下一个元素结点
} *GList;


// 基本操作函数原型

int InitGList(GList &L);

Status CreateGlist(Glist &L, GList S);

Status DestroyGList(Glist &L);

Status CopyGList(GList &T, GList L);

int GListLength(GList L);

int GListDepth(GList L);

Status GListEmpty(GList L);

GList GetHead(GList L);

GList GetTail(GList L);

Status InsertFirst_GL(GList &L, GList e);

Status DeleteFirst_GL(GList &L, GList &e);

