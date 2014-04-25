// main.cpp - 主程序，主要为测试代码
//
#include <stdio.h>
#include "basic.h"

#include "sqlist.h"

int main(void)
{
    // 有关变量声明
    Sqlist L;       // 建立顺序表类型L，用于后期测试
    ElemType e;     // 建立L数据元素类型变量e
    ElemType cur_e, pre_e, next_e;      // 当前元素，前驱， 后继

    // 逐个进行边界测试
    return InitList_sq(L);
}
