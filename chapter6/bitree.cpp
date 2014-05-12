#include <stdio.h>
#include <stdlib.h>

typedef char TElemType;
TElemType Nil=' ';
#include "./header/bitree.h"

//----------------基本操作函数定义--------------------
//
void InitBiTree(BiTree &T)
{
    // 构造空二叉树
    T = NULL;
}// InitBiTree

void DetroyBiTree(BiTree &T)
{
    // 二叉树T存在，销毁T
    if (T) {
        if (T->lchild)
            DestroyBiTree(T->lchild);       // 销毁左孩子树
        if (T->rchild)
            DestroyBiTree(T->rchild);       // 销毁右孩子树

        free(T);    // 释放根结点
        T = NULL;
    }
} //DestroyBiTree

Status CreateBiTree(BiTree &T)
{
    // 按先序次序输入二叉树结点的值(一个字符)，空格表示空树
    // 构造二叉链表表示的二叉树T
    char ch;

    scanf(&ch);
    if (ch == ' ')
        T = NULL;
    else {
        if ( !(T = (BiTree)malloc(sizeof(BiTNode))) )
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
        return Nil;
    else
        return T->data;

}

TElemType Value(BiTree p)
{
    // 二叉树T存在，p指向T中某个结点，返回p所指结点的值
    return p->data;
}

void Assign(BiTree &p, TElemType e)
{
    // 二叉树T存在，p指向T中某一结点，给p所指结点赋值value
    p->data = e;
}

//-------------------------
// 调用队列结构存储树的结点
typedef BiTree QElemType;
#include "../chapter3/header/queue.h"
//----------------------------

TElemType Parent(BiTree T, TElemType e)
{
    // 二叉树T存在，e为T中某结点，
    // 若e为T非根结点，则返回其parent，否则返回NULL
	LinkQueue Q;
	QElemType a;

	if (T) {
		InitQueue(Q);
		EnQueue(Q, T);      // 树根指针入队列

		while (!QueueEmpty(Q)) {
			DeQueue(Q, a);  // 出队，队列元素赋给a
			if ((a->lchild)&&(a->lchild->data==e) ||
                    (a->rchild)&&(a->rchild->data==e))
                // find e is a' lchild or rchild
				return a->data;     // 返回双亲
			else {      // 未找到e，则入队其孩子
				if (a->lchild)
					EnQueue(Q, a->lchild);
				if (a->rchild)
					EnQueue(Q, a->rchild);
			}
		}
	}

	return Nil;   // 树空或无值为e的结点, Nil在main中定义
}

BiTree Point(BiTree T, TElemType e)
{
    // 在T寻找值为e的结点，若存在返回其指针，否则返回NULL
	LinkQueue Q;
	QElemType a;

	if (T) {
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
    // e为T中某结点，返回e的左孩子，若无左孩子则返回空
	BiTree a;

	a = Point(T, e);
	if (a && a->lchild)
		return a->lchild->data;
	else
		return Nil;
}

TElemType RightChild(BiTree T, TElemType e)
{
    // 返回e的右孩子，若e无右孩子则返回空
	BiTree a;

	a = Point(T, e);
	if (a && a->rchild)
		return a->rchild->data;
	else
		return Nil;
}

TElemType LeftSibling(BiTree T, TElemType e)
{
    // 返回e的左兄弟，若无左兄弟则返回空
	BiTree a;
	TElemType b, c;

	if ((b = Parent(T, e)) != Nil) {    // 寻找e的、结点的parent赋给b
		if ((c = LeftChild(T, b)) != e)
            return c;         // 寻找b结点的左子树，即e的左兄弟
        else
            return Nil;
    }
	else
		return Nil;
}

TElemType RightSibling(BiTree T, TElemType e)
{
    // 返回e的右兄弟，若无右兄弟则返回空
	BiTree a;
	TElemType b, c;

	if ((b = Parent(T, e)) != Nil) {    // 寻找e的、结点的parent赋给b
		if ((c = RightChild(T, b)) != e)
            return c;         // 寻找b结点的右子树，即e的右兄弟
        else
            return Nil;
    }
	else
		return Nil;
}

Status InsertChild(BiTree p, int LR, BiTree c)
{
    // 初始条件:二叉树T存在,p指向T中某结点，LR为0或1,非空二叉树c与T不相交
    // 且右子树为空
    // 结果:LR=0则插入c为T中p所指结点的左子树，LR=1则插入为右子树;原有
    // 左或右子树则成为c的右子树
	if (!c || !p)   // c，p为空则错误
		return ERROR;

    // 求c的终端结点
	BiTree c_end;
	c_end = c;
	while (!c_end)
		c_end = c_end->lchild;

    // 根据LR的值进行插入操作
	switch (LR) {
	case 0:
		c_end->rchild = p->lchild;  // 原p的左子树成为c的右子树
		p->lchild = c;              // 插入c为p的左子树
		return OK;
	case 1:
		c_end->rchild = p->rchild;  // 原p的右子树成为c的右子树
		p->rchild = c;              // 插入p为p的右子树
		return OK;
	default:
		return ERROR;               // LR数值出错
	}
}

Status DeleteChild(BiTree p, int LR)
{
    // 依据LR的值删除p的孩子
	if (!p)
		return ERROR;

	switch (LR) {
	case 0:
		DestroyBiTree(p->lchild);
		return OK;
	case 1:
		DestroyBiTree(p->rchild);
		return OK;
	default:
		return ERROR;
	}
}

// 遍历二叉树算法
Status PreOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    // 采用二叉树链表存储结构
    // 先序遍历二叉树T的递归算法，对每个数据元素调用函数visit
    if (T) {
        if ( visit(T->data) )     // 访问根结点
            if ( PreOrderTraverse(T->lchild, visit) )   // 先序遍历左子树
                if ( PreOrderTraverse(T->rchild, visit) )  // 右子树
                    return OK;

        return ERROR;
    }
    else
        return OK;
}

Status InOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    // 采用二叉树链表存储结构
    // 中序遍历二叉树T的递归算法，对每个数据调用函数visit
    if (!T)
        return OK;

    if ( InOrderTraverse(T->lchild, visit) ) {   // 中序遍历左子树
        if ( visit(T->data) )                     // 访问根结点
            if ( InOrderTraverse(T->rchild, visit) )  // 中序遍历右子树
                return OK;

        return ERROR;
    }
}

Status PostOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    // 采用二叉树链表存储结构
    // 后序遍历二叉树T的递归算法，对每个数据调用函数visit
    if (!T)
        return OK;

    if ( PostOrderTraverse(T->lchild, visit) ) {   // 后序遍历左子树
        if ( PostOrderTraverse(T->rchild, visit) )  // 后序遍历右子树
            if ( visit(T->data) )                     // 访问根结点
                return OK;

        return ERROR;
    }
}

Status LevelOrderTraverse(BiTree T, Status (*visit)(TElemType e))
{
    // 空
}

void visit(TElemType e)
{
    printf("%c ", e);
}
