// 堆存储字符串结构的基本操作函数
#include <stdio.h>
#include <stdlib.h>
#include "hstring.h"

Status StrAssign(HString &T, char *chars)
{
    // 生成一个值等于串常量chars的串T
    if (T.ch)
        free(T.ch);     // 释放T原有空间

    int i, j;
    char *c;

    for (i = 0, c = chars; c; ++i, ++c);    // 计算chars长度

    if (!i) {
        T.ch = NULL;
        T.length = 0;
    }
    else {
        if (!(T.ch = (char *)malloc(i * sizeof(char))))
            exit(OVERFLOW);

        for (j = 0; j < i; j++) {
            T.ch[j] = chars[j];
        }

        T.length = i;
    }

    return OK;
}

int StrLength(HString S)
{
    return S.length;
}

int StrCompare(HString S, HString T)
{
    // 若S > T,则返回值 > 0; 若S = T,则返回值=0;若S < T,则返回值<0
    int i;

    for (i = 0; i < S.length && i < T.length; ++i)
        if (S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];

    return S.length - T.length;
}

Status ClearStr(HString &S)
{
    // 清为空串
    if (S.ch) {
        free(S.ch);
        S.ch = NULL;
    }

    S.length = 0;

    return OK;
}

Status Concat(HString &T, HString S1, HString S2)
{
    // 合并S1和S2到 T中
    if (T.ch)
        free(T.ch);

    if (!(T.ch = (char *)malloc( (S1.length + S2.length) * sizeof(char) )))
        exit(OVERFLOW);

    int i;

    for (i = 0; i < S1.length; i++)
        T.ch[i] = S1.ch[i];

    T.length = S1.length + S2.length;

    for (i = S1.length; i < T.length; i++)
        T.ch[i] = S2.ch[i-S1.length];

    return OK;
}

Status SubStr(HString &Sub, HString S, int pos, int len)
{
    // 用Sub返回串S的第pos个字符起长度为len的子串
    //
    if (pos < 1 || pos > S.length || len < 0 || len > S.length - pos + 1)
        return ERROR;

    if (Sub.ch)
        free(Sub.ch);

    if (!len) {
        Sub.ch = NULL;
        Sub.length = 0;
    }
    else {
        if (!(Sub.ch = (char *)malloc(len*sizeof(char))))
            exit(OVERFLOW);

        int i;
        for (i = 0; i < len; i++)
            Sub.ch[i] = S.ch[pos+i-1];

        Sub.length = len;
    }

    return OK;
}

int Index(HString S, HString T, int pos)
{
    // 返回子串T在主串S中第pos个字符之后的位置,若不存在,则函数值为0
    // 条件: T非空,1《pos《S.length
    int i, j;

    i = pos;
    j = 1;

    while (i <= S.length && j <= T.length) {
        if (S.ch[i-1] == T.ch[j-1]) {
            ++i;
            ++j;        // 继续比较后续字符
        }
        else {
            i = i - j + 2;      // 指针后退重新开始匹配
            j = 1;
        }
    }

    if (j > T.length)
        return (i - T.length);
    else
        return 0;
}

/*
int Index_KMP(HString S, HString T, int pos)
{
    // 利用模式串T的next函数求T在主串S中第pos个字符之后的位置的KMP算法
    int i, j;

    i = pos;
    j = 1;

    while (i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i-1] == T.ch[j-1]) {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }

    if (j > T.length)
        return i-T.length;
    else
        return 0;
}

void get_next(HString T, int next[])
{
    int i, j;

    i = 1;
    next[1] = 0;
    j = 0;

    while (j < T.length) {
        if (j == 0 || T.ch[i-1] == T.ch[j-1]) {
            ++i;
            ++j;

            next[i] = j;
        }
        else
            next[j] = j;
    }
}
*/

