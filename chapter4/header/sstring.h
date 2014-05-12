// 串的定长顺序结构
#ifndef _SSTRING_H
# define _SSTRING_H

# include <stdio.h>
# include <stdlib.h>
# include "basic.h"

//----------存储表示---------------
#define MAXSTRLEN 255;      // 用户可在255内定义最大串长
typedef unsigned char   SString[MAXSTRLEN + 1]; // 0号单元存放长度


