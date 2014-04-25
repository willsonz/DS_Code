#include "../header/stack.h"

// 习题3.17
Status bracket1(SqStack &S)
{
    InitStack(S);
    ElemType ch, c;

    if ((ch = getchar()) == '@')
        return ERROR;

    while ( (ch != '@' ) {
        if (ch != '&') {
            Push(S, ch);
        }
        else {
            do {
                ch = getchar();

                if (ch == *(S.top-1))
                    Pop(S, c);
                else
                    return ERROR;
            } while (!StackEmpty(S));
        }

        ch = getchar();
    }

    return (StackEmpty(S)) ? TURE : FALSE;
}
