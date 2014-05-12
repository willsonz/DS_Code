#ifndef _BITREE_H
# define _BITREE_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"

// --------------二叉树的二叉链表存储表示---------------
typedef struct BiTNode {
    TElemType data;
    struct BiTNode     *lchild, *rchild;   // 左右孩子指针
} BiTNode, *BiTree;

//---------------基本操作函数原型---------------------
void InitBiTree(BiTree &T);

void DestroyBiTree(BiTree &T);

Status CreateBiTree(BiTree &T);

Status BiTreeEmpty(BiTree T);

int BiTreeDepth(BiTree T);

TElemType Root(BiTree T);

TElemType Value(BiTree p);

void Assign(BiTree &p, TElemType value);

TElemType Parent(BiTree T, TElemType e);

BiTree Point(BiTree T, TElemType value);

TElemType LeftChild(BiTree T, TElemType e);

TElemType RightChild(BiTree T, TElemType e);

TElemType LeftSibling(BiTree T, TElemType e);

TElemType RightSibling(BiTree T, TElemType e);

Status InsertChild(BiTree T, BiTree p, int LR, BiTree c);

Status DeleteChild(BiTree T, BiTree p, int LR);

Status PreOrderTraverse(BiTree T, Status (*visitT)(TElemType e));

Status InOrderTraverse(BiTree T, Status (*visitT)(TElemType e));

Status PostOrderTraverse(BiTree T, Status (*visitT)(TElemType e));

Status LevelOrderTraverse(BiTree T, Status (*visitT)(TElemType e));

#endif
