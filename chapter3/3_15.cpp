// 习题3.15
// -----------双向栈顺序结构---------------

#include ".header/queue.h"

// ------函数说明---------

typedef struct {
    SqStack stack1;
    SqStack stack2;
} tws;

Status initstack(tws &S)
{
    SElemType a[STACK_INIT_SIZE];

    S.stack1.top = S.stack1.base = a;
    S.stack2.top = S.stack2.base = &a[STACK_INIT_SIZE-1];

    S.stack1.stacksize = S.stack2.stacksize = 0;

    return OK;
}

Status twsPush(tws &S, int i, SElemType x)
{
    switch (i) {
    case 0:
        *S.stack1.top++ = x;
        S.stack1.stacksize += 1;
        break;
    case 1:
        *S.stack2.top-- = x;
        S.stack2.stacksize += 1;
        break;
    default:
        break;

    }

    return OK;
}

Status twsPop(tws &S, int i)
{
    switch (i) {
    case 0:
        S.stack1.top--;
        break;
    case 1:
        S.stack2.top++;
        break;
    default:
        break;
    }

    return OK;
}

