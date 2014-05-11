#include "bitree.h"

//----------------基本操作函数定义--------------------
//
void InitBiTree(BiTree &T)
{
    // 构造空二叉树
    T = NULL;
}

void DetroyBiTree(BiTree &T)
{
    // 二叉树T存在，销毁T
    if (T) {
        if (T->lchaild)
            DestroyBiTree(T->lchild);       // 销毁左孩子树
        if (T->rchild)
            DestroyBiTree(T->rchild);       // 销毁右孩子树

        free(T);    // 释放根结点
        T = NULL;
    }
}

Status CreateBiTree(BiTree &T)
{
    // 按先序次序输入二叉树结点的值(一个字符)，空格表示空树
    // 构造二叉链表表示的二叉树T
    char ch;

    scanf(&ch);
    if (ch == ' ')
        T = NULL;
    else {
        if ( !(T = (BiTree *)malloc(sizeof(BiTNode))) )
            exit(OVERFLOW);
        T->data = ch;       // 生成根结点
        CreateBiTree(T->lchild);    // 构造左子树
        CreateBiTree(T->rchild);    // 构造右子树
    }
    return OK;
}

Status BiTreeEmpty(BiTree T)
{
    // 若二叉树T为空二叉树，返回TRUE，否则返回FALSE
    return (T) ? FALSE : TRUE;
}

int BiTreeDepth(BiTree T)
{
    // 二叉树T存在，返回T的深度
    int i, j;

    if (!T)
        return 0;   // 空树深度为0
    if (T->lchild)
        i = BiTreeDepth(T->lchild);     // i为左子树深度
    else
        i = 0;
    if (T->rchild)
        j = BiTreeDepth(T->rchild);     // j为右子树深度
    else
        j = 0;

    return (i > j) ? i+1 : j+1;         // T的深度为左右子树深度最大者+1
}

TElemType Root(BiTree T)
{
    // 返回T的根
    if (BiTreeEmpty(T))
        return NULL;
    else
        rerurn T->data;

}

TElemType Value(BiTree p)
{
    // 二叉树T存在，p指向T中某个结点，返回p所指结点的值
    return p->data;
}

void Assign(BiTree &p, TElemType value)
{
    // 二叉树T存在，p指向T中某一结点，给p所指结点赋值value
    p->data = e;
}

//
//
typedef QElemType BiTree;
include "../chapter4/queue.h"
//

TElemType Parent(BiTree T, TElemType e)
{
	LinkQueue Q;
	QElemType a;

	if (!T) {
		InitQueue(Q);
		EnQueue(Q, T);

		while (!QueueEmpty(Q)) {
			DeQueue(Q, a);
			if ((a->lchild)&&(a->lchild->data==e) || (a->rchild)&&(a->rchild->data==e))
				return a->data;
			else {
				if (a->lchild)
					EnQueue(Q, a->lchild);
				if (a->rchild)
					EnQueue(Q, a->rchild);
			}
		}
	}

	return ERROR;
}

BiTree Point(BiTree T, TElemType e)
{
	LinkQueue Q;
	QElemType a;

	if (!T) {
		InitQueue(Q);
		EnQueue(Q, T);
		
		while (!QueueEmpty(Q)) {
			DeQueue(Q, a);
			if (a->data == e)
				return a;
			else {
				if (a->lchild)
					EnQueue(Q, a->lchild);
				if (a->rchild)
					EnQueue(Q, a->rchild);
			}
		}
	}

	return NULL;
}

TElemType LeftChild(BiTree T, TElemType e)
{
	BiTree a;

	a = Point(T, e);
	if (a && a->lchild)
		return a->lchild->data;
	else
		return ERROR;
}
	
TElemType RightChild(BiTree T, TElemType e)
{
	BiTree a;

	a = Point(T, e);
	if (a && a->rchild)
		return a->rchild->data;
	else
		return ERROR;
}

TElemType LeftSibling(BiTree T, TElemType e)
{
	BiTree a;
	TElemType b;

	if ((b = Parent(T, e)) != ERROR)
		return LeftChild(T, b);
	else
		return ERROR;
}	

TElemType RightSibling(BiTree T, TElemType e)
{
	BiTree a;
	TElemType b;

	if ((b = Parent(T, e)) != ERROR)
		return RightChild(T, b);
	else
		return ERROR;
}	

Status InsertChild(BiTree p, int LR, BiTree c)
{
	if (!c || !p)
		return ERROR;

	BiTree c_end;
	c_end = c;
	while (!c_end)
		c_end = c_end->lchild;

	switch (LR) {
	case 0:
		c_end->lchild = p->lchild;
		p->lchild = c;
		return OK;
	case 1:
		c_end->lchild = p->rchild;
		p->rchild = c;
		return OK;
	default:
		return ERROR;
	}
}

Status DeleteChild(BiTree p, int LR)
{
	if (!p)
		return ERROR;

	switch (LR) {
	case 0:
		Destroy(p->lchild);
		p->lchild = NULL;
		return OK;
	case 1:
		Destroy(p->rchild);
		p->rchild = NULL;
		return OK;
	default:
		return ERROR;
	}
}

// 遍历二叉树算法
Status PreOrderTraverse(Bitree T, Status (*visit)(TElemType e))
{
    // 采用二叉树链表存储结构
    // 先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
    if (T) {
        if ( Visit(T->data) )     // 访问根结点
            if ( PreOrderTraverse(T->lchild, Visit) )   // 先序遍历左子树
                if ( PreOrderTraverse(T->rchilde, Visit) )  // 右子树
                    return OK;

        return ERROR;
    }
    else
        return OK;
}

Status InOrderTraverse(Bitree T, Status (*visit)(TElemType e))
{
    // 采用二叉树链表存储结构
    // 中序遍历二叉树T的递归算法，对每个数据调用函数Visit
    if (!T)
        return OK;

    if ( InOrderTraverse(T->lchild, Visit) ) {   // 中序遍历左子树
        if ( Visit(T->data) )                     // 访问根结点
            if ( InOrderTraverse(T->rchild, Visit) )  // 中序遍历右子树
                return OK;

        return ERROR;
    }
}

Status PostOrderTraverse(Bitree T, Status (*visit)(TElemType e))
{
    // 采用二叉树链表存储结构
    // 后序遍历二叉树T的递归算法，对每个数据调用函数Visit
    if (!T)
        return OK;

    if ( PostOrderTraverse(T->lchild, Visit) ) {   // 后序遍历左子树
        if ( PostOrderTraverse(T->rchild, Visit) )  // 后序遍历右子树
            if ( Visit(T->data) )                     // 访问根结点
                return OK;

        return ERROR;
    }
}

Status LevelOrderTraverse(Bitree T, Status (*visit)(TElemType e));

