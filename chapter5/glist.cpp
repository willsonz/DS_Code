//----------广义表基本操作函数定义----------------
#include <stdio.h>
#include <stdlib.h>
#include "../chapter4/header/sstring.h"
#include "./header/glist.h"

void InitGList(GList &L)
{
    // 创建空的广义表L
    L = NULL;
}

Status CreateGlist(Glist &L, SString S)
{
    // S为广义表的书写形式串,由S创建广义表L
    SString sub, hsub, emp;
    GList p, q;

    // 基本项1
    StrAssign(emp, "()");
    if (!StrCompare(S, emp))
        L = NULL;
    else {
        if (!(L = (kGList)malloc(sizeof(GLNode))))
            exit(OVERFOLOW);

        // 基本项2
        if (StrLength(S) == 1) {
            L->tag = ATOM;
            L->atom = S;
        }
        else { // 归纳项
            L->tag = LIST;
            p = L;
            SubString(sub, S, 2, StrLength(S) - 2); // 脱外层括号

            do {
                server(sub, hsub);  // 从sub分离出表头串hsub
                CreateGlist(p->ptr.hp);
                q = p;

                if (!StrEmpty(sub)) {   // 表尾不空
                    if ( !(p = (GLNode *)malloc(sizeof(GLNode))) )
                        exit(OVERFLOW);
                    p->tag = LIST;
                    q->ptr.tp = p;
                }
            } while (!StrEmpty(sub));

            q->ptr.tp = NULL;
        }
    }

}

Status sever(SString &str, SString &hstr)
{
    // 将非空串str分割为两部分:hsub为第一个','之前的字串，str为之后的字串
    int i, k, n;
    char ch;

    n = StrLength(str);
    i = k = 0;  // k记尚未配对的左括号个数

    do {        // 搜索最外层的第一个括号
        ++i;
        SubString(ch, str, i, 1);

        if (ch == '(')
            ++k;
        else if (ch == ')')
            --k;
    }while (i < n && (ch != ',' || k != 0));

    if (i < n) {
        SubString(hstr, str, 1, i-1);
        SubString(str, str, i+1, n-i);
    }
    else {
        StrCopy(hstr, str);
        ClearString(str);
    }
}

Status DestroyGList(Glist &L)
{
    if(L) {
        if (L->tag == LIST) {   // 删除表结点
            DestroyGList(L->ptr.hp);
            DestroyGList(L->ptr.tp);
        }

        free(L);
        L = NULL;
    }

    return OK;
}

Status CopyGList(GList &T, GList L)
{
    // 采用头尾链表存储结构,由广义表L复制得到广义表T
    if (!L)
        T = NULL;   //复制空表
    else {
        if ( !(T = (GList *)malloc(sizeof(GLNode))) )
            exit(OVERFLOW);

        T->tag = L->tag;
        if (L->tag == ATOM)
            T->atom = L->atom;  // 复制单原子
        else {
            CopyGList(T->ptr.hp, L->ptr.hp);
            CopyGList(T->ptr.tp, L->ptr.tp);
        }
    }

    return OK;
}

int GListLength(GList L)
{
    // 返回广义表L的长度
    int len;
    GList p;

    if (!L)
        len = 0;

    p = L->ptr.tp;
    len = 1;
    while (p) {
        ++len;
        p = p->ptr.tp;
    }

    return len;
}

int GListDepth(GList L)
{
    // 采用头尾链表存储结构,求广义表L的深度

    // 基本项
    if (!L)
        return 1;       // 空表深度为1
    if (L->tag == ATOM)
        return 0;       // 原子深度为0

    int dep, max;
    GList pp;

    for (max=0, pp=L; pp; pp=pp->ptr.tp) {
        dep = GListDepth(pp->ptr.hp);   // 求pp->ptr.hp为头指针的子表深度

        if (dep > max)
            max = dep;
    }

    return max + 1;
}

Status GListEmpty(GList L)
{
    return (L) ? FALSE : TRUE;
}

GList GetHead(GList L)
{
    // 返回广义表L的头部
    if (!L)
        exit(ERROR);

    return L->ptr.hp;
}

GList GetTail(GList L)
{
    // 返回广义表L的尾
    if (!L || !(L->ptr.tp))
        exit(ERROR);

    return L->ptr.tp;
}

Status InsertFirst_GL(GList &L, GList e)
{
    // 插入广义表e为广义表L的第一元素
    GList p;

    if (GListEmpty(L)) {
        if (!(L = (GList *)malloc(sizeof(GLNode))))
            exit(OVERFLOW);

        L->tag = LIST;
        L->ptr.hp = e;
        L->ptr.tp = NULL;
    }
    else {
        if (!(p = (GList *)malloc(sizeof(GLNode))))
            exit(OVERFLOW);
        p->ptr.hp = L->ptr.hp;
        p->ptr.tp = L->ptr.tp;
        L->ptr.tp = p;
        L->ptr.hp = e;
    }

    return OK;
}

Status DeleteFirst_GL(GList &L, GList &e)
{
    // 删除广义表L的第一元素,并用e返回
    if (GListEmpty(L))
        exit(ERROR);

    e = L->ptr.hp;
    free(L->ptr.hp);

    L = L->ptr.tp;

    return OK;
}
