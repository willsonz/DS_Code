#ifndef _HSTRING_H
# define _HSTRING_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"

// 字符串的堆分配存储表示
typedef struct {
    char *ch;   // 若是非空串,则按串长分配存储区,否则ch为NULL
    int length;
} HString;

// 基本操作函数原型
Status StrAssign(HString &T, char *chars);
int StrLength(HString S);
int StrCompare(HString S, HString T);
Status ClearStr(HString &S);
Status Concat(HString &T, HString S1, HString S2);
Status SubStr(HString &Sub, HString S, int pos, int len);
int Index(HString S, HString T, int pos);
#endif
