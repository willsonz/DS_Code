#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

//----- 模式匹配算法---------
int Index(SString S, SString T, int pos)
{
    int i, j;

    i = pos;
    j = 1;

    while (i <= S[0] && j <= T[0]) {
        if (S[i] == T[j]) {
            ++i;
            ++j;
        }
        else {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > T[0])
        return i - T[0];
    else
        return 0;
}

int Index_KMP(SString S, SString T, int pos)
{
    int i, j;

    i = pos;
    j = 1;

    while (i <= S[0] && j <= T[0]) {
        if (j == 0 || S[i] == T[j]) {
            ++i;
            ++j;
        }
        else{
            j = next[j];
        }
    }

    if (j > T[0])
        return i-T[0];
    else
        return 0;
}

void get_next(SString T, int next[])
{
    // 求模式串T的next函数值并存入数组next
    int i, j;

    i = 1;
    next[1] = 0;
    j = 0;

    while (i < T[0]) {
        if (j == 0 || T[i] == T[j]) {
            ++i;
            ++j;

            next[i] = j;
        }
        else
            j = next[j];
    }
}
