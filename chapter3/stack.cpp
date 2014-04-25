
#include <stdio.h>
#include <stdlib.h>
#include "header/stack.h"


Status InitStack(SqStack &S)
{
    // 构造一个空栈S
    S.base = (SElemType *)malloc( STACK_INIT_SIZE * sizeof(ElemType) );

    if( !S.base )
        exit(OVERFLOW);     // 存储失败

    S.top = S.base;
    S.staksize = STACK_INIT_SIZE;

    return OK;
}

Status DestroyStack(SqStack &S)
{
    // 销毁栈S, S不再存在
    free(S.base);
    S.top = S.base = NULL;

    return OK;
}

Status ClearStack(SqStack &S)
{
    // 将S置为空栈
    S.top = S.base;

    return OK;
}

Status StackEmpty(SqStack S)
{
    // 若S为空栈,则返回TURE,否则返回FALSE
    return ( S.top == S.base ) ? TRUE : FALSE;
}

int StackLength(SqStack S)
{
    // 返回S的元素个数,即栈的长度
    return (S.top - S.base);
}

Status GetTop(SqStack S, SElemType &e)
{
    // 若栈不空,则用e返回栈顶元素,并返回OK,否则返回ERROR
    if( StackEmpty(S) )
        return ERROR;

    e  = *(S.top - 1);

    return OK;
}

Status Push(SqStack &S, SElemType &e)
{
    // 插入元素e为新的栈顶元素
    if( (S.top - S.base) >= S.stacksize ) {     // 栈满追加空间
        S.base = (ElemType *) realloc( S.base,
                            (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if( !S.base )
            exit(OVERFLOW);

        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }

    *S.top++ = e;

    return OK;
}

Status Pop(SqStack &S, SelemType &e)
{
    // 若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK,否则返回ERROR
    if( StackEmpty(S) )
        return ERROR;

    e = * --S.top;

    return OK;
}

Sataus StackTraverse(SqStack S, Status (*visit)())
{
    // 从栈底到栈顶依次对每个元素调用visit(),
    // 一旦visit()失败,则操作失败
    Link sp;

    sp = S.base;

    while( sp < S.top) {
        visit( sp++ );
    }

    return OK;
}
