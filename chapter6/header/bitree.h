#ifndef _BITREE_H
# define _BITREE_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"

// --------------二叉树的二叉链表存储表示---------------
typedef struct BiTNode {
    TElemType data;
    struct BiTNode     *lchild, *rchild;   // 左右孩子指针
} BiTNode, *BiTRee;

//---------------基本操作函数原型---------------------
void InitBiTree(BiTree &T);

void DetroyBiTree(BiTree &T);

Status CreateBiTree(BiTree &T);

Status BiTreeEmpty(BiTree T);

int BiTreeDepth(BiTree T);

TElemType Root(BiTree T);

TElemType Value(BiTree p);

void Assign(BiTree &p; TElemType value);

BiTree Parent(BiTree T, BiTree e);

BiTree LeftChild(BiTree T, BiTree e);

BiTree RightChild(BiTree T, BiTree e);

BiTree LeftSibling(BiTree T, BiTree e);

BiTree RightSibling(BiTree T, BiTree e);

Status InsertChild(BiTree T, BiTree p, int LR, BiTree c);

Status DeleteChild(BiTree T, BiTree p, int LR);

Status PreOrderTraverse(Bitree T, Status (*visit)(TElemType e));

Status InOrderTraverse(Bitree T, Status (*visit)(TElemType e));

Status PostOrderTraverse(Bitree T, Status (*visit)(TElemType e));

Status LevelOrderTraverse(Bitree T, Status (*visit)(TElemType e));
