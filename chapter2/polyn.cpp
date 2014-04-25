// 一元多项式的链表结构实现
//

#include <stdio.h>
#include <stdlib.h>
#include "polyn.h"

// -------基本操作函数定义说明--------
int cmp(term a, term b)
{
    // 依a的指数值<(或=)(或>)b的指数值,分别返回-1,0和+1
    if(a.expn < b.expn)
        return -1;
    else if(a.expn > b.expn)
        return 1;
    else
        return 0;
} // cmp

Status LocateElem_p(polynomial L, term e, Position &q,
                    int (*cmp)(term, term))
{
    // 若有序链表L中存在与e满足判定函数com()取值为0的元素,则q指示L中第一个
    // 值为e的结点的位置,并返回TRUE;否则q指示第一个与e满足cmp()取值>0的元素
    // 的前驱的位置,并返回FALSE
    Link p = L.head;
    int i;

    for (i = 1; i < L.len; i++) {
        value = cmp(e, p->next->data);

        if (!value) {
            q = p->next;
            return TRUE;
        }
        else if (value > 0) {
            q = p;
            return FALSE;
        }
        else
            p = p->next;
    }

}
void CreatePolyn(polynomial &P, int m)
{
    // 输入m项的系数和指数,建立表示一元多项式的有序链表P
    Link h, q, s;
    term e;

    InitList(P);
    h = Gethead(P);     // h指向头结点
    e.coef = 0.0;
    e.expn = 0.0;
    SetCurElem(h, e);   // 设置头结点的数据元素

    for (i = 1; i <= m; i++) {      // 依次输入m个非零量
        scanf(" %f/%f\n", e.coef, e.expn);
        if (!LocateElem(P, e, q, (*cmp)()) {    // 当前链表中不存在该指数项
            if (MakeNode(s, e)) InFirst(q, s);  // 生成结点并插入链表
        }
    }
} // CreatePolyn

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
