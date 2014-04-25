/******************************** * 栈的应用举例 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include "header/stack.h"

// 算法3.1 - 数制转换
void dec2oct()
{
    // 对于输入的任一个非负十进制整数,打印出与其等值的八进制数
    SqStack L;
    SElemType n, e;

    InitStack(L);   // 构造空栈
    scanf( " %d", &n);

    while( n ) {
        Push( S, n % 8);
        n = n / 8;
    }

    while( !StackEmpty(S) ) {
        Pop( S, e);
        printf( "%d", e );
    }
}

// 算法3.2.2 - 括号匹配的检验
void BracketMatch()
{
    // 只允许包含圆括号和方括号,利用栈结构来进行括号匹配
    SqStack L;
    SElemType bracket, e;

    InitStack(L);   // 构造空栈

    bracket = getchar();
    if (bracket==')' || bracket==']')
        exit(ERROR);    // 首次输入不为右括号

    while(1) {
        switch( bracket ) {
        case '(':
        case '[':
            Push(L, bracket);
            break;
        case ')':
            GetTop(L, e);
            if( e == ')' )
                Pop(L, e);
            else
                printf("The bracket is invali!\n");

            break;
        case ']':
            GetTop(L, e);
            if( e == ']' )
                Pop(L, e);
            else
                printf("The bracket is invali!\n");

            break;
        default:
            printf("This is not a bracket!\n");
            exit(ERROR);
        }

        bracket = getchar;

        if( StackEmpty)    // 若为空栈，则匹配完成
            break;
    }
}

void LineEdit()
{
    // 利用字符栈S,从终端接收一行并传送至调用过程的数据区
    SqStack S;
    SElemType ch, c;

    InitStack(S);
    ch = getchar();

    while (ch != EOF) {
        while (ch != EOF || ch != '\n') {
            switch (ch) {
            case '#':
                Pop(S, c);
                break;
            case '@':
                ClearStack(S);
                break;
            default:
                Push(S, ch);
                break;
            }

            ch = getchar();
        }
        // 传送过程,代码省略

        ClearStack(S);
        if (ch != EOF)
            ch = getchar();
    }
    DeatroyStack(S);
}


