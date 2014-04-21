#ifndef _POLYN_H
# define _POLYN_H

# include <stdio.h>
# include "basic.h"
# include "linklist.h"

typedef struct {    // 项的表示,多项式的项作为LinkList的数据元素
    float coef;     // 系数
    int expn;       // 指数
} term, ElemType;   // 两个数据名:term用于本ADT,ElemType为LinkList的数据元素
                    // 对象名

typedef LinkList polynomial;    // 用带头结点的有序链表表示多项式

// ------------基本操作函数原型------------
void CreatPolyn(polynomial &P, int m);
    // 输入m项的系数和指数,建立一元多项式P
void DetroyPolyn(polynomial &P);
    // 一元多项式P已存在,销毁一元多项式P
void PrintPolyn(polynomial P);
    // 一元多项式已存在,打印输出一元多项式P
int PolynLength(polynomial P);
    // 一元多项式P已存在,返回一元多项式P中的项数
void AddPolyn(polynomial &Pa, polynomial &Pb);
    // Pa和Pb已存在,完成多项式的加运算,即:Pa=Pa+Pb,并销毁Pb
void SubsPolyn(polynomial &Pa, polynomial &Pb);
    // 完成多项式相减运算,即:Pa = Pa-Pb,并销毁一元多项式Pb
void MultiPolyn(polynomial &Pa, polynomial &Pb);
    // 完成多项式相乘运算,即Pa = Pa x Pb, 并销毁一元多项式Pb

#endif
